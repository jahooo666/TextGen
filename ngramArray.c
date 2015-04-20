#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "ngramArray.h"
#include "wordArray.h"



int addNgram(ngramArray_t *ngramArray, int *ngramToAdd, int lastNgram){
	int arrSize = 	ngramArray->number;
	int rng = ngramArray->ngramLevel;
	ngramArray->tabwsk[arrSize] = (ngram_t *)malloc(sizeof(ngram_t));
	ngramArray->tabwsk[arrSize]->ngram = (int *)malloc(rng* sizeof(int));
	ngramArray->tabwsk[arrSize]->ngram = ngramToAdd;
	printf("wlasnie dodalem nowy ngram %d\n", ngramArray->tabwsk[arrSize]->ngram[1]);
		 
	//if czy zostal dodany nowy czy tylko powtorzenie
	ngramArray->number++;
	printf("Zwiekszam number na: %d\n", ngramArray->number);
}


