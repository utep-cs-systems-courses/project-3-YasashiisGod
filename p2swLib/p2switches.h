#ifndef switches_included
#define switches_included

#define SW1 BIT0;
#define SW2 BIT1;
#define SW3 BIT2;
#define SW4 BIT3;

#define BUTTONS (SW1 | SW2 | SW3 | SW4)

#include "msp430.h"

char s1_down, s2_down, s3_down, s4_down;
char light_mode;

unsigned int p2sw_read();
void p2sw_init(unsigned char mask);


#endif // included

