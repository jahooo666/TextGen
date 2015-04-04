#ifndef WORDARRAY_H
#define WORDARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	char *text;
	int numberOfOccurences;

}word_t;

int createWord(char* newWord);
word_t* findWord(word_t *wordArray, char *soughtWord);
void addOccurence(wordt_t word);

	

#endif
