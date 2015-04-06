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




int readWordsFromTextFiles( char **fileName, int fileNumber, int totalWordNumber, word_t* wordArray){
	//word_t wordArray[totalWordNumber];
	//wordArray = malloc(totalWordNumber*sizeof(word_t));
	int i,j;
	j=0;
	
	
	for(i=1; i<fileNumber; i++){
		FILE *textFile;
		//char buffer[255];
		textFile = fopen(fileName[i],"r");
		word_t newWord;
		while(fscanf(textFile,"%s",newWord.text)!= EOF){	
			
			//newWord.text = buffer;
			//printf("%s-\t",buffer);
			newWord.numberOfOccurences = j;	
			wordArray[j] = newWord;
			j++;
		}
	}
//TODO trzeba poprawic cale to budowanie tablicy te wszystkie 255, powinno sie to jakos zainicjowac moze.-> jak najszybciej	
	
	return 1;
}


int main(int argc, char **argv){
	int i,j;
	int totalWordNumber = 0; 
	
	
	for(i=1; i<argc; i++){
		totalWordNumber += countWordsInText(argv[i]);
	}
	
	printf("calkowita liczba slow we wszystkich plikach to: %d\n",totalWordNumber);
	word_t *wordArray;
	//char *sloowo = "lol";
	wordArray = malloc(totalWordNumber*sizeof(word_t));
	for(i=0;i<totalWordNumber;i++){
		word_t newWord;
		
		newWord.numberOfOccurences =12;
		wordArray[i] = newWord; 
		printf("%s----%d\n",newWord.text,newWord.numberOfOccurences);
	}
	
	
	int error = readWordsFromTextFiles(argv,argc,totalWordNumber,wordArray);
	
	
	
	
	for(i=0;i<totalWordNumber;i++){
		word_t newWord = wordArray[i]; 
		printf("%s----%d\n",newWord.text,newWord.numberOfOccurences);
	}
}

//ngramElem *readDataFromBaseFile( char *fileName);

