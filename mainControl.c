#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

#include "lcdutils.h"
#include <lcddraw.h>
#include <p2switches.h>

void main(void) 
{  
  configureClocks();
  lcd_init();
  p2sw_init(15);
  buzzer_init();
  switch_init();
  led_init();
  enableWDTInterrupts();
  
  
  or_sr(0x18);  // CPU off, GIE on
  or_sr(0X8); 
  clearrScreen(COLORBLUE);
} 
