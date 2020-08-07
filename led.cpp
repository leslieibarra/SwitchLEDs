//----------------------------------------------------------------------//
// Programmer: Leslie Ibarra    
// Date: 02/17/2020
// Course: UArizona - ECE 372a
// Assignment: LAB 2
//----------------------------------------------------------------------//


#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

void initLED(){
    //Initialize pins PA0, PA1, PA2, and PA3 to outputs
    DDRA |= (1<< DDA0) | (1<< DDA1) | (1<< DDA2) | (1 << DDA3);
}

/* This must be one line of code.
* In this function you will be giving a number "num" which will be represented
* in binary by four LEDs. You must effectively assign the lowest four bits of
* "num" to the appropriate bits of PORTA.
*/
void turnOnLEDWithChar(unsigned char num){
    PORTA = (PORTA & 0xF0) | (num & 0x0F);
}
