#include <msp430.h>

#include "lcdutils.h"

#include "lcddraw.h"



static int squareSize = 10; // Starting size of the square

static int growthRate = 1;  // Growth rate of the square

void main(){
  animateGrowingSquare();
}


void drawSquare(int size) {

  u_char colMin = (screenWidth - size) / 2;

  u_char rowMin = (screenHeight - size) / 2;

  drawRectOutline(colMin, rowMin, size, size, WHITE);

}



void animateGrowingSquare() {

  // Initialize LCD

  configureClocks();

  lcd_init();



  // Clear screen

  clearScreen(BLACK);



  // Animation loop

  while (1) {

    // Draw the square with the current size

    drawSquare(squareSize);



    // Increase the square size

    squareSize += growthRate;



    // Refresh the screen

    lcd_update();

  }

}



void timeAdvStateMachines() {

  // No need for blinking state machine, just call to grow the square

  animateGrowingSquare();

}



void __interrupt_vec(WDT_VECTOR) WDT() {

  // Handle animations

  timeAdvStateMachines();

}

