#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordArray.h"
#include "ngramArray.h"

int main(int argc, char **argv){
	ngram_t *ngramArray = malloc(5*sizeof(ngram_t));
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			int ngramArray.ngram* = malloc(5*sizeof(int));
			ngramArray[i].ngram[j]=j*i;
			printf("%d-",ngramArray[i].ngram[j]);
		}
		printf("\n");
	}
}
