#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "output.h"
#include "wordArray.h"
#include "./ngramTree/tree.h"

int writeTextToTextFile(char *fileName, node *origTree, int rng, int ls){		
// ls -liczba slow do wygenerowania
	FILE *fp;
	fp=fopen(fileName,"w");
		
	node * tree = origTree;
	srand(time(NULL));
	int i,j;	
	int suma;
	i=0;
	printf("Drukuje ngram %d rzedu do pliku %s\n",rng,fileName);
	//drukowanie wszystkich wyrazow pierwszego ngramu
	for(j=0;j<rng;j++)
			fprintf(fp,"%s ",tree->wArray[j]);
	tree = (tree->nextArray)[tree->nextNumber-1].nextEl;
	
	
	
	//drukowanie pojedynczego(ostatniego) slowa kolejnego ngramu i przesuwanie wskaznika na nastepny element	
	while(i<ls){	
		if (tree==NULL) tree = origTree;	
		fprintf(fp,"%s ",tree->wArray[rng-1]);
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
	fprintf(fp,"\n");
	fclose(fp);
	return 0;	
}
int writeNgramsToBinaryFile(char *fileName, node *origTree, int rng){
FILE *fp;
fp=fopen(fileName,"wb");

	
}

