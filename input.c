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

int readNgramsFromTextFiles( char **fileName, int fileNumber, ngramArray_t *ngramArray, word_t *wordArray, int wordArraySize){
	int newNgram[4];
	int i;
	
	for(i=0; i<(ngramArray->ngramLevel); i++)
		newNgram[i] = i;
	addNgram(&(*ngramArray), newNgram, 0);
	for(i=0; i<(ngramArray->ngramLevel); i++)
		newNgram[i] = 2*i;
	addNgram(&(*ngramArray), newNgram, 0);
	for(i=0; i<(ngramArray->ngramLevel); i++)
		newNgram[i] = 3*i;
	addNgram(&(*ngramArray), newNgram, 0);
	
	printf("Dodalem %d ngramow sa nimi: %d, %d, %d \n",ngramArray->number, 
											ngramArray->tabwsk[0]->ngram[1], 
											ngramArray->tabwsk[1]->ngram[1],
											ngramArray->tabwsk[2]->ngram[1]  );
	//przechodzenie przez wszystkie pliki i po koleii dodawanie do tablicy ngramow
};

	
