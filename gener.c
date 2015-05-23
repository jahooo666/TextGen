#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./ngramTree/tree.h"
#include "gener.h"

void gener(node * tree, int rng, int ls){
// ls -liczba slow do wygenerowania
	int i,j;	
	
	//drukowanie wszystkich wyrazow pierwszego ngramu
	for(j=0;j<rng;j++)
			printf("%s \n",tree->wArray[j]);
	//drukowanie pojedynczego(ostatniego) slowa kolejnego ngramu i przesuwanie wskaznika na nastepny element		
	while(tree){		
		printf("%s \n",tree->wArray[rng-1]);
		tree = (tree->nextArray)[0].nextEl;	 
	}
}
