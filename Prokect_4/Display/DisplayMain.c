#include "Display.h"

void updateDisplay(u_char switch_pressed){
  init_display();
  updateLocation(switch_pressed);
}
