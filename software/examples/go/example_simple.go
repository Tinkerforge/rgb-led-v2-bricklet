package main

import (
	"fmt"
	"github.com/Tinkerforge/go-api-bindings/ipconnection"
	"github.com/Tinkerforge/go-api-bindings/rgb_led_v2_bricklet"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your RGB LED Bricklet 2.0.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	rl, _ := rgb_led_v2_bricklet.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	// Set light blue color
	rl.SetRGBValue(0, 170, 234)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()
}
