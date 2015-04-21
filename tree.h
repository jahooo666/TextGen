#ifndef TREE_H
#define TREE_H
#include <stdio.h>

typedef struct tree_el{
	 char* val;
	 int number; 
	 struct tree_el * right, * left;
}node;

void insert(node ** tree, node * item);
void printout(node * tree);
void add(node **tree, char* valu);
node* search(node **tree, char* valu);
#endif
