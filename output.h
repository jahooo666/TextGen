#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./ngramTree/tree.h"
#include "./gener.h"


int writeTextToTextFile(char *fileName, node *origTree, int rng, int ls);
int writeNgramsToBinaryFile(char *fileName, node *origTree, int rng);

					 							

#endif
