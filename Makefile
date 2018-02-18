CC=gcc
CFLAGS=-I.

makeSol:
	$(CC) -o solution main.c crosswordboard.c stringutil.c $(CFLAGS)
