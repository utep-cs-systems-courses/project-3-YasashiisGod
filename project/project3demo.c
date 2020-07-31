#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include "project3demo.h"

void project_3_demo()
{
  
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_GREEN);  
  
  drawString5x7(13,15, "Hello and welcome", COLOR_BLACK, COLOR_GREEN);
  drawString5x7(47,29, "to the", COLOR_BLACK, COLOR_GREEN);

  drawString8x12(20,45, "HOMESCREEN", COLOR_BLACK, COLOR_GREEN);

  drawString8x12(52,70, ":)", COLOR_BLACK, COLOR_GREEN);

  drawTriangle(22, 111, 45, COLOR_WHITE);
  drawString5x7(43, 148, "triangle.", COLOR_BLACK, COLOR_WHITE);
  
}
