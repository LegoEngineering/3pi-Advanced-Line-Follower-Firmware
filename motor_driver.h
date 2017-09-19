//Header file for motor driver to define its functions and associations
//Program by Andrew Brick 

#ifndef _motor_driver_
#define _motor_driver_
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#define LEFT_MOTOR_PORT_A D
#define LEFT_MOTOR_PORT_B D
#define LEFT_MOTOR_BIT_A 6
#define LEFT_MOTOR_BIT_B 5
#define RIGHT_MOTOR_PORT_A B
#define RIGHT_MOTOR_PORT_B D
#define RIGHT_MOTOR_BIT_A 3
#define RIGHT_MOTOR_BIT_B 3
#define RIGHT_MOTOR_PWN_A A
#define RIGHT_MOTOR_PWM_B B
#define LEFT_MOTOR_PWM_A A
#define LEFT_MOTOR_PWM_B B
#define RIGHT_MOTOR_PWM_A A
#define RIGHT_MOTOR_PWM_B B
#define WGM00 0
#define WGM01 1
#define WGM02 3

#define CS00 0
#define CS01 1
#define WGM20 0
#define WGM21 1
#define CS20 0
#define CS21 1
#define concat(A,B) A##B
#define PORT(letter) concat(PORT,letter)
#define DDR(letter) concat(DDR,letter)
#define PIN(letter) concat(PIN,letter)
#define TCCR0(letter) concat(TCCR0,letter)
#define OCR0(letter) concat(OCR0,letter)
#define TCCR2(letter) concat(TCCR2,letter)
#define OCR2(letter) concat(OCR2,letter)


void initialize_left_motor();
void initialize_right_motor();

void engage_left_motor_forward();
void engage_left_motor_reverse();
void engage_right_motor_forward();
void engage_right_motor_reverse();

void brake_left_motor();
void brake_right_motor();
void coast_left_motor();
void coast_right_motor();

void set_left_motor_duty_cycle(uint8_t duty_cycle);
void set_right_motor_duty_cycle(uint8_t duty_cycle);

uint8_t left_motor_duty_cycle();
uint8_t right_motor_duty_cycle();


#endif
