#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./ngramTree/tree.h"
#include "gener.h"

void gener(node * tree, int rng, int ls){
// ls -liczba slow do wygenerowania
	int i,j;	
	i=0;
	printf("Drukuje ngram %d rzedu\n",rng);
	//drukowanie wszystkich wyrazow pierwszego ngramu
	for(j=0;j<rng;j++)
			printf("%s ",tree->wArray[j]);
	tree = (tree->nextArray)[tree->nextNumber-1].nextEl;
	
	//drukowanie pojedynczego(ostatniego) slowa kolejnego ngramu i przesuwanie wskaznika na nastepny element	
	while(tree && i<ls){		
		printf("%s ",tree->wArray[rng-1]);
		
		tree = (tree->nextArray)[tree->nextNumber-1].nextEl;
		i++;	 
	}
}
