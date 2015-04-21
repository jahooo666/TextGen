#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void insert(node ** tree, node * item){
	if(!(*tree)){
		*tree = item;
		return;
	}
	if(strcmp((item->val),((*tree)->val))<0)
		insert(&(*tree)->left, item);
	else if(strcmp((item->val),((*tree)->val))>0)
		insert(&(*tree)->right, item);
}


node* search(node **tree, char* valu){
	if(!(*tree)){
		return NULL;
	}
	int wynik = strcmp(valu,(*tree)->val);
	if(wynik == 0){
		return *tree;
	}else if(wynik < 0){
		search(&((*tree)->left),valu);
	}else if(wynik > 0){
		search(&((*tree)->right),valu);
	}
}

void add(node **tree, char* valu){
	node * curr;
	curr = (node *)malloc(sizeof(node));
	curr->left = curr->right = NULL;
	curr->val = malloc(30*sizeof(char));
	(curr->val)=valu;
	insert(&(*tree),curr);
}

void printout(node * tree){
	if(tree->left) printout(tree->left);
	printf("%s\n",tree->val);
	if(tree->right) printout(tree->right);
}
