<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletRGBLEDV2.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletRGBLEDV2;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your RGB LED Bricklet 2.0

$ipcon = new IPConnection(); // Create IP connection
$rl = new BrickletRGBLEDV2(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Set light blue color
$rl->setRGBValue(0, 170, 234);

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
