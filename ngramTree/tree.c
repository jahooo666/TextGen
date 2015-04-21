#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


int ngrcmp(char **a,char **b,int size){	// do porownywania tablic stringow
	int i;
	int stan = 0;					 //zero oznacza ze do tej pory wszystkie slowa byly rowne
	for(i=0; i<size; i++){
		stan = strcmp(a[i],b[i]);		//tutaj troche nasladujemy strcmp bo zwracamy to co on przy pierwszym slowie ktore sie nie zgadza. -Genialne -bhawoja
		if (stan!=0) return stan; 
	}
	if(stan==0) return 0;
}


void insert(node ** tree, node * item,int rng){
	if(!(*tree)){
		*tree = item;
		return;
	}
	if(ngrcmp((item->wArray),((*tree)->wArray),rng)<0)
		insert(&(*tree)->left, item,rng);
	else if(ngrcmp((item->wArray),((*tree)->wArray),rng)>0)
		insert(&(*tree)->right, item,rng);
}

void add(node **tree, char** valu, int rng){
	int i;
	node * curr;
	curr = (node *)malloc(sizeof(node));
	curr->left = curr->right = NULL;
	curr->wArray = (char **)malloc(rng*sizeof(char*));
	for(i=0; i<rng; i++) curr->wArray[i] = (char *)malloc(100*sizeof(char));
	curr->noO = 1;
	(curr->wArray) = valu;
	insert(&(*tree),curr,rng);
}

node* search(node **tree, char** valu,  int rng){
	if(!(*tree)){
		return NULL;
	}
	int wynik = ngrcmp(valu,(*tree)->wArray,rng);
	if(wynik == 0){
		return *tree;
	}else if(wynik < 0){
		search(&((*tree)->left),valu,rng);
	}else if(wynik > 0){
		search(&((*tree)->right),valu,rng);
	}
}



void printout(node * tree, int rng, int lvl){
	int i;
	if(tree->left) printout(tree->left,rng,lvl+1);
	for(i=0;i<lvl;i++)printf("\t");
	for(i=0; i<rng; i++)printf("%s-\t",tree->wArray[i]);
	printf("--%d\n",tree->noO);
	if(tree->right) printout(tree->right,rng,lvl+1);
}




