#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "project3demo.h"
#include "state_machine2.h"

int redrawScreen = 1;  
unsigned char toggle_led, state;
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
  
  clearScreen(COLOR_BLACK);
  project_3_demo();

  play_sound2();
  
  enableWDTInterrupts();
  or_sr(0x8); /* GIE (enable interrupts) */
  for (;;) {
    while (!redrawScreen) {
      P1OUT |= LED_RED;
      or_sr(0x10);
    }
    stateDeterminedScreen();
    redrawScreen = 0;
    P1OUT &= ~LED_RED;
  }
}
/** Watchdog timer interrupt handler. 15 interrupts/sec */
void wdt_c_handler()
{
  //P1OUT |= RED_LED;
  static char count = 0; // added logic from old handler
  if (++count == 125) {
    if (state != 3)
      state_advance();    // Calls state advance for all other cases for toggling
    count = 0;
  }
  if (state == 3)
    state_advance();    // Calls state advance for all other cases for toggling
  //P1OUT &= ~RED_LED; 
}
  
