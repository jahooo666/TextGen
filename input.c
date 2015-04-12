#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "wordArray.h"
#include "ngramArray.h"

int countWordsInText( char *fileName){
	FILE *textFile;
	char slowo[255];
	int wordNumber = 0;

	textFile = fopen(fileName,"r");
	
	while(fscanf(textFile,"%s",slowo)!= EOF)
		wordNumber++;
	
	printf("Liczba slow to: %d\n", wordNumber);
	return wordNumber;
}


int countWordsInTextFiles( char **fileName, int fileNumber){
	int totalWordNumber = 0; 
	int i;
	for(i=0; i<fileNumber; i++){
		totalWordNumber += countWordsInText(fileName[i]);
	}
	printf("Liczba slow we wszystkich plikach to: = %d\n",totalWordNumber);
	return totalWordNumber;
}


int readWordsFromTextFiles( char **fileName, int fileNumber, word_t *wordArray){
	int i,j,ind;
	j = 0;//takie i dla niepowtarzalnych slow
	int totalWordNumber = 0; 
	int newTotalWordNumber = 0; 
	
	for(i=0; i<fileNumber; i++){
		FILE *textFile = fopen(fileName[i],"r");
		word_t newWord;
		while(fscanf(textFile,"%s",newWord.text)!= EOF){	
			ind = findWord(wordArray,j,newWord.text);
			if(ind != (-1)){			
				wordArray[ind].numberOfOccurences++;
			}
			else{
				newWord.numberOfOccurences = 1;
				wordArray[j] = newWord;
				j++;
			}
		}fclose(textFile);
	}
	
	return j;
	
}

int readNgramsFromTextFiles( char **fileName, int fileNumber, ngram_t *ngramArray, int ngramLevel, word_t *wordArray, int wordArraySize){
	
	int i,j,k;
	int currentNgramArrayPosition = 0; 
	int first,last; 				//indexy do przechodzenia po tablicy 
	char buffer[255];
	FILE *textFile;
	ngram_t newNgram;
	
	int foundPosition;
	int foundNext;
	int lastNgramIndex; //<- index ostatnio uzywanego ngramu uzywany do laczenia ngramow
	int wordsInText;
	int temp;
	int tempWordIndexArray[ngramLevel];
	int newtempWordIndexArray[ngramLevel];
	for(i=0; i<fileNumber; i++){
		wordsInText = countWordsInText(fileName[i]);		
		if( wordsInText >= ngramLevel ){		
			FILE *textFile = fopen(fileName[i],"r");
			
			
			fclose(textFile);
		}
		else printf("Plik %s ma za malo slow- nie jest brany pod uwage przy tworzeniu ngramow",fileName[i]);	
	
	}
	
return currentNgramArrayPosition;	
}

//TODO obsluga bledow

/*
newTotalWordNumber = readWordsFromTextFiles(argv,argc,totalWordNumber,wordArray);
	int error = printWordArray(wordArray, newTotalWordNumber);
*/
//ngramElem *readDataFromBaseFile( char *fileName);

