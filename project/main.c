#include "shape.h"
#include "buzzer.h"
#include "led.h"
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include "triangle.c"

#define GREEN_LED BIT6
#define RED_LED BIT0

/** Initializes everything, clears the screen, draws "hello" and the circle */
void main()
{
  P1DIR |= GREEN_LED; // Green on/CPU on
  P1OUT |= GREEN_LED;
  configureClocks();
  buzzer_init();
  led_init();
  lcd_init();
  p2sw_init(15);
  or_sr(0x8); /* GIE (enable interrupts) */

  demo();
}
