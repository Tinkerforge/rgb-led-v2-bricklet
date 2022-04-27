// This example is not self-contained.
// It requires usage of the example driver specific to your platform.
// See the HAL documentation.

#include "src/bindings/hal_common.h"
#include "src/bindings/bricklet_rgb_led_v2.h"

void check(int rc, const char *msg);
void example_setup(TF_HAL *hal);
void example_loop(TF_HAL *hal);

static TF_RGBLEDV2 rl;

void example_setup(TF_HAL *hal) {
	// Create device object
	check(tf_rgb_led_v2_create(&rl, NULL, hal), "create device object");

	// Set light blue color
	check(tf_rgb_led_v2_set_rgb_value(&rl, 0, 170, 234), "call set_rgb_value");
}

void example_loop(TF_HAL *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
