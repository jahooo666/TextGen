#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


int main(int argc, char **argv){
	srand(time(NULL));
	node * curr, * root;
	int i;
	
	
	root = NULL;

	for(i=1; i<=10; i++){
		char *string = (char *)malloc(30*sizeof(char));
		sprintf(string ,"numer %d",rand()%1000);
		add(&root, string);
	}
	add(&root, "blabla");
	add(&root, "Okurwa");
	add(&root, "numer 192");
	
	node *found = search(&root, "Okurwa");
	found->number++; 
	//TODZIALA!!!!
	printout(root);
	
	
}
