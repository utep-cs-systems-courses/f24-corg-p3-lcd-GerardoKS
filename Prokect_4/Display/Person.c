#include "Display.h"
#include "../../timerLib/libTimer.h"
#include "../../lcdLib/lcddraw.h"
#include "../../lcdLib/lcdutils.h"
#include <msp430.h>

#define LED (BIT0 | BIT6)
void updateLocation(u_char switch_pressed){
  u_char redrawPlacement = 1;
  u_char updateCol = 0;
  u_char updateRow = 0;
  if(switch_pressed > -2 && switch_pressed < 4){
    if(switch_pressed == 0){
      updateCol = W * -1;
      updateRow = 0;
    }
    else if(switch_pressed == 1){
      updateCol = 0;
      updateRow = H * -1;
    }
    else if(switch_pressed == 2){
      updateCol = 0;
      updateRow = H;
    }
    else if(switch_pressed == 3){
      updateCol = W;
      updateRow = 0;
    }
    else if(switch_pressed == -1)
      redrawPlacement = 1;
  
    if((playerCurCol + updateCol) > WIDTHOFSCREEN - WOFFSET || (playerCurCol+ updateCol) <= WOFFSET || (playerCurRow + updateCol) > HEIGHTOFSCREEN || (playerCurRow + updateCol) <= HOFFSET){
      P1OUT |= BIT0;
      updateCol = 0;
      updateRow = 0;
      redrawPlacement = 0;
      //play sound
    }
    int* barrierPointer = BARRIER_ARRAY;
    for(int i = 0; i < NUMBEROFBARRIERS; i+= 2){
      if(barrierPointer[i] == playerCurCol && barrierPointer[i + 1] == playerCurRow){
	playerCurCol -= updateCol;
	playerCurRow -= updateRow;
	P1OUT |= BIT6;
	redrawPlacement = 0;
      }
    }

    playerCurCol += updateCol;
    playerCurRow += updateRow;

     
    if(redrawPlacement){
      P1OUT |= LED;
      if(playerCurCol == colExitMaze && playerCurRow == rowExitMaze){
	//end
	clearScreen(COLOR_BLACK);
      }
      configureClocks();
      fillRectangle(playerCurCol, (playerCurRow - updateRow), W, H, COLOR_BLACK);
      drawRectOutline(playerCurCol,(playerCurRow - updateCol), W -1, H -1, COLOR_RED);      
      fillRectangle(playerCurCol, playerCurRow, W, H, COLOR_WHITE);
      enableWDTInterrupts();
      switch_pressed = 0;
    }
  }
}
 
