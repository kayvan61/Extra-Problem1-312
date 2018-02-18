#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"crosswordboard.h"

#ifdef _WIN32

#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable: 4996) 

#endif // win32

void displayMenu();
void runTests();

int main()
{
	char* strToSearch = 0;
	crosswordBoard currentBoard;
	FILE *file = 0;
	char *fileName = 0;
	char userChoice = 'y';
	int8_t isTests = 1;
	char *testString = "tests";

	//get filepath from user 
	printf("Type 'tests' to run tests.\n");
	printf("Enter the path to a file with the crossword: ");
	fileName = malloc(sizeof(char) * 50);
	if(fileName == NULL)
	{
		printf("Malloc failed. Exiting program.");
		return -1;
	}
	scanf(" %s", fileName);

	for(int i = 0; i < 5; i++)
	{
		if(fileName[i] != testString[i])
		{
			isTests = 0;
			break;
		}
	}
	if(isTests)
	{
		runTests();
		free(fileName);
		return 0;
	}

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

void runTests()
{
	crosswordBoard testBoard;
	FILE* file = 0;
	char* stringToFind;

	//TEST 1
	printf("----------STARTING TEST1---------\n\n");
	file = fopen("test1", "r+");
	if(file == NULL)
	{
		printf("failed to open file for test1\n\n");
	}
	initBoard(&testBoard, file);
	stringToFind = malloc(sizeof(char) * testBoard.totalSize);
	if(stringToFind == NULL)
	{
		printf("Malloc failed. exiting program.");
		exit(-1);
	}
	printBoard(&testBoard);
	printf("\n\nFinding longest vertical word:\n\n");
	findLongest(&testBoard);
	printf("\n\nFinding user string:\n\n");
	printf("enter a string to find: ");
	scanf(" %s", stringToFind);
	findString(&testBoard, stringToFind);
	findSymetric(&testBoard);

	destoryBoard(&testBoard);
	free(stringToFind);
	fclose(file);
		
	printf("----------END OF TEST1----------\n\n");
        
        printf("----------STARTING TEST2---------\n\n");
	file = fopen("test2", "r+");
	if(file == NULL)
	{
		printf("failed to open file for test2\n\n");
	}
	initBoard(&testBoard, file);
	stringToFind = malloc(sizeof(char) * testBoard.totalSize);
	if(stringToFind == NULL)
	{
		printf("Malloc failed. exiting program.");
		exit(-1);
	}
	printBoard(&testBoard);
	printf("\n\nFinding longest vertical word:\n\n");
	findLongest(&testBoard);
	printf("\n\nFinding user string:\n\n");
	printf("enter a string to find: ");
	scanf(" %s", stringToFind);
	findString(&testBoard, stringToFind);
	findSymetric(&testBoard);
	
	destoryBoard(&testBoard);
	free(stringToFind);
	fclose(file);
		
	printf("----------END OF TEST2----------\n\n");
	
	printf("----------STARTING TEST3---------\n\n");
	file = fopen("test3", "r+");
	if(file == NULL)
	{
		printf("failed to open file for test3\n\n");
	}
	initBoard(&testBoard, file);
	stringToFind = malloc(sizeof(char) * testBoard.totalSize);
	if(stringToFind == NULL)
	{
		printf("Malloc failed. exiting program.");
		exit(-1);
	}
	printBoard(&testBoard);
	printf("\n\nFinding longest vertical word:\n\n");
	findLongest(&testBoard);
	printf("\n\nFinding user string:\n\n");
	printf("enter a string to find: ");
	scanf(" %s", stringToFind);
	findString(&testBoard, stringToFind);
	findSymetric(&testBoard);
	
	destoryBoard(&testBoard);
	free(stringToFind);
	fclose(file);
		
	printf("----------END OF TEST3----------\n\n");
	printf("----------STARTING TEST4---------\n\n");
	file = fopen("test4", "r+");
	if(file == NULL)
	{
		printf("failed to open file for test4\n\n");
	}
	initBoard(&testBoard, file);
	stringToFind = malloc(sizeof(char) * testBoard.totalSize);
	if(stringToFind == NULL)
	{
		printf("Malloc failed. exiting program.");
		exit(-1);
	}
	printBoard(&testBoard);
	printf("\n\nFinding longest vertical word:\n\n");
	findLongest(&testBoard);
	printf("\n\nFinding user string:\n\n");
	printf("enter a string to find: ");
	scanf(" %s", stringToFind);
	findString(&testBoard, stringToFind);
	findSymetric(&testBoard);
	
	destoryBoard(&testBoard);
	free(stringToFind);
	fclose(file);
		
	printf("----------END OF TEST4----------\n\n");
}
