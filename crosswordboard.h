#ifndef _CROSS_WORD_BOARD_H_
#define _CROSS_WORD_BOARD_H_

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"stringutil.h"

typedef struct {
	int32_t x_size;
	int32_t y_size;
	int32_t totalSize;
	char* board;
} crosswordBoard;

//creates a board at address board from the contents of file
void initBoard(crosswordBoard*, FILE*);
void destoryBoard(crosswordBoard* board);

//prints a board to the console 
void printBoard(crosswordBoard*);

//finds the longest vertical word and returns it. There may be more than one word
void findLongest(crosswordBoard*);

//find the position of a word given by the user
void findString(crosswordBoard*, char*);

//find non-symatric black squares 
void findSymetric(crosswordBoard*);

#endif // !_CROSS_WORD_PUZZLE_H_