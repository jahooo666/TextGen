#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordArray.h"

int findWord(word_t *wordArray, int arraySize, char *soughtWord){//zwraca index do tablicy slow
	int  i = 0;
	int sought =-1;
	
	while((i<arraySize)&&(sought==(-1))){
		if(strcmp(wordArray[i].text,soughtWord)==0)
			sought = i;
		i++;
	}
	
	return(sought);	
}
	
int printWordArray(word_t *wordArray, int arraySize){
	int i;
	for(i=0;i<arraySize;i++){
		printf("%s\t\t%d\n",wordArray[i].text,wordArray[i].numberOfOccurences);
		//TODO formatowanie listy slow
	}

}
