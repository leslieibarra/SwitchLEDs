//----------------------------------------------------------------------//
// Programmer: Leslie Ibarra    
// Date: 02/17/2020
// Course: UArizona - ECE 372a
// Assignment: LAB 2
//----------------------------------------------------------------------//


#include "timer.h"

//Initializing Timer0, Use CTC mode
void initTimer0(){
    TCCR0A &= ~( 1 << WGM00 ); 
    TCCR0A |=  ( 1 << WGM01 );
    TCCR0B &= ~( 1 << WGM02 );

    //Turn on timer by setting the prescaler
    TCCR0B |= (1 << CS01) | (1 << CS00); 
    TCCR0B &= ~(1 << CS02); 

    OCR0A = 249;    //Setting the calculated OCR0A value
}

/* This delays the program an amount specified by unsigned int delay.
* Use timer 0. Keep in mind that you need to choose your prescalar wisely
* such that your timer is precise to 1 millisecond and can be used for
* 100-200 milliseconds
*/
void delayMs(unsigned int delay){
    
    unsigned int count = 0;

    TIFR0 |= (1 << OCF0A);  //Set the flag down, initially flag is down
    TCNT0 = 0;  //Setting the count to 0 (Clearing the timer)
    
    while (count < delay) {

        if (TIFR0 & (1 << OCF0A)) {
            count++;
            TIFR0 |= (1 << OCF0A);
            
        }
    }
}
