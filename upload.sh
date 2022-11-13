#!/bin/bash

ampy --port /dev/ttyACM0 put mavcrc.py /mavcrc.py
ampy --port /dev/ttyACM0 put pymavminimal.py /pymavminimal.py
ampy --port /dev/ttyACM0 put main.py /main.py
