#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_rgb_led_v2'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change XYZ to the UID of your RGB LED Bricklet 2.0

ipcon = IPConnection.new # Create IP connection
rl = BrickletRGBLEDV2.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Set light blue color
rl.set_rgb_value 0, 170, 234

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
