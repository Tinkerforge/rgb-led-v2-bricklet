#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your RGB LED Bricklet 2.0

# Set light blue color
tinkerforge call rgb-led-v2-bricklet $uid set-rgb-value 0 170 234
