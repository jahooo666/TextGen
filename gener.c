#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./ngramTree/tree.h"
#include "gener.h"

void gener(node * origTree, int rng, int ls){
// ls -liczba slow do wygenerowania
	node * tree = origTree;
	srand(time(NULL));
	int i,j;	
	int suma;
	i=0;
	printf("Drukuje ngram %d rzedu\n",rng);
	//drukowanie wszystkich wyrazow pierwszego ngramu
	for(j=0;j<rng;j++)
			printf("%s ",tree->wArray[j]);
	tree = (tree->nextArray)[tree->nextNumber-1].nextEl;
	
	
	
	//drukowanie pojedynczego(ostatniego) slowa kolejnego ngramu i przesuwanie wskaznika na nastepny element	
	while(i<ls){	
		if (tree==NULL) tree = origTree;	
		printf("%s ",tree->wArray[rng-1]);
		//losowanie slowa ktore ma byc nastepne z tablicy nextow
		suma = 0;
		for (j=0;j<tree->nextNumber;j++){
			suma = suma + tree->nextArray[j].noC;			
		}
		//printf("[%d]  ",suma);
		if(suma!=0){
			int los=rand()%suma;		
			//printf("%d -",los);
			int przedzial = 0;
			while(los>tree->nextArray[przedzial].noC){
				los=los-tree->nextArray[przedzial].noC;
				przedzial++;
			}
			tree = (tree->nextArray)[przedzial].nextEl;
			
		}
		else	tree = NULL; 
		i++;	 
	}
	printf("\n");	
}
