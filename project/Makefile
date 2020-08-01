all: project3-demo.elf

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as 
AR              = msp430-elf-ar

project3-demo.elf: ${COMMON_OBJECTS} main.o buzzer.o project3demo.o state_machine2.o led.o switches.o switches.o p2_interrupt_handler.o state_machine1.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ $^ -lLcd -lp2sw -lTimer -lShape -lCircle 

clean:
	rm -f *.a *.o *.elf *~ *#

load: project3-demo.elf
	msp430loader.sh project3-demo.elf $^

#lcddraw.o:lcddraw.c lcddraw.h lcdutils.h

#lcdutils.o: lcdutils.c lcdutils.h

