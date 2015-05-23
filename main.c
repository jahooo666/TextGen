#include "input.h"
//#include "output.h"
#include "./ngramTree/tree.h"
#include "wordArray.h"
#include "attributes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
word_t *wordArray;

int rng; 



int main(int argc, char **argv){
	int i;
	attributes_t attributes;
	attributes = readAttributes(argc, argv);
	rng=attributes.ngramLevel;
	if (attributes.error == 0){
		//printAttributes(attributes);
		
		int wordNumber = countWordsInTextFiles( attributes.inFile,attributes.inFileNumber+1);	
		printf("Liczba slow z maina to : %d\n",wordNumber);
		wordArray = malloc(wordNumber*(sizeof(word_t)));
		//int newWordNumber=readWordsFromTextFiles( attributes.inFile,attributes.inFileNumber+1, wordArray);
		//printf("Liczba nowych slow z maina to : %d\n",newWordNumber);
		
		if(wordNumber > 0){
		node *root; // sadzenie drzewa na ngramy
		root = NULL;
		readNgramsFromTextFiles( attributes.inFile, attributes.inFileNumber+1, &root, attributes.ngramLevel);		
		printout(root,attributes.ngramLevel,0);		
		//gener(root, 2, 5);
		free(root);
		}
		else return 0;
					
	}
	else 
		return 0; 
	
}
