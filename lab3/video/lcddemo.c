#include <msp430.h>

#include "lcdutils.h"

#include "lcddraw.h"

//#include "libTimer.h"



#define FLAG_WIDTH 20 // Width of the flag

#define FLAG_HEIGHT 10 // Height of the flag

#define PYRAMID_HEIGHT 8 // Height of the pyramid

#define BRICK_WIDTH 10 // Width of each brick



// Draw a single brick at the specified position

void drawBrick(u_char col, u_char row) {

  fillRectangle(col, row, BRICK_WIDTH, 5, WHITE); // Adjust the height as needed

}



// Draw the pyramid with the specified height

void drawPyramid() {

  u_char pyramidBaseWidth = (PYRAMID_HEIGHT * BRICK_WIDTH) - 1;

  u_char pyramidBaseX = (screenWidth - pyramidBaseWidth) / 2;

  u_char pyramidY = screenHeight - BRICK_WIDTH;



  // Draw each row of the pyramid

  for (int row = 0; row < PYRAMID_HEIGHT; row++) {

    u_char bricksInRow = PYRAMID_HEIGHT - row;

    u_char startX = pyramidBaseX + (BRICK_WIDTH / 2) * row;

    for (int brick = 0; brick < bricksInRow; brick++) {

      drawBrick(startX + brick * BRICK_WIDTH, pyramidY - row * 5); // Adjust the height as needed

    }

  }

}



// Draw the flag on top of the pyramid

void drawFlag() {

  u_char flagX = (screenWidth - FLAG_WIDTH) / 2;

  u_char flagY = screenHeight - (PYRAMID_HEIGHT * 5) - FLAG_HEIGHT; // Adjust the position based on pyramid height and flag height

  fillRectangle(flagX, flagY, FLAG_WIDTH, FLAG_HEIGHT, COLOR_RED); // Example color, change as needed

}



int main() {

  // Initialize LCD

  configureClocks();

  lcd_init();



  // Clear screen

  clearScreen(BLACK);

  drawString5x7(20,20, "fuck", COLOR_WHITE, COLOR_RED);
  drawString8x12(50,50, "off", COLOR_GREEN, COLOR_RED);

  // Draw the pyramid

  drawPyramid();



  // Draw the flag

  drawFlag();



  // Update the screen

  // lcd_update();



  return 0;

}
