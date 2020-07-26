#include "state_machine.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include <msp430.h>
 
//  variables for the state
static enum {off = 0, dim =1, bright = 2} led_state;
static char pwmCount = 0;

// slowly cycles through {off dim and bright}
void sm_slow_clock(){ 
  led_state = (led_state + 1) % 3;
}

// Always toggle
char toggle_red(){ 
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
  case 1:
    red_on = 0;
    state = 0;
  }
  return 1;
}

//Alternate between toggling red & green
void state_advance(){
  char changed = 0;
  changed = toggle_red();
  led_changed = changed;
  led_update();
}

void sm_update_led(){
  pwmCount = (pwmCount + 1) % 3;
  char red_on_alt, green_on_alt;
  switch(light_mode){
  case 0:             // MSP Starts with both lights on, no button pressed yet
    red_on_alt = 1;
    green_on_alt = 1;
    break;
  case 1:             // Green is on
    red_on_alt = (factor % 2);
    green_on_alt = 0;
    buzzer_set_period(6000);
    break;
  case 2:             // Green dims
    red_on_alt = 0;
    green_on_alt = (pwmCount <1);
    break;
  case 3:             // Red is on
    red_on_alt = 0;
    green_on_alt = (factor % 2);
    buzzer_set_period(8000);
    break;
  case 4:             // Red dims
    red_on_alt = (pwmCount <1);
    green_on_alt = 0;
    buzzer_set_period(9000);
    break;
  }
  if (red_on != red_on_alt || green_on != green_on_alt)
    {
      red_on = red_on_alt;
      green_on = green_on_alt;
      led_changed = 1;
    }
}
