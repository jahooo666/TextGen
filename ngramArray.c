#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "ngramArray.h"
#include "wordArray.h"

int findNgram(ngram_t *ngramArray, int arraySize, int ngramLevel, int *soughtNgram){ //tablica intow jako ostatni argument jest specjalnie- patrz struktura
	//zwraca index z tablicy ngramow lub (-1) jezeli nie znalazl niczego
	
	int  i = 0;
	int j;
	int sought =-1;
	int equal;
	while((i<arraySize)&&(sought==(-1))){
		ngram_t newNgram=ngramArray[i];
		int equal=1;	//zmienna sluzy do sprawdzenia czy wszystkie przeiterowane indexy sa rowne- domyslnie jeden, 
		for (j=0;j<ngramLevel;j++){
			if(newNgram.ngram[j]!=soughtNgram[j])
				equal=0;					//jak ktorykolwiek jest rozny, zmieniamy na zero
		}
		if(equal==1)
			sought = i;					//jezeli wytrwalo 1 to znaczy ze caly ngram jest taki sam
		i++;
	}
	
	return(sought);						//zwracamy index z ngram Array
		
}
int findNext(ngram_t ngramElem, int nextNgramIndex){
	int i;
	int foundNext = -1;
	if(ngramElem.nextNumber!=0){
		for(i=0;i<ngramElem.nextNumber;i++){
			if((ngramElem.nextArray[i].nextNgram)==nextNgramIndex)
				foundNext= nextNgramIndex;
		}
	}
	return(foundNext);
}


