#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include "project3demo.h"

void project_3_demo()
{
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_GREEN);

  /*

  int j;
  for(j=60; j<75; j++){
    int row = j;
    for (int col = j; col <= screenWidth - j; col++)
      drawPixel(row-35, col+80, COLOR_WHITE);
  }
  drawString5x7(20,20, "Hey There Del..", COLOR_BLACK, COLOR_GREEN);
  */

  
  
  drawString8x12(10,20, "You got this!", COLOR_BLACK, COLOR_GREEN);

  drawString8x12(19,45, "Keep going", COLOR_BLACK, COLOR_GREEN);

  drawString8x12(50,70, ":)", COLOR_BLACK, COLOR_GREEN);

  // fillRectangle(20,30,30, 30, COLOR_WHITE);
}
