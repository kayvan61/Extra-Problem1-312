#include"stringutil.h"

int isLetter(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int stringLen(char *str)
{
	int32_t counter = 0;
	while (str[++counter] != '\0');
	return counter;
}
