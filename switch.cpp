//----------------------------------------------------------------------//
// Programmer: Leslie Ibarra    
// Date: 02/17/2020
// Course: UArizona - ECE 372a
// Assignment: LAB 2
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>


void initSwitchPB3(){
  //Initializing pull-up resistor on PB3 and setting to input mode
  DDRB &= ~(1 << DDB3);     //Data direction register set for input
  PORTB |= (1 << PORTB3);   //Pull-up resistor on PORTB3 inside microcontroller enabled

  PCICR |= (1 << PCIE0);    //Enable PCINT for 7-0
  PCMSK0 |= (1 << PCINT3);  //Enable PCINT for PCINT3
}
