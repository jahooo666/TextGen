//#include "input.h"
//#include "output.h"
//#include "ngramArray.h"
//#include "wordArray.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
Wiadomosc o niepoprawnych danych- wraz z instrukcja.
*/

int help(){
	printf("Sposob uzycia: ./TextGen\n");
		printf("\t [-in = plik wejsciowy]\n");
		printf("\t [-ngin = plik wejsciowy bazowy]\n");
		printf("\t [-out = plik wyjsciowy]\n");
		printf("\t [-ngout = nazwa pliku do ktorego ma byc zapisana baza ]\n");
		printf("\t [-is = ilosc slow ktore program ma wygenerowac]");
		printf("\t [-rng = rzad n-gramow na podstawie ktorych ma byc generowany tekst ]");
		printf("\t [-stat = czy maja byc generowane statystyki slow]");

	return 1;
}



int main(int argc, char *argv[]){
int i, is, ia, rng; 
int stat=1; 									
char* inFile[15];								// tablice nazw plikow
char* nginFile[15];								//------------
char* ngoutFile;
char* outFile;
int a; 										//aktualna pozycja w tablicy stringow 

	for (i = 1; i < (argc -1); i++){				// pliki wejsciowe z tekstem - maksymalnie 15
		if (strcmp("-in", argv[i]) == 0) {
			a=0;
			printf("in: ");
			while(argv[++i][0]!='-'){
				inFile[a]=argv[i];
				printf("--[ %s ]",inFile[a]);				
				a++;
			}
			printf("\n");	
			i--;
			continue;
		}
		
		if (strcmp("-ngin", argv[i]) == 0) {		// pliki wejsciowe z danymi - maksymalnie 15
			a=0;
			printf("ngin: ");
			while(argv[++i][0]!='-'){
				nginFile[a]=argv[i];
				printf("--[ %s ]",nginFile[a]);				
				a++;
			}
			printf("\n");	
			i--;
			continue;
		}
		
		if (strcmp("-out", argv[i]) == 0) {		// nazwa pliku do ktorego bedzie zapisywany tekst
			if (argv[++i][0]!='-')
			outFile=argv[i];
			i--;
			printf("out = %s\n", outFile);
			continue;
		}
		
		if (strcmp("-ngout", argv[i]) == 0) {		// nazwa pliku do ktorego beda zapisywane dane slow
			if (argv[++i][0]!='-')
				ngoutFile=argv[i];
			i--;
			printf("ngout = %s\n", ngoutFile);
			continue;
		}
		
		if (strcmp("-is", argv[i]) == 0) {			// ilosc slow do wygenerowania
			is = atoi(argv[++i]);
			printf("is = %d\n", is);
			continue;
		}
		
		if (strcmp("-ia", argv[i]) == 0) {			//ilosc akapitow na ktore ma byc podzielony tekst
			ia = atoi(argv[++i]);
			printf("ia = %d\n", ia);
			continue;
		}
		
		if (strcmp("-rng", argv[i]) == 0) {		//rzad ngramow 
			rng = atoi(argv[++i]);
			printf("rng = %d\n", rng);
			continue;
		}
		
		if (strcmp("-stat", argv[i]) == 0) {		//czy maja byc generowane statystyki
			i++;
			if(((strcmp(argv[i],"0"))==0)||((strcmp(argv[i],"false"))==0))				//||(strcmp("false", argv[i]) == 0)
				stat=0;
			else stat=1;
			i--;
			printf("stat = %d\n", stat);
			continue;
		}
		
		
	}

}
