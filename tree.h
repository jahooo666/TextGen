#ifndef TREE_H
#define TREE_H
#include <stdio.h>

typedef struct tree_el{
	 int val;
	 struct tree_el * right, * left;
}node;

void insert(node ** tree, node * item);
void printout(node * tree);
#endif
