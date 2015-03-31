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
int i;
for (i = 1; i < (argc -1); i++){
if (strcmp("-s", argv[i]) == 0) {
printf("string = %s\n", argv[++i]);
continue;
}
}

}
