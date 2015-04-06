#ifndef WORDARRAY_H
#define WORDARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	char text[255]; //pojedyncze slowo moze miec maksymalnie 255 liter
	int numberOfOccurences;

}word_t;
int findWord(word_t *wordArray,int arraySize, char *soughtWord);
 //zwraca index pierwszego elementu z takim samm tekstem

	

#endif
