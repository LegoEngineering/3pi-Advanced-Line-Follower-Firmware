//C file for motor driver to enumerate motor functions according to 3pi truth table
//Program by Andrew Brick 

#include <avr/io.h>
#include "motor_driver.h"

void initialize_left_motor(){
	brake_left_motor();
	DDR(LEFT_MOTOR_PORT_A) |= (1<<LEFT_MOTOR_BIT_A);
	DDR(LEFT_MOTOR_PORT_B) |= (1<<LEFT_MOTOR_BIT_B);
	TCCR0(LEFT_MOTOR_PWM_A) |= (1<<WGM00);
	TCCR0(LEFT_MOTOR_PWM_A) |= (1<<WGM01);
	TCCR0(LEFT_MOTOR_PWM_B) |= (1<<CS00);
}

void initialize_right_motor(){
	brake_right_motor();
	DDR(RIGHT_MOTOR_PORT_A) |= (1<<RIGHT_MOTOR_BIT_A);
	DDR(RIGHT_MOTOR_PORT_B) |= (1<<RIGHT_MOTOR_BIT_B);
	TCCR2(RIGHT_MOTOR_PWM_A) |= (1<<WGM20);
	TCCR2(RIGHT_MOTOR_PWM_A) |= (1<<WGM21);
	TCCR2(RIGHT_MOTOR_PWM_B) |= (1<<CS20);
}

void engage_left_motor_forward(){
	PORT(LEFT_MOTOR_PORT_A) |= (1<<LEFT_MOTOR_BIT_A);
	PORT(LEFT_MOTOR_PORT_B) &= ~(1<<LEFT_MOTOR_BIT_B);
}

void engage_left_motor_reverse(){
	PORT(LEFT_MOTOR_PORT_A) &= ~(1<<LEFT_MOTOR_BIT_A);
	PORT(LEFT_MOTOR_PORT_B) |= (1<<LEFT_MOTOR_BIT_B);
}

void engage_right_motor_forward(){
	PORT(RIGHT_MOTOR_PORT_A) |= (1<<RIGHT_MOTOR_BIT_A);
	PORT(RIGHT_MOTOR_PORT_B) &= ~(1<<RIGHT_MOTOR_BIT_B);
}

void engage_right_motor_reverse(){
	PORT(RIGHT_MOTOR_PORT_A) &= ~(1<<RIGHT_MOTOR_BIT_A);
	PORT(RIGHT_MOTOR_PORT_B) |= (1<<RIGHT_MOTOR_BIT_B);
}



void brake_left_motor(){
	PORT(LEFT_MOTOR_PORT_A) |= (1<<LEFT_MOTOR_BIT_A);
	PORT(LEFT_MOTOR_PORT_B) |= (1<<LEFT_MOTOR_BIT_B);
}

void brake_right_motor(){
	PORT(RIGHT_MOTOR_PORT_A) |= (1<<RIGHT_MOTOR_BIT_A);
	PORT(RIGHT_MOTOR_PORT_B) |= (1<<RIGHT_MOTOR_BIT_B);
}

void coast_left_motor(){
	PORT(LEFT_MOTOR_PORT_A) &= ~(1<<LEFT_MOTOR_BIT_A);
	PORT(LEFT_MOTOR_PORT_B) &= ~(1<<LEFT_MOTOR_BIT_B);
}

void coast_right_motor(){
	PORT(RIGHT_MOTOR_PORT_A) &= ~(1<<RIGHT_MOTOR_BIT_A);
	PORT(RIGHT_MOTOR_PORT_B) &= ~(1<<RIGHT_MOTOR_BIT_B);
}



void set_left_motor_duty_cycle(uint8_t duty_cycle){

	if(duty_cycle < 10){
		coast_left_motor();
		}else{
		OCR0(LEFT_MOTOR_PWM_A) = duty_cycle;
		OCR0(LEFT_MOTOR_PWM_B) = duty_cycle;
		}
}

void set_right_motor_duty_cycle(uint8_t duty_cycle){

	if(duty_cycle < 10){
		coast_right_motor();
		}else{
		OCR0(RIGHT_MOTOR_PWM_A) = duty_cycle;
		OCR0(RIGHT_MOTOR_PWM_B) = duty_cycle;
		}
}
