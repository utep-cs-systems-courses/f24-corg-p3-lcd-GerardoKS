#include <stdlib.h>
#include <stdio.h>

#include "../../lcdLib/lcddraw.h"
#include "../../lcdLib/lcdutils.h"
#include "Display.h"

int numOfBarriers;
int *BARRIER_ARRAY = NULL;
int currentIndex = 0;
int colExitMaze;
int rowExitMaze;

void declareBARRIER_ARRAY(){
  if (BARRIER_ARRAY == NULL) {
    BARRIER_ARRAY = (int *)calloc(NUMBEROFBARRIERS, sizeof(int));
    if (BARRIER_ARRAY == NULL) {
      printf("Memory allocation failed\n");
      exit(1);
    }
  }
}
void init_display(){
  clearScreen(COLOR_BLACK);
  drawRectOutline(C0,R0, W -1, H -1, COLOR_RED);
  drawRectOutline(C1,R0, W -1, H -1, COLOR_RED);
  drawRectOutline(C2,R0, W -1, H -1, COLOR_RED);
  drawRectOutline(C3,R0, W -1, H -1, COLOR_RED);
  //drawRectOutline(C4,R0, W -1, H -1, COLOR_BLACK);
  fillRectangle(C4,R0, W -1, H -1, COLOR_RED);
  BARRIER_ARRAY[0] = C4;
  BARRIER_ARRAY[1] = R0; 
  drawRectOutline(C0,R1, W -1, H -1, COLOR_RED);
  //drawRectOutline(C1,R1, W -1, H -1, COLOR_BLACK);
  fillRectangle(C1,R1, W -1, H -1, COLOR_RED);
  BARRIER_ARRAY[2] = C1;
  BARRIER_ARRAY[3] = R1;
  //drawRectOutline(C2,R1, W -1, H -1, COLOR_BLACK);
  fillRectangle(C2,R1, W -1, H -1, COLOR_RED);
  BARRIER_ARRAY[4] = C2;
  BARRIER_ARRAY[5] = R1;
  drawRectOutline(C3,R1, W -1, H -1, COLOR_RED);
  drawRectOutline(C4,R1, W -1, H -1, COLOR_RED);
  drawRectOutline(C0,R2, W -1, H -1, COLOR_RED);
  drawRectOutline(C1,R2, W -1, H -1, COLOR_RED);
  drawRectOutline(C2,R2, W -1, H -1, COLOR_RED);
  //drawRectOutline(C3,R2, W -1, H -1, COLOR_BLACK);
  fillRectangle(C3,R2, W -1, H -1, COLOR_RED);
  BARRIER_ARRAY[6] = C3;
  BARRIER_ARRAY[7] = R2;
  drawRectOutline(C4,R2, W -1, H -1, COLOR_RED);
  drawRectOutline(C0,R3, W -1, H -1, COLOR_RED);
  //drawRectOutline(C1,R3, W -1, H -1, COLOR_BLACK);
  fillRectangle(C1,R3, W -1, H -1, COLOR_RED);
  BARRIER_ARRAY[8] = C1;
  BARRIER_ARRAY[9] = R3;
  //drawRectOutline(C2,R3, W -1, H -1, COLOR_BLACK);
  fillRectangle(C2,R3, W -1, H -1, COLOR_RED);
  BARRIER_ARRAY[10] = C2;
  BARRIER_ARRAY[11] = R3;
  drawRectOutline(C3,R3, W -1, H -1, COLOR_RED);
  drawRectOutline(C4,R3, W -1, H -1, COLOR_RED);
  drawRectOutline(C0,R4, W -1, H -1, COLOR_RED);
  //drawRectOutline(C1,R4, W -1 , H, COLOR_BLACK);
  fillRectangle(C1,R4, W -1, H -1, COLOR_RED);
  BARRIER_ARRAY[12] = C1;
  BARRIER_ARRAY[13] = R4;
  fillRectangle(C2,R4, W -1, H -1, COLOR_DEEP);
  colExitMaze = C2;
  rowExitMaze = R4;
  drawRectOutline(C2,R4, W -1, H -1, COLOR_BLACK);
  drawRectOutline(C3,R4, W -1, H -1, COLOR_RED);
  //drawRectOutline(C4,R4, W -1, H -1, COLOR_BLACK);
  fillRectangle(C4,R4, W -1, H -1, COLOR_RED);
  BARRIER_ARRAY[14] = C4;
  BARRIER_ARRAY[15] = R4;
}
