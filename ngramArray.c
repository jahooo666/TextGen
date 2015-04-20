#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "ngramArray.h"
#include "wordArray.h"



int addNgram(ngramArray_t *ngramArray, int *ngramToAdd, int lastNgram){
	int arrSize = 	ngramArray->number;
	int rng = ngramArray->ngramLevel;
	int i;
	ngramArray->tabwsk[arrSize] = (ngram_t *)malloc(sizeof(ngramArray->tabwsk[arrSize]));
	ngramArray->tabwsk[arrSize]->ngram = (int *)malloc(rng* sizeof(ngramArray->tabwsk[arrSize]->ngram));
	ngramArray->tabwsk[arrSize]->ngram = ngramToAdd;
	
	printf("wlasnie dodalem nowy ngram %d\n", ngramArray->tabwsk[arrSize]->ngram[1]);
	
	printf("\nDodalem %d ngramow sa nimi: ",ngramArray->number+1); 
	for(i=0; i<=arrSize; i++)	
	printf("%d\t",ngramArray->tabwsk[i]->ngram[1]);	 
	//if czy zostal dodany nowy czy tylko powtorzenie
	ngramArray->number++;
	printf("Zwiekszam number na: %d\n", ngramArray->number);
}


