#include "../timerLib/libTimer.h"
#include "../lcdLib/lcdutils.h"
#include "../lcdLib/lcddraw.h"
#include "Display/Display.h"
#include "../msquares/msquares.h"
#include "Sound/SoundSetUp.h"
#include <msp430.h>
int redrawScreen = 0;
char current_position = 0;

int playerCurCol = PLAYERSTART_COL;
int playerCurRow = PLAYERSTART_ROW;
 
void main(){
  P1DIR |= LED;
  P1OUT &= ~LED;
  switch_init();
  sound_init();
  configureClocks();/* setup master oscillator, CPU & peripheral clocks */
  lcd_init();
  init_display();
  //updateDisplay(-1);
  
  enableWDTInterrupts();/* enable periodic interrupt */
  
  //backround and bariers and goal
  //person
  or_sr(0x18);
}
static int P2buttonDown;
static char buttonPressed;
char total = 0;
char moves = 17;
void switch_interrupt_handler()
{
  char p2val = P2IN;/* switch is in P2 */
  buttonPressed = p2val;
  /* update switch interrupt sense to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */

  if (p2val & SWITCHES) {/* button up */
    current_position = p2val;
    P2buttonDown = 0;
    total += p2val;
    moves --;
  } else {/* button down */
    current_position = p2val;
    P2buttonDown = 1;
  }
}



/* Switch on S2 */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    //switch_interrupt_handler();	/* single handler for all switches */
    if(P2IN & 1)
      total += 1;
    else if(P2IN & 2)
      total += 2;
    else if(P2IN & 4)
      total += 3;
    else if(P2IN & 8)
      total += 4;
    moves --;
  }
}
 
  //wdt 
     //move person based on switch pressed 
       //check valid path
       //play stuck sound if not
       // else play move sound
    //Check if in final
    // play song
    // blinky lights
char lastButton = 4;
int count = 0;
void __interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  /*if(lastButton != 4){  
    if (!P2buttonDown) {
      clearScreen(COLOR_BLACK);
      redrawScreen = 0;
      updateLocation(current_position);
    } 
    }*/
  if( count == 1250){
    clearScreen(COLOR_BLACK);
  }
  count ++;
  if( moves == 0 && total == 21){
    set_period(15000);
    clearScreen(COLOR_DARK_GREEN);
    drawChar5x7(C1, R3, 0x57, COLOR_WHITE, COLOR_DARK_GREEN);
    drawChar5x7(C2, R3, 0x49, COLOR_WHITE, COLOR_DARK_GREEN);
    drawChar5x7(C3, R3, 0x4e, COLOR_WHITE, COLOR_DARK_GREEN);
    
  }
  else if(moves == 0){
    set_period(300);
    clearScreen(COLOR_RED);
    drawChar5x7(C0, R3, 0x4c, COLOR_WHITE, COLOR_RED);
    drawChar5x7(C1, R3, 0x4f, COLOR_WHITE, COLOR_RED);
    drawChar5x7(C2, R3, 0x53, COLOR_WHITE, COLOR_RED);
    drawChar5x7(C3, R3, 0x45, COLOR_WHITE, COLOR_RED);
    drawChar5x7(C4, R3, 0x21, COLOR_WHITE, COLOR_RED);
  }
}
