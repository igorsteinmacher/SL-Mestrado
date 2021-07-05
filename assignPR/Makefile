CC = gcc
CFLAGS = -g -w -Wall
LM = -lm
.PHONY: all

all:
	compile run

run:
	./main

compile:	
	$(CC) $(CFLAGS) entrada.c -c -o entrada.o
	$(CC) $(CFLAGS) featureMantissa.c -c -o featureMantissa.o $(LM)
	$(CC) $(CFLAGS) main.c -o main entrada.o featureMantissa.o $(LM)

test:
	$(CC) $(CFLAGS) entrada.c -c -o entrada.o
	$(CC) $(CFLAGS) featureMantissa.c -c -o featureMantissa.o $(LM)
	$(CC) $(CFLAGS) test.c -o teste featureMantissa.o entrada.o $(LM)

clear:
	rm -f *.o