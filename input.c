#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "wordArray.h"
//#include "ngramArray.h"

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




word_t *readWordsFromTextFiles( char **fileName, int fileNumber, int totalWordNumber){
	word_t *wordArray;
	wordArray = malloc(totalWordNumber*sizeof(word_t));
	int i,j;
	j=0;
	
	
	for(i=1; i<fileNumber; i++){
		FILE *textFile;
		char buffer[255];
		textFile = fopen(fileName[i],"r");
		while(fscanf(textFile,"%s",buffer)!= EOF){	
			wordArray[j].text = malloc(255*sizeof(char));
			printf("%s-\t",buffer);
			wordArray[j].text = buffer;
			j++;
		}
	}
//TODO trzeba poprawic cale to budowanie tablicy te wszystkie 255, powinno sie to jakos zainicjowac moze.-> jak najszybciej	
	
	return wordArray;
}


int main(int argc, char **argv){
	int i;
	int totalWordNumber = 0; 
	
	
	for(i=1; i<argc; i++){
		totalWordNumber += countWordsInText(argv[i]);
	}
	
	printf("calkowita liczba slow we wszystkich plikach to: %d\n",totalWordNumber);
	word_t *wordArray;
	wordArray = malloc(totalWordNumber*sizeof(word_t));
	wordArray = readWordsFromTextFiles(argv,argc,totalWordNumber);
	for(i=0;i<totalWordNumber;i++)
		printf("%s\n",wordArray[i].text);
	
}

//ngramElem *readDataFromBaseFile( char *fileName);

