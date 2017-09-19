//C file for pushbuttons
//Program by Andrew Brick

#ifndef _pushbutton_driver_C_
#define _pushbutton_driver_C_

#include "pushbutton_driver.h"

void initialize_pushbutton_array(){
	
PORT(LEFT_BUTTON_PORT) |= (1<<LEFT_BUTTON_BIT);
PORT(RIGHT_BUTTON_PORT) |= (1<<RIGHT_BUTTON_BIT);
PORT(MIDDLE_BUTTON_PORT) |= (1<<MIDDLE_BUTTON_BIT);

DDR(LEFT_BUTTON_PORT) &= ~(1<<LEFT_BUTTON_BIT);
DDR(RIGHT_BUTTON_PORT) &= ~(1<<RIGHT_BUTTON_BIT);
DDR(MIDDLE_BUTTON_PORT) &= ~(1<<MIDDLE_BUTTON_BIT);
}

bool left_button_is_pressed(){

if(PIN(LEFT_BUTTON_PORT)&(1<<LEFT_BUTTON_BIT))
return false;
else
return true;
}

bool right_button_is_pressed(){

if(PIN(RIGHT_BUTTON_PORT)&(1<<RIGHT_BUTTON_BIT))
return false;
else
return true;
}

bool middle_button_is_pressed(){

if(PIN(MIDDLE_BUTTON_PORT)&(1<<MIDDLE_BUTTON_BIT))
return false;
else
return true;
}

#endif
