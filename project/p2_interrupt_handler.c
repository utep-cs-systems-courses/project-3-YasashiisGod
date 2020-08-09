#include <msp430.h>
#include "switches.h"
#include "state_machine2.h"
#include "led.h"


/* Switch on P2 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & BUTTONS) {	      /* did a button cause this interrupt? */
    P2IFG &= ~BUTTONS;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

/*
void
__interrupt_vec(WDT_VECTOR) WDT(){

  P1OUT |= RED_LED;
  static char count = 0;
  if (++count == 125) {
    if (state != 3)
      state_advance();    // Calls state advance for all other cases for toggling
    count = 0;
  }
  if (state == 3)
    state_advance();    // Calls state advance for all other cases for toggling
  P1OUT &= ~RED_LED;

}

*/
