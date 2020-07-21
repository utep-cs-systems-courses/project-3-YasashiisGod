#include <msp430.h>
#include "switches.h"
#include "state_machine.h"
#include "led.h"

/* Switch on P2 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & BUTTONS) {	      /* did a button cause this interrupt? */
    P2IFG &= ~BUTTONS;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}


void
__interrupt_vec(WDT_VECTOR) WDT(){
  sm_update_led();
  led_update();
}
