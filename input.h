#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordArray.h"
//#include "ngramArray.h"

int countWordsInText( char *fileName);
int countWordsInTextFiles( char **fileName,int fileNumber);
int readWordsFromTextFiles( char **fileName, int fileNumber,word_t *wordArray);

//ngramElem *readDataFromBaseFile( char *fileName);

#endif
