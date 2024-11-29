#include "../../corgProjectTwo/f24-corg-p2-GerardoKS/demos/timerLib/libTimer.h"
#include "../lcdLib/lcdutils.h"
#include "../lcdLib/lcddraw.h"
#include "Display/Display.h"
#include "../msquares/msquares.h"
#include <msp430.h>
int redrawScreen = 0;
char current_position = 0;

int playerCurCol = PLAYERSTART_COL;
int playerCurRow = PLAYERSTART_ROW;
 
void main(){
  P1DIR |= LED;
  P1OUT &= ~LED;
  switch_init();
  configureClocks();/* setup master oscillator, CPU & peripheral clocks */
  lcd_init();
  updateLocation(-1);
  enableWDTInterrupts();/* enable periodic interrupt */
  
  //backround and bariers and goal
  //person
  or_sr(0x18);
}
static int P2buttonDown;
static char buttonPressed;
void switchP2_interrupt_handler()
{
  char p2val = P2IN;/* switch is in P2 */
  buttonPressed = p2val;
  /* update switch interrupt sense to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */

  if (p2val & SWITCHES) {/* button up */
    current_position = p2val;
    P2buttonDown = 0;
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
    switch_interrupt_handler();	/* single handler for all switches */
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
static char start = 0;
static char lastButton = -1;
void __interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  if(lastButton != current_position){
    lastButton = current_position;
    if(current_position == 3){
      start ++;
    }
    if(start){  
      if (!P2buttonDown) {
	redrawScreen = 0;
	updateLocation(current_position);
      }
    } 
  }
}
