#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include "project3demo.h"

void project_3_demo()
{
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_GRAY);  
  
  drawString5x7(6,15, "Hello friendly user,", COLOR_BLACK, COLOR_GRAY);
  drawString5x7(17,29, "Press 1 to start", COLOR_BLACK, COLOR_GRAY);
                                   
  drawString8x12(20,height/2, "Go ahead:)", COLOR_BLACK, COLOR_GRAY);

  drawTriangle(22, 111, 45, COLOR_WHITE);
  drawString5x7(43, 148, "triangle.", COLOR_BLACK, COLOR_WHITE);
  
}
