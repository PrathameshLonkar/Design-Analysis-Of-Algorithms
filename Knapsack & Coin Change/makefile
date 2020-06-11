CC=gcc
CFLAGS=-Wall -pedantic

all: programs

programs:
	$(CC) -c knapsack.c -o knapsack.o
	$(CC) -o coin_change coin_change.c -lm
	$(CC) -c coin_change_nk.c -o coin_change_nk.o
	$(CC) knapsack.o -o knapsack
	$(CC) coin_change_nk.o -o coin_change_nk
	


clean:
	rm knapsack coin_change coin_change_nk *.o
