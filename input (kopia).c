#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "wordArray.h"
#include "ngramArray.h"

int countWordsInText( char *fileName){
	FILE *textFile;
	char slowo[255];
	int wordNumber = 0;

	textFile = fopen(fileName,"r");
	
	while(fscanf(textFile,"%s",slowo)!= EOF)
		wordNumber++;
	
	printf("Liczba slow to: %d\n", wordNumber);
	return wordNumber;
}


int countWordsInTextFiles( char **fileName, int fileNumber){
	int totalWordNumber = 0; 
	int i;
	for(i=0; i<fileNumber; i++){
		totalWordNumber += countWordsInText(fileName[i]);
	}
	printf("Liczba slow we wszystkich plikach to: = %d\n",totalWordNumber);
	return totalWordNumber;
}


int readWordsFromTextFiles( char **fileName, int fileNumber, word_t *wordArray){
	int i,j,ind;
	j = 0;//takie i dla niepowtarzalnych slow
	int totalWordNumber = 0; 
	int newTotalWordNumber = 0; 
	
	for(i=0; i<fileNumber; i++){
		FILE *textFile = fopen(fileName[i],"r");
		word_t newWord;
		while(fscanf(textFile,"%s",newWord.text)!= EOF){	
			ind = findWord(wordArray,j,newWord.text);
			if(ind != (-1)){			
				wordArray[ind].numberOfOccurences++;
			}
			else{
				newWord.numberOfOccurences = 1;
				wordArray[j] = newWord;
				j++;
			}
		}fclose(textFile);
	}
	
	return j;
	
}

int readNgramsFromTextFiles( char **fileName, int fileNumber, ngram_t *ngramArray, int ngramLevel, word_t *wordArray, int wordArraySize){
	
	int i,j,k;
	int currentNgramArrayPosition = 0; 
	int first,last; 				//indexy do przechodzenia po tablicy 
	char buffer[255];
	FILE *textFile;
	ngram_t newNgram;
	
	int foundPosition;
	int foundNext;
	int lastNgramIndex; //<- index ostatnio uzywanego ngramu uzywany do laczenia ngramow
	int wordsInText;
	int temp;
	int tempWordIndexArray[ngramLevel];
	int newtempWordIndexArray[ngramLevel];
	for(i=0; i<fileNumber; i++){
		wordsInText = countWordsInText(fileName[i]);		
		if( wordsInText >= ngramLevel ){		
			FILE *textFile = fopen(fileName[i],"r");
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
								foundNext=findNext(ngramArray[lastNgramIndex], currentNgramArrayPosition);
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
	
		}
		else printf("Plik %s ma za malo slow- nie jest brany pod uwage przy tworzeniu ngramow",fileName[i]);	
	}
	
return currentNgramArrayPosition;	
}

//TODO obsluga bledow

/*
newTotalWordNumber = readWordsFromTextFiles(argv,argc,totalWordNumber,wordArray);
	int error = printWordArray(wordArray, newTotalWordNumber);
*/
//ngramElem *readDataFromBaseFile( char *fileName);

