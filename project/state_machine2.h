#ifndef state_machine_included
#define state_machine_included

#include <msp430.h>
  
//static enum {off, dim, bright} led_state;
//static char pwmCount;

void sm_slow_clock();
char toggle_red();
void state_advance();
void sm_update_led();


#endif
