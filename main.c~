#include "input.h"
#include "output.h"
#include "statystyka.h"
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
	//printAttributes(attributes);
	rng=attributes.ngramLevel;
	
	
	if (attributes.error == 0){
		node *root; // sadzenie drzewa na ngramy
		root = NULL;				
		readNgramsFromTextFiles( attributes.inFile, attributes.inFileNumber, &root, attributes.ngramLevel);		
		//printout(root,attributes.ngramLevel,0);		
		if(attributes.outFile==NULL)
			gener(root, attributes.ngramLevel, attributes.wordNumber);
		else
			writeTextToTextFile(attributes.outFile, root, attributes.ngramLevel, attributes.wordNumber);
		if(attributes.statistics>0)
			statystyka(root, attributes.ngramLevel,attributes.statistics);		
		//printConnections(root,attributes.ngramLevel,0);
		free(root);
					
	}
	else 
		return 0; 
	
}
