CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: project3-demo.elf

project3-demo.elf: ${COMMON_OBJECTS} main.o buzzer.o project3demo.o state_machine2.o switches.o state_machine1.o p2_interrupt_handler.o led.o wdt_handler.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ $^ -lLcd -lTimer -lCircle 

clean:
	rm -f *.a *.o *.elf *~ *#

load: project3-demo.elf
	msp430loader.sh project3-demo.elf $^
