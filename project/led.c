#include <msp430.h>
#include "led.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached  to leds are output
  led_update();
}

void led_update(){ 
  char ledFlags = toggle_led; //state_machine given value for toggle
  
  P1OUT &= (0xff-LEDS) | ledFlags; // turn off leds 
  P1OUT |= ledFlags; // sets bits 
}
