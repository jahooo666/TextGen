#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "ngramArray.h"
#include "wordArray.h"

/*
bierze: slowo do dodania, index poprzedniego ngramu, wskaznik na tablice ngramow, aktualna pozycje w ngramie, 
robi: dodaje nowy ngram/ dodaje wystapienie do istniejacego ngramu
zwraca: 
*/
int addNgram(ngram_t *ngramArray, int arraySize, int ngramLevel, int *ngramToAdd, int lastNgram){
	ngram_t newNgram;
	int foundNgram;
	printf("dodaje nowy ngram %d,%d, %d, %d\n",ngramToAdd[0],ngramToAdd[1],ngramToAdd[2],ngramToAdd[3]);
	if(lastNgram==(-1)){
		printf("1-");
		//dodawanie ngramu bez linkowania -- to znaczy ze jest to pierwsze slowo tekstow/pliku - zobaczymy jak to bedzie rozwiazane
		foundNgram = findNgram(ngramArray, arraySize, ngramLevel, ngramToAdd);
		//szuka ngramu w tablicy ngramow
		printf("znaleziony ngram %d\n", foundNgram);
		if(foundNgram==(-1)){		//nie znalezlismy wiec tworzymym nowy
			newNgram.ngram = ngramToAdd;
			newNgram.numberOfOccurences = 1;
			newNgram.nextNumber = 0;
			ngramArray[arraySize] = newNgram;
			// w razie dalszych problemow z nextami tutaj mozna sprobowac zaalokowac pamiec na tablice nextow
			//printf("dodaje nowy ngram %d,%d, %d, %d\n",newNgram.ngram[0],newNgram.ngram[1],newNgram.ngram[2],newNgram.ngram[3]);
			return (arraySize+1);
		}	
		else{						//znalezlismy go juz w tablicy wiec dodajemy mu tylko wystapienie.
			ngramArray[foundNgram].numberOfOccurences++;
			return (foundNgram);			
		}		 	
	} 
	else{			//dodawanie ngramu wraz z linkowaniem
		printf("2-");
		foundNgram = findNgram(ngramArray, arraySize, ngramLevel, ngramToAdd);
		printf("znaleziony ngram %d\n", foundNgram);
		printf("dodaje nowy ngram %d,%d, %d, %d\n",ngramToAdd[0],ngramToAdd[1],ngramToAdd[2],ngramToAdd[3]);
		if (foundNgram==(-1)){// takiego ngramu jeszcze nie bylo dodajemy go i linkujemy do poprzedniego
			newNgram.ngram = ngramToAdd;
			newNgram.numberOfOccurences = 1;
			newNgram.nextNumber = 0;
			ngramArray[arraySize] = newNgram;
			// w razie dalszych problemow z nextami tutaj mozna sprobowac zaalokowac pamiec na tablice nextow
			//linkowanie
			printf("dodaje nowy ngram %d,%d, %d, %d\n",newNgram.ngram[0],newNgram.ngram[1],newNgram.ngram[2],newNgram.ngram[3]);
			return (arraySize+1);
		}
		else{// taki ngram juz byl wiec dodajemy mu occurence i linkujemy do poprzedniego
			ngramArray[foundNgram].numberOfOccurences++;
			//linkowanie
			return (foundNgram);	
		}		
	}	
}


int findNgram(ngram_t *ngramArray, int arraySize, int ngramLevel, int *soughtNgram){ //tablica intow jako ostatni argument jest specjalnie- patrz struktura
//indx w tab ngamow|(w tym szukamy)|tyle dotych. bylo ngramow|lvl|ngram podejrzewany o bycie juz w tablicy 
	int i = 0;
	int j = 0;
	int theSame = 1;	//w kazdym ngramie ta zmienna jest od nowa ustalana na true i gdy wystapi pierwsza niezgodnosc to staje sie 0
	int found = 0; 	//zmienna mowiaca czy juz znalezlismy odpowiedni ngram
	
	
	while((i<arraySize)&&(found!=1)){
		theSame = 1;
		j=0;
		while((j<ngramLevel)&&(theSame!=0)){			//czy jestesmy jeszcze  w ngrami i czy juz gdzies nie bylo niezgodnosci
			if((ngramArray[i].ngram[j])!=soughtNgram[j])
				theSame = 0;
			else
				j++;
		}
		
		if(theSame == 1){ //jezeli po przejsciu przez poprzednia petle theSame nadal jest rowne 1 to znaczy ze znaleziono odpowiedni
			found = 1;
			return i;	
		}
		else	i++;
	}
	return -1;	

}


int findNext(ngram_t ngramElem, int nextNgramIndex){
	int i;
	int foundNext = -1;
	if(ngramElem.nextNumber!=0){
		for(i=0;i<ngramElem.nextNumber;i++){
			if((ngramElem.nextArray[i].nextNgram)==nextNgramIndex)
				foundNext= nextNgramIndex;
		}
	}
	return(foundNext);
}

/*
if(wordsInText == ngramLevel){
				for(j=0;j<ngramLevel;j++){		//dla takiej liczby slow w pliku = ngramLevel					
					fscanf(textFile,"%s",buffer);		//wczytaj do stringa slowo
					newNgram.ngram[j] = findWord(wordArray, wordArraySize, buffer); //sprawdzajac i zapisujac po koleii indexy z wordArray
				}
				foundPosition=findNgram(ngramArray, currentNgramArrayPosition, ngramLevel, newNgram.ngram);
				if(foundPosition==(-1)){					
					newNgram.numberOfOccurences=1;
					newNgram.nextNumber = 0;
					ngramArray[currentNgramArrayPosition] = newNgram;
					currentNgramArrayPosition++;
				}	
				else
					ngramArray[foundPosition].numberOfOccurences++; 	
			}
			//TODO Dodac do funkcji addNgram opcje dodawania bez wiazania - z jakims indeksem poprzedniego -1 czy cos
			else	{			//wiemy ze liczba slow w pliku jest wieksza od rzedu ngramu
				//znajdujemy sie teraz na poczatku pliku- inicjujemy tworzac pierwszy ngram
				
				for(j=0;j<ngramLevel;j++){					
					fscanf(textFile,"%s",buffer);		//czytanie slowa z pliku			
					temp = findWord(wordArray, wordArraySize, buffer);
					tempWordIndexArray[j] = temp;		//findWord(wordArray, wordArraySize, buffer);//sprawdzenie indexu slowa  z tablicy slow
					printf("przeczytalem slowo %d \n",temp);
				}
				printf("bede szukal takiej tablicy %d-%d-%d-%d \n",tempWordIndexArray[0],tempWordIndexArray[1],tempWordIndexArray[2],tempWordIndexArray[3]);
				foundPosition = findNgram(ngramArray, currentNgramArrayPosition, ngramLevel, tempWordIndexArray);
				printf("pozycja ngramu to :%d\n",foundPosition);
						if(foundPosition==(-1)){
							newNgram.ngram=tempWordIndexArray;		//twrzorzymy nowy ngram
							newNgram.numberOfOccurences=1;
							newNgram.nextNumber = 0;
							ngramArray[currentNgramArrayPosition] = newNgram;
							//printf("newNgram.ngram to :%d-%d-%d\n",ngramArray[currentNgramArrayPosition].ngram[0],ngramArray[currentNgramArrayPosition].ngram[1],ngramArray[currentNgramArrayPosition].ngram[2]);
								
							lastNgramIndex=currentNgramArrayPosition;
							currentNgramArrayPosition++;
																			
						}	
						else{
							ngramArray[foundPosition].numberOfOccurences++; 
							lastNgramIndex=foundPosition;
						}
						//newtempWordIndexArray[0] = tempWordIndexArray[0];
					
				for(k=0;k<(ngramLevel);k++){		//kopiuje tablice do nowej zminnej bo tamta cos chrzniola --- zagadka wszechczasow
							newtempWordIndexArray[k]=tempWordIndexArray[k];
					}
				for(j=1;j<(wordsInText-ngramLevel);j++){
						for(k=0;k<(ngramLevel-1);k++){		//przesuniecie tablicy o jeden w lewo -> prawy brzeg "wolny"
							newtempWordIndexArray[k]=newtempWordIndexArray[k+1];
						}
						
						fscanf(textFile,"%s",buffer);	
						newtempWordIndexArray[ngramLevel-1] = findWord(wordArray, wordArraySize, buffer);//ostatni element uzupelniamy nowym slowem(jego indexem)
						printf("Doczytalem do tablicy slowo %d \n",newtempWordIndexArray[ngramLevel-1]);
						printf("Teraz tablica wyglada nastepujaca %d-%d-%d-%d \n",newtempWordIndexArray[ngramLevel-4],newtempWordIndexArray[ngramLevel-3],newtempWordIndexArray[ngramLevel-2],newtempWordIndexArray[ngramLevel-1]);
						foundPosition = findNgram(ngramArray, currentNgramArrayPosition, ngramLevel, newtempWordIndexArray);//TODO sprawdzic czy to szukanie nie wchodzi na pamiec currentngramPosition!!!
						printf("znaleziona pozycja to: %d\n",foundPosition);
						
						if(foundPosition==(-1)){
						
							newNgram.ngram = newtempWordIndexArray;		//twrzorzymy nowy ngram
							newNgram.numberOfOccurences = 1;
							newNgram.nextNumber = 0;
							ngramArray[currentNgramArrayPosition] = newNgram;
														//tu jest miejsce gdzie zaczynamy linkowac poprzedniego ngram do aktualnego
								foundNext=findNext(ngramArray[lastNgramIndex],currentNgramArrayPosition);
								printf("1\n");
								if(foundNext==-1){	
														//wypadek gdy nie wystapilo jeszcze takie przejscie
									ngramArray[lastNgramIndex].nextNumber++;
									
									int nextSize = ngramArray[lastNgramIndex].nextNumber;
									printf("rozmiar nexta = %d\n",nextSize);
					
									ngramArray[lastNgramIndex].nextArray[nextSize].nextNgram = currentNgramArrayPosition;
									printf("2\n");
								}
								else ngramArray[lastNgramIndex].nextArray[foundNext].numberOfCollocations++;		//gdy takie przejscie juz nastapilo
								// ngramArray[lastNgramIndex].nextArray[]; -chyba niepotrzebne ale boje sie wyrzucac
							lastNgramIndex=currentNgramArrayPosition;
							currentNgramArrayPosition++;
							printf("Jestem tutaj i dodaje collocation w ngramie nr %d przejscie nr %d\n",lastNgramIndex,foundNext);
							
						}	
						else{
							ngramArray[foundPosition].numberOfOccurences++; 
							lastNgramIndex=foundPosition;
							printf("Dodalem occurence do ngramu nr: %d\n",foundPosition);
						}
				}
	
			}
			*/

