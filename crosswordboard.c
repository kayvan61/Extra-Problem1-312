#include"crosswordboard.h"

#ifdef _WIN32

#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable: 4996) 

#endif // win32

void initBoard(crosswordBoard* board, FILE* file)
{
	fscanf(file, "%d %d", &board->x_size, &board->y_size);
	//printf("%d %d\n", board->x_size, board->y_size);
	board->totalSize = board->x_size * board->y_size;

	board->board = malloc(board->totalSize * sizeof(char));
	if(board->board == NULL)
	{
		printf("Malloc failed. Exiting Program.");
		exit(-1);
	}
	for (int i = 0; i < board->totalSize; i++)
	{
		*(board->board + i) = fgetc(file);
		if (*(board->board + i) == ' ' || *(board->board + i) == '\n')
		{
			i--;
		}
	}
}

void destoryBoard(crosswordBoard* board)
{
	free(board->board);
	board->board = 0;
}

void printBoard(crosswordBoard* board)
{
	for (unsigned int i = 0; i < board->totalSize; i++)
	{
		printf("%c", board->board[i]);
		if (i != 0 && (i+1)% (board->y_size) == 0)
		{
			putc('\n',stdout);
		}
	}
}

void findLongest(crosswordBoard *board)
{
	char* temp = 0;
	int32_t maxlen = -1;
	int32_t curLen = 0;
	int32_t maxIndex = -1;
	int8_t print = 0;
	for (int i = 0; i < board->totalSize; i++)
	{
		if (isLetter(board->board[i]))
		{
			while (isLetter(board->board[i + (curLen * board->y_size)]))
			{
				curLen++;
			}
			if (curLen > maxlen)
			{
				maxlen = curLen;
				maxIndex = i;
			}
			curLen = 0;
		}
	}
	temp = malloc(sizeof(char) * maxlen+1);
	if(temp == NULL)
	{
		printf("Malloc Failed. Exiting program.");
		exit(-1);
	}
	temp[maxlen] = '\0';
	for (int i = 0; i < maxlen; i++)
	{
		temp[i] = board->board[maxIndex + (i * board->y_size)];
	}
	printf("%s\n", temp);

	for (int i = maxIndex+1; i < board->totalSize; i++)
	{
		if (isLetter(board->board[i]))
		{
			if (i + ((maxlen-1) * board->y_size) < board->totalSize)
			{
				print = 1;
				for (int j = 0; j < maxlen; j++)
				{
					if (!isLetter(board->board[i + (j*board->y_size)]))
					{
						print = 0;
						break;
					}
					temp[j] = board->board[i + j*board->y_size];
				}
				if (print)
				{
					printf("%s\n", temp);
				}
			}
			else
			{
				free(temp);
				return;
			}
		}
	}
	free(temp);
}

void findString(crosswordBoard* board,char* searchString)
{
	int8_t isString_h = 0;
	int8_t isString_v = 0;
	for (int i = 0; i < board->totalSize-1; i++)
	{
		if (board->board[i] == searchString[0] && board->board[i+1] != '*')
		{
			isString_h = 1;
			for (int j = 0; j < stringLen(searchString); j++)
			{
				if (board->board[i + j] != searchString[j])
				{
					isString_h = 0;
					break;
				}
			}
		}
		if (board->board[i] == searchString[0] && board->board[i + board->y_size] != '*')
		{
			isString_v = 1;
			for (int j = 0; j < stringLen(searchString); j++)
			{
				if (board->board[i + j*board->y_size] != searchString[j])
				{
					isString_v = 0;
					break;
				}
			}
		}
		if (isString_h || isString_v)
		{
			isString_h = 0;
			isString_v = 0;
			printf("%d %d\n", 1 + (i / board->y_size), (i%board->y_size) + 1);
		}
	}
}

void findSymetric(crosswordBoard *board)
{
	for (int i = 0; i < board->y_size; i++)
	{
		for (int j = 0; j < board->x_size; j++)
		{
			if (board->board[j + (i * board->y_size)] != board->board[(board->y_size - j - 1) + (i * board->y_size)] )
			{
				if((board->board[j + (i * board->y_size)] == '*'))
				{
					printf("%d %d\n", i+1, j+1);
				}
				/*else if (board->board[(board->y_size - j - 1) + (i * board->y_size)] == '*')
				{
					printf("%d %d\n", (board->y_size - j), i + 1);
				}*/
			}
		}
	}
}
