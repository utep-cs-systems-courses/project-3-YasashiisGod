#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "state_machine2.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "state_machine1.h"

unsigned char toggle_led, state;
int redrawScreen;
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
}

void stateDeterminedScreen() {
  u_char width = screenWidth, height = screenHeight;
  clearScreen(COLOR_BLACK);
  drawString5x7((width-75), 5,"*B4 to reset", COLOR_RED, COLOR_BLACK); // Always shown
  switch (state) {
  case 0:
    drawString5x7(5,42,"Press B1 to", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(41,42,"B1", COLOR_YELLOW, COLOR_BLACK);
    drawString5x7(5,52,"start again", COLOR_WHITE, COLOR_BLACK);
    break;
  case 1:
    drawString5x7(5,42,"Press B2 to", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(41,42,"B2", COLOR_YELLOW, COLOR_BLACK);
    drawString5x7(5,52,"spawn Triangle", COLOR_WHITE, COLOR_BLACK);
    break;
  case 2:
    drawString5x7(5,42,"Press B3 to", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(41,42,"B3", COLOR_YELLOW, COLOR_BLACK);
    drawString5x7(5,52,"double size", COLOR_WHITE, COLOR_BLACK);
    drawTriangle(40,120, 30, COLOR_WHITE);
    break;
  case 3:
    drawString5x7(5,42,"Press B1 & B3 to", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(41,42,"B1 & B3", COLOR_YELLOW, COLOR_BLACK);
    drawString5x7(59,42,"&", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(5,52,"change color and ", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(47,52,"color", COLOR_GREEN, COLOR_BLACK);
    
    drawString5x7(5,62,"play a tune", COLOR_WHITE, COLOR_BLACK);
    drawTriangle(10,100, 60, COLOR_WHITE);
    break;
  case 4:
    drawString5x7(5,42,"Playing -", COLOR_WHITE, COLOR_BLACK); // dont ask ;-;          jk
    drawString5x7(5,52,"F", COLOR_RED, COLOR_BLACK);
    drawString5x7(11,52,"a", COLOR_ORANGE_RED, COLOR_BLACK);
    drawString5x7(17,52,"ll and Rise", COLOR_DARK_ORANGE, COLOR_BLACK);
    drawString5x7(23,52,"l and Rise", COLOR_GRAY, COLOR_BLACK);
    drawString5x7(35,52,"and Rise", COLOR_NAVY, COLOR_BLACK);
    drawString5x7(41,52,"nd Rise", COLOR_STEEL_BLUE, COLOR_BLACK);
    drawString5x7(47,52,"d Rise", COLOR_SPRING_GREEN, COLOR_BLACK);
    drawString5x7(53,52," Rise", COLOR_LIME_GREEN, COLOR_BLACK);
    drawString5x7(59,52,"Rise", COLOR_KHAKI, COLOR_BLACK);
    drawString5x7(65,52,"ise", COLOR_GOLD, COLOR_BLACK);
    drawString5x7(71,52,"se", COLOR_HOT_PINK, COLOR_BLACK);
    drawString5x7(77,52,"e", COLOR_DEEP, COLOR_BLACK);
    drawTriangle(10,100, 60, COLOR_RED);
    break;
  }
}
/*
//second method for assembly
int dimmerSet(){
  dim++;
  if (dim == 4)
    return 1;
  else
    return 0;
  }
*/
void colorText(int x){
  drawString5x7(x,42,"B", COLOR_YELLOW, COLOR_BLACK);
}
/*
int colorTextPlacement(char state){
  switch(state){
  case 1:
    return 41;
    break;
  case 2:
    return 41;
    break;
  case 3:
    return 41; //second B
    break;
  case 4:
    return 71;
  default:
    return 200;
    break;
  }
} 
*/   
void state_advance() {
  led_update();
  //Switch 4 is reset during every state 
  if(s4_down)
    {
      reset_states();
      redrawScreen = 1;
    }
   
  switch (state) {
  case 1:       
    if (dimmerSet(dim))
      {
	toggle_led |= LED_GREEN;
	dim = 0;
      }
    else
      {
	toggle_led &= ~LED_GREEN;
	dim++;
      }
    if(s2_down)
      {
        state = 2;
	buzzer_set_period(2000);
	colorText(colorTextPlacement(state));
	redrawScreen = 1;
      }
    break;
  case 2:              
    if (dimmerSet(dim))
      {
	toggle_led |= LED_GREEN;
	dim = 0;
      }
    else
      {
	toggle_led &= ~LED_GREEN;
	dim++;
      }
    if(s3_down)
      {
	state = 3;
	buzzer_set_period(3000);
	colorText(colorTextPlacement(state));
	redrawScreen = 1;
      }
    break;
  case 3:     
    if (dimmerSet(dim))
      {
	toggle_led |= LED_GREEN;
	dim = 0;
      }
    else
      {
	toggle_led &= ~LED_GREEN;
	dim++;
      } 
    if(s1_down && s3_down)
      {
	state = 4;
	buzzer_set_period(4000);
	colorText(colorTextPlacement(state));
	redrawScreen = 1;
      }
    break;
  case 4:
    toggle_led |= LED_GREEN;
    state = 0;
    play_sound();                            //Song player at end state
    colorText(colorTextPlacement(state));
    redrawScreen = 1;
    break;
  case 0:
    toggle_led |= LED_GREEN;
    if(s1_down)
      {
	state = 1;
	buzzer_set_period(1000);
        redrawScreen = 1;
      }
    break;
  default:
    break;
  }
}
