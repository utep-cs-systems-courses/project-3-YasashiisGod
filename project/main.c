#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "project3demo.h"
#include "state_machine2.h"

unsigned char toggle_led;

/** Initializes everything, clears the screen, draws "hello" and the circle */
void main()
{
  u_char width = screenWidth, height = screenHeight; 
  configureClocks();
  buzzer_init();
  led_init();
  lcd_init();
  switch_init();
  state_init();
 
  enableWDTInterrupts();
  clearScreen(COLOR_BLACK);
  
  project_3_demo();


  P1OUT &= ~LED_GREEN; // turns off cpu
  or_sr(0x18); /* GIE (enable interrupts) */
  
}
