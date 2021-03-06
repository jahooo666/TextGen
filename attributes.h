#ifndef ATRIBUTES_H
#define ATRIBUTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int wordNumber;
	int paragraphNumber;
	int ngramLevel;
	int statistics;
	char *inFile[15];
	int inFileNumber;
	char *nginFile[15];
	int nginFileNumber;
	char *outFile;
	char *ngoutFile;
	int error;

} attributes_t;


int help();	
attributes_t readAttributes(int argc,char** argv);
int printAttributes(attributes_t atributes);
#endif
