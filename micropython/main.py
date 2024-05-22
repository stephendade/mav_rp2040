#!/usr/bin/env python3
# Micropython script for the Raspberry Pi Pico (or any RP2040 based board) for sending ADC
# values via MAVLink connection. The ADC values can then be viewed on a ground station.
# This requires the RP2040's UART (Rx, Tx, Gnd, Pwr) to be connected to a flight controller's
# TELEM ports.

# The TELEM port should be set to MAVLink2, 57600 baud

# In MAVProxy, use "graph NAMED_VALUE_FLOAT[ADC0].value NAMED_VALUE_FLOAT[ADC1].value NAMED_VALUE_FLOAT[ADC2].value"
# to view the values

from machine import Pin, Timer, ADC, UART
import time
import pymavminimal as pymav

led = Pin(25, Pin.OUT)
timer = Timer()

uart0 = UART(0, baudrate=57600, tx=Pin(0), rx=Pin(1))

adc3_value = ADC(29)
adc2_value = ADC(28)
adc1_value = ADC(27)
adc0_value = ADC(26)
conversion_factor = 3.3/(65536) 
seen_heartbeat = False

def sendFloats(timer):
    if seen_heartbeat:
        #send floats
        msgs = []
        msgs.append(mavobj.heartbeat_encode(pymav.MAV_TYPE_ONBOARD_CONTROLLER, 8, 0, 0, 0))
        msgs.append(mavobj.named_value_float_encode(time.ticks_ms(), "ADC0", adc0_value.read_u16() * conversion_factor))
        msgs.append(mavobj.named_value_float_encode(time.ticks_ms(), "ADC1", adc1_value.read_u16() * conversion_factor))
        msgs.append(mavobj.named_value_float_encode(time.ticks_ms(), "ADC2", adc2_value.read_u16() * conversion_factor))
        msgs.append(mavobj.named_value_float_encode(time.ticks_ms(), "ADC3", adc3_value.read_u16() * conversion_factor))
        for msg in msgs:
            uart0.write(msg.pack(mavobj))
        print("Sent at {0}".format(time.ticks_ms()))

# Use a timer for sending packets
timer.init(freq=1, mode=Timer.PERIODIC, callback=sendFloats)

# MAVLink
mavobj = pymav.MAVLink()
mavobj.robust_parsing = True

# Keep looping to receive data
while True:
    num = uart0.any()
    # Receive data and process into MAVLink packets
    if num > 0:
        rxData = uart0.read(num)
        pkts = mavobj.parse_buffer(bytearray(rxData))
        if pkts is not None:
            for pkt in pkts:
                if pkt.get_type() == 'HEARTBEAT' and pkt.type not in [pymav.MAV_TYPE_GCS, pymav.MAV_TYPE_ADSB, pymav.MAV_TYPE_GIMBAL, pymav.MAV_TYPE_ONBOARD_CONTROLLER]:
                    led.toggle()
                    if not seen_heartbeat:
                        print("Got heartbeat from {0}:{1}".format(pkt.get_srcSystem(), pkt.get_srcComponent()))
                        mavobj.srcSystem = pkt.get_srcSystem()
                        mavobj.srcComponent = 158 #MAV_COMP_ID_PERIPHERAL
                        seen_heartbeat = True
    time.sleep(0.01)
