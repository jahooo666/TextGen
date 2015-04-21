#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


int main(int argc, char **argv){
	srand(time(NULL));
	node * curr, * root;
	int i;
	int rng = 3;
	root = NULL;
	
	char **wArray=(char **)malloc(rng*sizeof(char *));
	char **wvArray=(char **)malloc(rng*sizeof(char *));
	char **waArray=(char **)malloc(rng*sizeof(char *));
	for(i=0;i<rng;i++){
		wArray[i]=(char *)malloc(100*sizeof(char));
		sprintf(wArray[i],"komorka nr %d",i);
	}
	
	add(&root, wArray,rng);
	
	for(i=0;i<rng;i++){
		wvArray[i]=(char *)malloc(100*sizeof(char));
		sprintf(wvArray[i],"komorka bla %d",i);
	}
	
	add(&root, wvArray,rng);
	
	for(i=0;i<rng;i++){
		waArray[i]=(char *)malloc(100*sizeof(char));
		sprintf(waArray[i],"sheuoa bla %d",i);
	}
	
	add(&root, waArray,rng);
		
		
	node *found = search(&root, wArray,rng);
	found->noO++; 
	printf("left to: %s\n",(found->left)->wArray[0]);
	//node *found2 = found->right;
	
		
	//printf("left to: %s",found->left->val);
	//found->left->number+=2;
	//found->right->number--;
	//TODZIALA!!!!
	printout(root, rng, 0);
	
	
}
