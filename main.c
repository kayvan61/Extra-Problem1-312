#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"crosswordboard.h"

#ifdef _WIN32

#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable: 4996) 

#endif // win32

void displayMenu();

int main()
{
	char* strToSearch = 0;
	crosswordBoard currentBoard;
	FILE *file = 0;
	char *fileName = 0;
	char userChoice = 'y';

	//get filepath from user 
	printf("Enter the path to a file with the crossword: ");
	fileName = malloc(sizeof(char) * 50);
	scanf(" %s", fileName);

	//open the file
	file = fopen(fileName, "r+");
	if (file == NULL)
	{
		printf("Failed to open the file at: %s", fileName);
	}

	initBoard(&currentBoard, file);
	printBoard(&currentBoard);
	
	strToSearch = malloc(sizeof(char) * currentBoard.totalSize);

	do {
		displayMenu(&userChoice);
		switch (userChoice)
		{
		case '1':
			findLongest(&currentBoard);
			break;
		case '2':
			printf("Enter a string to find: ");
			scanf(" %s", strToSearch);
			findString(&currentBoard, strToSearch);
			break;
		case'3':
			findSymetric(&currentBoard);
			break;
		}
		printf("Would you like to choose again?(y/n)\n");
		scanf(" %c", &userChoice);
	} while (userChoice != 'n' && userChoice != 'N');
	
	destoryBoard(&currentBoard);
	free(strToSearch);
	free(fileName);
	fclose(file);
	file = 0;

	return 0;
}

void displayMenu(char* userChoice)
{
	do {
		printf("What would you like to do?\n\
1) Find the longest vertical word\n\
2) Find the positions of a word\n\
3) Find unsymetric black squares\n");
		scanf(" %c", userChoice);
		if (*userChoice != '1' && *userChoice != '2' && *userChoice != '3')
		{
			printf("invalid character. try again.\n");
		}
	} while (*userChoice != '1' && *userChoice != '2' && *userChoice != '3');
}