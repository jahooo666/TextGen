#include <stdio.h>
#include<stdlib.h>
#include "tree.h"


int main(int argc, char **argv){
	node * curr, * root;
	int i;
	root = NULL;

	for(i=1; i<=10; i++){
		curr = (node *)malloc(sizeof(node));
		curr->left = curr->right = NULL;
		curr->val = rand();
		insert(&root, curr);
	}
	printout(root);	
}
