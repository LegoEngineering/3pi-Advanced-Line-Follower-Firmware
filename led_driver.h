//Header file for led_driver.c
//Program by Andrew Brick

#ifndef _led_driver_H_
#define _led_driver_H_

#include <stdint.h>
#include <avr/io.h>

#define LEFT_LED_PIN D
#define RIGHT_LED_PIN D

#define LEFT_LED_BIT 1
#define RIGHT_LED_BIT 7

#define concat(A,B) A##B
#define PIN(letter) concat(PIN,letter)
#define DDR(letter) concat(DDR,letter)

void initialize_left_led();
void initialize_right_led();
void turn_on_left_led();
void turn_off_left_led();
void turn_on_right_led();
void turn_off_right_led();
void toggle_left_led();
void toggle_right_led();

#endif
