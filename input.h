#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordArray.h"
#include "./ngramTree/tree.h"

int countWordsInText( char *fileName);
int countWordsInTextFiles( char **fileName,int fileNumber);
int readWordsFromTextFiles( char **fileName, int fileNumber, word_t *wordArray);
int readNgramsFromTextFiles( char **fileName, int fileNumber, node **root, int rng);

					 							
//ngramElem *readDataFromBaseFile( char *fileName);

#endif
