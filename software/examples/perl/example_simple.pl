#!/usr/bin/perl

use strict;
use Tinkerforge::IPConnection;
use Tinkerforge::BrickletRGBLEDV2;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your RGB LED Bricklet 2.0

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $rl = Tinkerforge::BrickletRGBLEDV2->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Set light blue color
$rl->set_rgb_value(0, 170, 234);

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
