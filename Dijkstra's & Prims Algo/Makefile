CC=gcc
CFLAGS=-Wall -pedantic

all: programs

programs:
	$(CC) -c Dijsktras.c -o Dijsktras.o
	$(CC) -c prims.c -o prims.o
	$(CC) Dijsktras.o -o Dijsktras
	$(CC) prims.o -o prims
	


clean:
	rm Dijsktras prims *.o
