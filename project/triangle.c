#include <lcdutils.h>
#include <lcddraw.h>


void demo()
{
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_GREEN);

  int j;
  for(j=60; j<75; j++){
    int row = j;
    for (int col = j; col <= screenWidth - j; col++)
      drawPixel(row-35, col+80, COLOR_WHITE);
  }
  drawString5x7(20,20, "Hey There Del..", COLOR_BLACK, COLOR_GREEN);

  fillRectangle(20,30,90, 90, COLOR_WHITE);
}
