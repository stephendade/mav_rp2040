/**
 * Simple example of sending and recieving MAVLink on the RP2040 microcontroller.
 * Requires the UART (GPIO0/1) to be connected to a TELEM port on a flight controller
 * 
 * In this example, the RP2040 will first wait for a heartbeat from the flight controller.
 * Once a valid heartbeat is detected, the RP2040 will start to send heartbeats and
 * named-value-float messages via MAVLink at a rate of once per second.
 * 
 * The named-value-float messages a readings of the 4x ADC channels
 *
 * Written by Stephen Dade (stephen_dade@hotmail.com)
 * 
 * Licensed under GPLV3
 * 
 * cmake .. -DPICO_BOARD=pico -DPICO_TOOLCHAIN_PATH=/usr/bin/
 * make
 * cp ./mavlink_periph.uf2 /media/stephen/RPI-RP2
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#include "mavlink/minimal/mavlink.h"
#include "mavlink/common/common.h"

#define FLAG_VALUE 123
#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)

#define UART_ID uart0
#define BAUD_RATE 57600

// We are using pins 0 and 1, but see the GPIO function select table in the
// datasheet for information on which other pins can be used.
#define UART_TX_PIN 0
#define UART_RX_PIN 1

static uint8_t autopilotSysID = 0;

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
                gpio_put(PICO_DEFAULT_LED_PIN, !gpio_get_out_level (PICO_DEFAULT_LED_PIN));
            }
        }
    }
}

int main()
{
    stdio_init_all();

    //init ADC
    adc_init();
    adc_gpio_init(26);
    adc_gpio_init(27);
    adc_gpio_init(28);
    adc_gpio_init(29);

    //init UART
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    uart_set_translate_crlf(UART_ID, false);
    uart_set_fifo_enabled(UART_ID, false);

    //init LED
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    // 12-bit conversion for adc, assume max value == ADC_VREF == 3.3 V
    const float conversion_factor = 3.3f / (1 << 12);

    // MAVLink message reading/writing variables
    mavlink_message_t msg;
    uint16_t len;
    uint8_t buf[BUFFER_LENGTH];

    // Labels mapping ADC channels to string names
    // Note the labels must be ALL CAPS
    const char *adclabels[4];
    adclabels[0] = "ADC0";
    adclabels[1] = "ADC1";
    adclabels[2] = "ADC2";
    adclabels[3] = "ADC3";

    // Set up a RX interrupt
    // We need to set up the handler first
    // Select correct interrupt for the UART we are using
    int UART_IRQ = UART_ID == uart0 ? UART0_IRQ : UART1_IRQ;

    // And set up and enable the interrupt handlers
    irq_set_exclusive_handler(UART_IRQ, on_uart_rx);
    irq_set_enabled(UART_IRQ, true);

    // Now enable the UART to send interrupts - RX only
    uart_set_irq_enables(UART_ID, true, false);

    // Now enter the main loop - sending heatbeat and ADC values once per sec, if valid HB from autopilot has been recieved
    while (true) {

        //Send heartbeat
        mavlink_msg_heartbeat_pack(autopilotSysID, MAV_COMP_ID_PERIPHERAL, &msg, MAV_TYPE_ONBOARD_CONTROLLER, MAV_AUTOPILOT_INVALID, MAV_MODE_FLAG_SAFETY_ARMED, 0, MAV_STATE_ACTIVE);
		len = mavlink_msg_to_send_buffer(buf, &msg);
        uart_write_blocking(UART_ID, buf, len);

        sleep_ms(500);

        if (autopilotSysID != 0)
        {
            // read all the ADC's and send as named-value-floats
            for (int i = 0; i < 4; i++) {
                adc_select_input(i);
                uint16_t result = adc_read();
                float result_v = result * conversion_factor;

                printf("Raw value %s: 0x%03x, voltage: %.3f V\n", adclabels[i], result, result_v);

                //send named-value-float
                mavlink_msg_named_value_float_pack(autopilotSysID, MAV_COMP_ID_PERIPHERAL, &msg, to_ms_since_boot(get_absolute_time()), adclabels[i], result_v);
                len = mavlink_msg_to_send_buffer(buf, &msg);
                uart_write_blocking(UART_ID, buf, len);

                sleep_ms(125);
            }
        }
        else
        {
            printf("Waiting for hearbeat from autopilot\n");
            sleep_ms(500);
        }

    }
}
