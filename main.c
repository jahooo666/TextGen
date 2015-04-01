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
char* sdr;
	for (i = 1; i < (argc -1); i++){
		if (strcmp("-in", argv[i]) == 0) {
			printf("in = %s\n", argv[++i]);
			continue;
		}
		
		if (strcmp("-ngin", argv[i]) == 0) {
			printf("ngin = %s\n", argv[++i]);
			continue;
		}
		
		if (strcmp("-out", argv[i]) == 0) {
			printf("out = %s\n", argv[++i]);
			continue;
		}
		
		if (strcmp("-ngout", argv[i]) == 0) {
			printf("ngout = %s\n", argv[++i]);
			continue;
		}
		
		if (strcmp("-is", argv[i]) == 0) {
			is = atoi(argv[++i]);
			printf("is = %d\n", is);
			continue;
		}
		
		if (strcmp("-ia", argv[i]) == 0) {
			ia = atoi(argv[++i]);
			printf("ia = %d\n", ia);
			continue;
		}
		
		if (strcmp("-rng", argv[i]) == 0) {
			rng = atoi(argv[++i]);
			printf("rng = %d\n", rng);
			continue;
		}
		
		if (strcmp("-stat", argv[i]) == 0) {
			printf("stat = %s\n", argv[++i]);
			continue;
		}
		
		if ((argv[i][0]=='*')) {
			printf("mamy gwiazdke %s\n", argv[++i]);
			continue;
		}
	}

}
