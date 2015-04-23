#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./ngramTree/tree.h"
#include "gener.h"

void gener(node * tree, int rng, int ls){
	int i,j;
	for(i=0;i<ls;i++){
		for(j=0;j<ls;j++){
			printf("%s \n",tree->wArray[j]);
		}
		tree = (tree->nextArray)[0].nextEl; 
	}
}
