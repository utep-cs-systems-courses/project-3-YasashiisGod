#ifndef switches_included
#define switches_included

#define SW1 BIT0           		/* switch1 is p1.3 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define BUTTONS (SW1 | SW2 | SW3 | SW4)	/* Initialized all the buttons */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed;
extern char s1_down, s2_down, s3_down, s4_down;
extern char light_mode, factor;


#endif // included
