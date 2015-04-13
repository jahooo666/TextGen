#ifndef NGRAMARRAY_H
#define NGRAMARRAY_H

#include <stdio.h>


typedef struct {
	int nextNgram;			//index z tablicy ngramow
	int numberOfCollocations;//ile razy ten zwiazek sie powtorzyl
}next_t;


typedef struct {
	int *ngram;//tablica indexow z tablicy slow
	int numberOfOccurences;
	double pmi;
	next_t nextArray[100];	// docelowo tu ma byc *
	int nextNumber;
}ngram_t;



int findNgram(ngram_t *ngramArray, int arraySize, int ngramLevel, int *soughtNgram); //tablica intow jako ostatni argument jest specjalnie- patrz struktura. zwraca inta- index w tablicy ngramow
int findNext(ngram_t ngramElem, int nextNgramIndex); // jw
int addNgram(ngram_t *ngramArray, int arraySize, int ngramLevel, int *ngramToAdd, int lastNgram);

#endif
