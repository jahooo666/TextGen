#include "input.h"
//#include "output.h"
//#include "ngramArray.h"
#include "wordArray.h"
#include "attributes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
word_t *wordArray; 



int main(int argc, char **argv){
	attributes_t attributes;
	attributes = readAttributes(argc, argv);
	
	if (attributes.error == 0){
		//printAttributes(attributes);
		
		int wordNumber = countWordsInTextFiles( attributes.inFile,attributes.inFileNumber+1);	
		printf("Liczba slow z maina to : %d\n",wordNumber);
		wordArray = malloc(wordNumber*(sizeof(word_t)));
		int newWordNumber=readWordsFromTextFiles( attributes.inFile,attributes.inFileNumber+1, wordArray);
		printf("Liczba nowych slow z maina to : %d\n",newWordNumber);
		word_t newWord;
		newWord = wordArray[0];
		//printf("Jestem tutaj, a 1 element tablicy to: %s\n",newWord.text);
		if(wordNumber > 0){
			int error = printWordArray(wordArray, wordNumber);
		
		
		
		}
		else return 0;
					
	}
	else 
		return 0; 
	
}
