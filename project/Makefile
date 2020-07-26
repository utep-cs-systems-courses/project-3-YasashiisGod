CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as 
AR              = msp430-elf-ar

all: project3-demo.elf

project3-demo.elf: ${COMMON_OBJECTS} main.o buzzer.o led.o triangle.c
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ $^ -lLcd -lp2sw -lTimer -lShape -lCircle 

clean:
	rm -f *.a *.o *.elf *~ *#

load: project3-demo.elf
	msp430loader.sh project3-demo.elf

#lcddraw.o:lcddraw.c lcddraw.h lcdutils.h

#lcdutils.o: lcdutils.c lcdutils.h

