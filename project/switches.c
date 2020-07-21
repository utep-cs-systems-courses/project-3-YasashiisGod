#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char switch_state_down, switch_state_changed;
char s1_down, s2_down, s3_down, s4_down;
char light_mode = 0, factor = 0;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & BUTTONS);	/* if switch up, sense down */
  P2IES &= (p2val | ~BUTTONS);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= BUTTONS;		/* enables resistors for switches */
  P2IE = BUTTONS;		/* enable interrupts from switches */
  P2OUT |= BUTTONS;		/* pull-ups for switches */
  P2DIR &= ~BUTTONS;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  s1_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  s2_down = (p2val & SW2) ? 0 : 1; /* 0 when SW2 is up */
  s3_down = (p2val & SW3) ? 0 : 1; /* 0 when SW3 is up */
  s4_down = (p2val & SW4) ? 0 : 1; /* 0 when SW4 is up */

  if (s1_down){
    light_mode = 1;
    factor++;
  }
  if (s2_down){
    light_mode = 2;
    factor++;
  }
  if (s3_down){
    light_mode = 3;
    factor++;
  }
  if (s4_down){
    light_mode = 4;
    factor++;
  }
  switch_state_changed = 1;
}
