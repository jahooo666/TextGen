#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void insert(node ** tree, node * item){
	if(!(*tree)){
		*tree = item;
		return;
	}
	if(item->val<(*tree)->val)
		insert(&(*tree)->left, item);
	else if(item->val>(*tree)->val)
		insert(&(*tree)->right, item);
}
void printout(node * tree){
	if(tree->left) printout(tree->left);
	printf("%d\n",tree->val);
	if(tree->right) printout(tree->right);
}
