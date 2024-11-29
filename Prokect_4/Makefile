# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as


all: Project4.elf

#additional rules for files
Project4.elf: ${COMMON_OBJECTS} GameMain.o Display/DisplayMain.o Display/SetUpDisplay.o Display/Person.o ../lcdLib/lcddraw.o ../lcdLib/lcdutils.o ../lcdLib/font-5x7.o ../timerLib/sr.o ../timerLib/clocksTimer.o msquares.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: Project4.elf
	msp430loader.sh Project4.elf

clean:
	rm -f *.o *.elf
	rm -f Display/*.o *.elf
	rm -f Display/lcdLib/*.o *.elf

#Main
GameMain.o: GameMain.c Display/Display.h ../lcdLib/lcddraw.h ../lcdLib/lcdutils.h ../../corgProjectTwo/f24-corg-p2-GerardoKS/demos/timerLib/libTimer.h ../msquares/msquares.h
#Display
DisplayMain.o: Display/DisplayMain.c Display/Display.h 

SetUpDisplay.o: Display/SetUpDisplay.c Display/Display.h ../h/lcddraw.h ../lcdLib/lcdutils.h

msquares.o : msquares.c ../msquares/msquares.h Display/Display.h

Person.o: Display/Person.c Display/Display.h ../lcdLib/lcddraw.h ../lcdLib/lcdutils.h
