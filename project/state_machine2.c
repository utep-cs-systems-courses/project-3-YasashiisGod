#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "state_machine2.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
// #include assembly.h

unsigned char toggle_led;
//Dim variable higher = lower brightness
static char dim = 0;
//Intializes state machine and variables
void state_init() {
  state = 0;
}
//Method resets state machine and variables back to start
void reset_states() {
  state = 0;
  toggle_led = 0;
  buzzer_set_period(0);
  led_update();
}

void drawState() {
  u_char width = screenWidth, height = screenHeight;
  clearScreen(COLOR_BLACK);
  
  switch (state) {
  case 0:
    drawString5x7(5,22,"Press B1 to", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(5,32,"start again", COLOR_WHITE, COLOR_BLACK);
    break;
  case 1:
    drawString5x7(5,22,"Press 2 to", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(5,32,"spawn Triangle", COLOR_WHITE, COLOR_BLACK);
    break;
  case 2:
    drawString5x7(5,22,"Press 3 to", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(5,32,"double size", COLOR_WHITE, COLOR_BLACK);
    drawTriangle(40,120, 30, COLOR_WHITE);
    break;
  case 3:
    drawString5x7(5,22,"Press 1&3 to", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(5,32,"change color and ", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(5,42,"play a tune", COLOR_WHITE, COLOR_BLACK);
    drawTriangle(10,100, 60, COLOR_WHITE);
    break;
  case 4:
    drawString5x7(5,22,"Playing -", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(5,32,"Falling Chirp", COLOR_WHITE, COLOR_BLACK);
    drawTriangle(10,100, 60, COLOR_BLUE);
    break;
  }
  P1OUT &= ~LED_GREEN;
  or_sr(0x18);
}

void state_advance() {
  //Switch 4 is exit case for all states
  if(s4_down) {
    reset_states();
    //play_beep();
  }
  //Dimming for case 3 only
  dim++;
  dim = (dim > 8) ? 0 : dim;

  switch (state) {
  case 1:               /* Case 1 set green led and plays beep when sw1 & sw3 are down moves case */
    P1OUT |= LED_GREEN;
    //Led dimmer logic
    if (dim == 0)
      toggle_led = LED_RED;
    else
      toggle_led = 0;
    if(s2_down) {  // was 1 & 3 now is button 2
      state = 2;
      //playbeep
      drawState();
    }
    break;
  case 2:               /* case 2 sets red led and plays beep when sw2 & sw3 are down moves case */
    P1OUT |= LED_GREEN;
    //Led dimmer logic
    if (dim == 0)
      toggle_led = LED_RED;
    else
      toggle_led = 0;
    if(s3_down) {
      state = 3;
      drawState();
    }
    break;
  case 3:               /* Third case dims both leds and plays beep when sw1 & sw2 & sw3 are down moves case */
    P1OUT |= LED_GREEN;
    //Led dimmer logic
    if (dim == 0)
      toggle_led = LED_RED;
    else
      toggle_led = 0;
    //wating for next case
    if(s1_down && s3_down) {
      state = 4;
      //play_beep();
      drawState();
    }
    break;
  case 4:               /* Last case or "win case" sets state to zero to start over and then plays song because you won */
    P1OUT |= LED_GREEN;
    state = 0;
    play_sound();//Song player
    drawState();
    break;
  case 0:               /* Base case toggles led with timer intterrupt, moves to case 1 and plays beep if sw1 is down */
    P1OUT |= LED_GREEN;
    if(s1_down) {
      state = 1;
      //play_beep();
      drawState();
    }
    break;
  default: break;
  }

  led_update();
}
