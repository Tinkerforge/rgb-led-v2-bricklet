#include "bindings/hal_common.h"
#include "bindings/bricklet_rgb_led_v2.h"

#define UID "XYZ" // Change XYZ to the UID of your RGB LED Bricklet 2.0

void check(int rc, const char* msg);

void example_setup(TF_HalContext *hal);
void example_loop(TF_HalContext *hal);


static TF_RGBLEDV2 rl;

void example_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_rgb_led_v2_create(&rl, UID, hal), "create device object");

	// Set light blue color
	check(tf_rgb_led_v2_set_rgb_value(&rl, 0, 170, 234), "call set_rgb_value");
}

void example_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
