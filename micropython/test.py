#!/usr/bin/env python3

# The TELEM port should be set to MAVLink2, 57600 baud

from machine import Pin, UART
import time
import pymavminimal as pymav

led = Pin(25, Pin.OUT)

uart0 = UART(0, baudrate=57600, tx=Pin(0), rx=Pin(1))

seen_heartbeat = False

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
                        # Send the set message interval request for VFR_HUD (74), once we have heard the first heartbeat
                        command = 511 #MAV_CMD_SET_MESSAGE_INTERVAL
                        param1 = 74 # Message ID MAVLINK_MSG_ID_VFR_HUD
                        param2 = 1 # Message interval
                        cmd = mavobj.command_long_encode(1, 1, command, 1, param1, param2, 0, 0, 0, 0, 0)
                        uart0.write(cmd.pack(mavobj))
                if pkt.get_type() == 'VFR_HUD':
                    print(pkt)
    time.sleep(0.01)
