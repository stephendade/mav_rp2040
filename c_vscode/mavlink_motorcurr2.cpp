#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/adc.h"

#include "mavlink/minimal/mavlink.h"
#include "mavlink/common/common.h"


#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)

// UART defines
// By default the stdout UART is `uart0`, so we will use the second one
#define UART_ID uart1
#define BAUD_RATE 115200

// Use pins 4 and 5 for UART1
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define UART_TX_PIN 4
#define UART_RX_PIN 5

static uint8_t autopilotSysID = 0;

// 12-bit conversion, assume max value == ADC_VREF == 3.3 V
static float conversion_factor = 3.3f / (1 << 12);

// RX interrupt handler
void on_uart_rx() {
    while (uart_is_readable(UART_ID)) {
        // Read a single byte from UART
        uint8_t byte = uart_getc(UART_ID);

        // Something received - print out all bytes and parse packet
        mavlink_message_t msg;
        mavlink_status_t status;
        if (mavlink_parse_char(MAVLINK_COMM_0, byte, &msg, &status))
        {
            // Packet received
            printf("Received packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n", msg.sysid, msg.compid, msg.len, msg.msgid);
            // if Heartbeat from componentID1, assume autopilot:
            if(msg.msgid == 0 && msg.compid == 1 && autopilotSysID == 0) {
                autopilotSysID = msg.sysid;
            }
            else if (msg.msgid == 0 && msg.compid == 1 && autopilotSysID == msg.sysid) {
                //toggle LED on each HB packet recieved from autopilot
                //gpio_put(PICO_DEFAULT_LED_PIN, !gpio_get_out_level (PICO_DEFAULT_LED_PIN));
            }
        }
    }
}

int main()
{
    stdio_init_all();

    // MAVLink message reading/writing variables
    mavlink_message_t msg;
    uint16_t len;
    uint8_t buf[BUFFER_LENGTH];

    // Set up ADC
    adc_init();

    // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(26);
    adc_gpio_init(27);
    adc_gpio_init(28);
    adc_gpio_init(29);

    // Labels mapping ADC channels to string names
    const char *adclabels[4];
    adclabels[0] = "FRONTRIGHT"; //front right
    adclabels[1] = "BACKRIGHT"; //front left
    adclabels[2] = "BACKLEFT"; //back right
    adclabels[3] = "FRONTLEFT"; //back left

    // Set up our UART
    uart_init(UART_ID, BAUD_RATE);
    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    
    // Set up a RX interrupt
    // We need to set up the handler first
    // Select correct interrupt for the UART we are using
    int UART_IRQ = UART_ID == uart0 ? UART0_IRQ : UART1_IRQ;

    // And set up and enable the interrupt handlers
    irq_set_exclusive_handler(UART_IRQ, on_uart_rx);
    irq_set_enabled(UART_IRQ, true);

    // Now enable the UART to send interrupts - RX only
    uart_set_irq_enables(UART_ID, true, false);
    
    // Send out a string, with CR/LF conversions
    //uart_puts(UART_ID, " Hello, UART!\n");
    printf("System is set up\n");
    
    // For more examples of UART use see https://github.com/raspberrypi/pico-examples/tree/master/uart

    while (true) {
        //Send heartbeat
        mavlink_msg_heartbeat_pack(autopilotSysID, MAV_COMP_ID_PERIPHERAL, &msg, MAV_TYPE_ONBOARD_CONTROLLER, MAV_AUTOPILOT_INVALID, MAV_MODE_FLAG_SAFETY_ARMED, 0, MAV_STATE_ACTIVE);
		len = mavlink_msg_to_send_buffer(buf, &msg);
        uart_write_blocking(UART_ID, buf, len);

        sleep_ms(200);
        autopilotSysID = 1;

        // read all the ADC's and send as named-value-floats
        printf("Reading ADC values\n");
        for (int i = 0; i < 4; i++) {
            // read each ADC channel 10 time and average the result
            uint16_t result = 0;
            for (int j = 0; j < 10; j++) {
                adc_select_input(i);
                // Read the ADC value
                result += adc_read();
                sleep_ms(10);
            }
            // Average the result
            result /= 10;

            float result_v = result * conversion_factor;
            // Conversion to amps for Pololu DRV8874 sensor that we're using
            float curr = result_v / 1.1f;

            printf("Raw value %s: 0x%03x, voltage: %.3f V, current: %.1f A\n", adclabels[i], result, result_v, curr);

            //send named-value-float
            if (autopilotSysID != 0)
            {
                mavlink_msg_named_value_float_pack(autopilotSysID, MAV_COMP_ID_PERIPHERAL, &msg, to_ms_since_boot(get_absolute_time()), adclabels[i], curr);
                len = mavlink_msg_to_send_buffer(buf, &msg);
                uart_write_blocking(UART_ID, buf, len);
            }
            sleep_ms(100); 
        }
    }
}
