//Main file for Programming Assignment 3
//Program by Andrew Brick 

#include <avr/io.h>
#include "led_driver.h"
#include "pushbutton_driver.h"
#include "motor_driver.h"
#include <util/delay.h>

int main(){

initialize_left_led();
initialize_right_led();
initialize_pushbutton_array();
initialize_left_motor();
initialize_right_motor();

while(1){

	turn_on_left_led();
	turn_on_right_led();
	if(left_button_is_pressed()||middle_button_is_pressed()||right_button_is_pressed()){
			turn_off_left_led();
			_delay_ms(250);
			turn_off_right_led();
			_delay_ms(250);

			set_left_motor_duty_cycle(100);
			set_right_motor_duty_cycle(100);
			engage_left_motor_forward();
			engage_right_motor_forward();
			_delay_ms(1000);
			brake_left_motor();
			brake_right_motor();
			_delay_ms(1500);

			set_left_motor_duty_cycle(50);
			set_right_motor_duty_cycle(50);
			engage_left_motor_reverse();
			engage_right_motor_reverse();
			_delay_ms(2000);
			brake_left_motor();
			brake_right_motor();
			_delay_ms(1500);

			set_left_motor_duty_cycle(25);
			set_right_motor_duty_cycle(25);
			engage_left_motor_reverse();
			engage_right_motor_forward();
			_delay_ms(180);
			brake_left_motor();
			brake_right_motor();
			_delay_ms(1500);

			set_left_motor_duty_cycle(10);
			set_right_motor_duty_cycle(10);
			engage_left_motor_forward();
			engage_right_motor_reverse();
			_delay_ms(250);
			brake_left_motor();
			brake_right_motor();
			_delay_ms(1500);

			set_left_motor_duty_cycle(60);
			set_right_motor_duty_cycle(10);
			engage_left_motor_forward();
			engage_right_motor_forward();
			_delay_ms(1000);
			brake_left_motor();
			brake_right_motor();
			_delay_ms(1500);

			set_left_motor_duty_cycle(10);
			set_right_motor_duty_cycle(60);
			engage_left_motor_reverse();
			engage_right_motor_reverse();
			_delay_ms(1000);
			brake_left_motor();
			brake_right_motor();
			_delay_ms(1500);


		}
	}
 return 0;
}

