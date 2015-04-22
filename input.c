#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "wordArray.h"
#include "./ngramTree/tree.h"

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

int readNgramsFromTextFiles( char **fileName, int fileNumber, node **root, int rng){
	int i,f;
	char **wArray=(char **)malloc(rng*sizeof(char *));
	char *buffer = (char *)malloc(100*sizeof(char));
	node *last;
	
	//char bufer[255];	
	
	for(f=0;f<fileNumber;f++){
		//teraz wczytam pierwsze rng ngramow do tablicy bufforowej i postaram sie ja wrzucic do drzewa
		FILE *textFile = fopen(fileName[f],"r");
		i=0;
		
		while((fscanf(textFile,"%s",buffer)!= EOF)&&(i<rng)){
			wArray[i]=(char *)malloc(100*sizeof(char));
			strcpy(wArray[i],buffer);			
			i++;
		}	
			last = add(&(*root), wArray ,rng, NULL); 	//dodajemy tylko pierwszy ngram
			
		while(fscanf(textFile,"%s",buffer)!= EOF){
			for(i=0;i<(rng-1);i++){
				strcpy(wArray[i],wArray[i+1]);	//przesuwam wszystkie o jeden w lewo
			}
			strcpy(wArray[rng-1],buffer);			//dodaje ostatni element ngramu				
			last = add(root, wArray ,rng, last);		//dodajemy kazdy ngram po koleii
			
		}
	}
	
};

	
