CC=gcc
CFLAGS=-Wall -pedantic

all: programs

programs:
	$(CC) -c problem1.c -o problem1.o
	$(CC) -c problem2.c -o problem2.o
	$(CC) -c problem3.c -o problem3.o
	$(CC) problem1.o -o problem1
	$(CC) problem2.o -o problem2
	$(CC) problem3.o -o problem3
	


clean:
	rm problem1 problem2 problem3 *.o
