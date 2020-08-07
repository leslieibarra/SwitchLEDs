//----------------------------------------------------------------------//
// Programmer: Leslie Ibarra    
// Date: 02/17/2020
// Course: UArizona - ECE 372a
// Assignment: LAB 2
//----------------------------------------------------------------------//

#include <Arduino.h>
#include <avr/io.h>
#include "led.h"
#include "switch.h"
#include "timer.h"

/*
 * Define a set of states that can be used in the state machine using an enum.
 */
typedef enum stateType_enum {wait_press, debounce_press, wait_release, debounce_release} stateType; 
volatile stateType state = wait_press;

bool isdelay = true;  //Boolean changes states when switch is pressed
unsigned char i = 0;  //Increment to turn on LEDs

int main(){
    initSwitchPB3();
    initLED();
    initTimer0();
    sei();

	
  while (1) {
    i++;

    //Selecting between short and long delay
    if(isdelay == true) {
      turnOnLEDWithChar(i);
      delayMs(200);
    }
    else {
      turnOnLEDWithChar(i);
      delayMs(100);
    }
   
    switch(state) {

      case wait_press:
      break;

      case debounce_press:
      delayMs(1);
      state = wait_release;
      break;

      case wait_release:
      break;

      case debounce_release:
      delayMs(1);
      state = wait_press;
      break;

    }
  }
  
  return 0;

} //END main()

/* Implement an Pin Change Interrupt which handles the switch being
* pressed and released. When the switch is pressed and released, the LEDs
* change at twice the original rate. If the LEDs are already changing at twice
* the original rate, it goes back to the original rate.
*/
ISR(PCINT0_vect){
  if(state == wait_press) {
    state = debounce_press;
  }
  else if(state == wait_release) {
    isdelay = !isdelay;
    state = debounce_release;
  }
}