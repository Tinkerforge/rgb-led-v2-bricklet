/* rgb-led-v2-bricklet
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * led.c: Driver for RGB LED
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "led.h"

#include "configs/config_led.h"
#include "bricklib2/hal/ccu4_pwm/ccu4_pwm.h"
#include "bricklib2/hal/system_timer/system_timer.h"

#include "xmc_gpio.h"

#include "cie1931.h"

LED led;

void led_init(void) {
	const XMC_GPIO_CONFIG_t output_config = {
		.mode         = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
		.output_level = XMC_GPIO_OUTPUT_LEVEL_HIGH,
	};

	XMC_GPIO_Init(LED_R_PIN, &output_config);
	XMC_GPIO_Init(LED_G_PIN, &output_config);
	XMC_GPIO_Init(LED_B_PIN, &output_config);

	ccu4_pwm_init(LED_R_PIN, LED_R_CCU4_SLICE, LED_PERIOD_VALUE-1);
	ccu4_pwm_init(LED_G_PIN, LED_G_CCU4_SLICE, LED_PERIOD_VALUE-1);
	ccu4_pwm_init(LED_B_PIN, LED_B_CCU4_SLICE, LED_PERIOD_VALUE-1);

	memset(&led, 0, sizeof(LED));
}

void led_tick(void) {
	static uint8_t last_r = 0;
	static uint8_t last_g = 0;
	static uint8_t last_b = 0;

	if(led.r != last_r) {
		ccu4_pwm_set_duty_cycle(LED_R_CCU4_SLICE, cie1931[led.r]);
		last_r = led.r;
	}
	if(led.g != last_g) {
		ccu4_pwm_set_duty_cycle(LED_G_CCU4_SLICE, cie1931[led.g]);
		last_g = led.g;
	}
	if(led.b != last_b) {
		ccu4_pwm_set_duty_cycle(LED_B_CCU4_SLICE, cie1931[led.b]);
		last_b = led.b;
	}
}