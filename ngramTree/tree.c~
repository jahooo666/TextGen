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


node* insert(node ** tree, node * item, int rng){
	if(!(*tree)){
		*tree = item;
		return *tree;
	}
	if(ngrcmp((item->wArray),((*tree)->wArray),rng)<0)
		insert(&(*tree)->left, item,rng);
	else if(ngrcmp((item->wArray),((*tree)->wArray),rng)>0)
		insert(&(*tree)->right, item,rng);
}


node* add(node **tree, char** valu, int rng, node *last){
	//TODO dodac sprawdzadzie czy danego nexta jeszcze nie bylo
	node * found = search(tree, valu, rng);
	if(found!=NULL){		//gdy taki ngram byl juz w drzewie
		found->noO++;
		//dodaawanie przejscia z poprzedniego
		if(last!=NULL){
			int nextNumb=last->nextNumber;
			//next_t temp = last->nextArray[nextNumb];
			//temp.nextEl = found;
			last->nextArray[nextNumb].nextEl = found;
			//last->nextArray[nextNumb] = temp; 
			last->nextNumber++; 
		}		
		return(found);
	}else{				//gdy takiego ngramu jeszcze nie bylo w drzewie
		int i;
		node * curr;
		curr = (node *)malloc(sizeof(node));
		curr->left = curr->right = NULL;
		curr->wArray = (char **)malloc(rng*sizeof(char*));
		curr->nextArray = (next_t *)malloc(100*sizeof(next_t));
		curr->nextNumber = 0;
		for(i=0; i<rng; i++){
			 curr->wArray[i] = (char *)malloc(100*sizeof(char));
			 strcpy(curr->wArray[i],valu[i]);
		}
		curr->noO = 1;			
		node *currPtr = insert(&(*tree),curr,rng);
		if(last!=NULL){
			int nextNumb=last->nextNumber;
			(last->nextArray[nextNumb]).nextEl = (node *)currPtr; 
			last->nextNumber++;
		}
		return currPtr;
	}
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
// od ktorego wezla ma zaczac drukowac - rzad ngramow - poziom drukowania - zeby wygladalo jak drzewo 	
	int i;
	if(tree->left) printout(tree->left,rng,lvl+1);
	//if((tree->nextNumber > 1)&&(tree->noO!=tree->nextNumber)){
		for(i=0;i<lvl;i++)printf(" ");	
		for(i=0; i<rng; i++)printf("%s-\t",tree->wArray[i]);
		printf("--noO=%d--nN=%d\n",tree->noO,tree->nextNumber);
	//}
	if(tree->right) printout(tree->right,rng,lvl+1);
}




