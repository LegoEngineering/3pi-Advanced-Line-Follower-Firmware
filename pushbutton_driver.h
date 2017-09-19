//Header file for pushbutton driver to define its functions and associations
//Program by Andrew Brick 

#ifndef _pushbutton_driver_H_
#define _pushbutton_driver_H_

#include <stdint.h>
#include <avr/io.h>
#include <stdbool.h>

#define LEFT_BUTTON_PORT B  
#define RIGHT_BUTTON_PORT B
#define MIDDLE_BUTTON_PORT B

#define LEFT_BUTTON_BIT 1
#define RIGHT_BUTTON_BIT 5
#define MIDDLE_BUTTON_BIT 4

#define concat(A,B) A##B
#define PORT(letter) concat(PORT,letter)
#define DDR(letter) concat(DDR,letter)
#define PIN(letter) concat(PIN,letter)

void initialize_pushbutton_array();
bool left_button_is_pressed();
bool right_button_is_pressed();
bool middle_button_is_pressed();

#endif
