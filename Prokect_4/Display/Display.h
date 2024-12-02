#include "../../lcdLib/lcddraw.h"
#include "../../lcdLib/lcdutils.h"

#define WIDTHOFSCREEN 128
#define HEIGHTOFSCREEN 160

#define WOFFSET 4
#define HOFFSET 5
//squares should be W24, H30
//off space on side of the screen W4 H5 on each side
#define W ((WIDTHOFSCREEN-(WOFFSET * 2))/ 5)
#define H ((HEIGHTOFSCREEN -(HOFFSET * 2))/5)

#define R0 HOFFSET
#define C0 WOFFSET

#define R1 (H + HOFFSET)
#define C1 (W + WOFFSET)

#define R2 ((2 * H) + HOFFSET)
#define C2 ((2 * W) + WOFFSET)

#define R3 ((3 * H) + HOFFSET)
#define C3 ((3 * W) + WOFFSET)

#define R4 ((4 * H) + HOFFSET)
#define C4 ((4 * W) + WOFFSET)

#define PLAYERSTART_ROW R4
#define PLAYERSTART_COL C0

#define NUMBEROFBARRIERS 15

typedef unsigned char u_char;
typedef unsigned int u_int;

extern int playerCurRow;
extern int playerCurCol;

//col even indexes
//row odd indexes
extern int *BARRIER_ARRAY;
extern int colExitMaze;
extern int rowExitMaze;

extern char lastButton;
extern char total;
extern char moves;
void updateDisplay(u_char switch_pressed);
void init_display();
void updateLocation(u_char switch_pressed);
