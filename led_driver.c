//C file for LEDs
//Program by Andrew Brick

#ifndef _led_driver_C_
#define _led_driver_C_

#include "led_driver.h"

void initialize_left_led() {
	DDR(LEFT_LED_PIN) &= ~(1<<LEFT_LED_BIT);
	}

void initialize_right_led() {
	DDR(RIGHT_LED_PIN) &= ~(1<<RIGHT_LED_BIT);
	}

void turn_on_left_led() {
	PIN(LEFT_LED_PIN) |= (1<<LEFT_LED_BIT);
	}

void turn_off_left_led() {
	PIN(LEFT_LED_PIN) &= ~(1<<LEFT_LED_BIT);
	}

void turn_on_right_led() {
	PIN(RIGHT_LED_PIN) |= (1<<RIGHT_LED_BIT);
	}

void turn_off_right_led() {
	PIN(RIGHT_LED_PIN) &= ~(1<<RIGHT_LED_BIT);
	}

void toggle_left_led()	{
	PIN(LEFT_LED_PIN) ^= (1<<LEFT_LED_BIT);
	}

void toggle_right_led()	{
	PIN(RIGHT_LED_PIN) ^= (1<<RIGHT_LED_BIT);
	}

#endif
