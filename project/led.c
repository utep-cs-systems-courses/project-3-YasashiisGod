#include <msp430.h>
#include "led.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached  to leds are output
  led_update();
} // Nothing changed

void led_update(){ 
  char ledFlags = 0; //state_machine given value for toggle
  ledFlags = toggle_led; // toggle LED changed in state machine
  P1OUT &= (0xff-LEDS) | ledFlags; // turn off leds 
  P1OUT |= ledFlags; // sets bits 
}
