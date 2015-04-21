#ifndef TREE_H
#define TREE_H
#include <stdio.h>

typedef struct {
	struct node *nextEl;
	int noC; //number of Collocation
}next_t;

typedef struct tree_el{
	 char** wArray;
	 int noO; 	//number of Occurences
	 int PMI;
	 struct next_t* nextArray;
	 struct tree_el * right, * left; //to do drzewa
	 
}node;


void insert(node ** tree, node * item, int rng);
void printout(node * tree, int rng);
void add(node **tree, char** valu, int rng);
int ngrcmp(char **a,char **b, int size);
node* search(node **tree, char** valu, int rng);
#endif
