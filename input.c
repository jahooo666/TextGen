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
		
			if((ind=findWord(wordArray,j-1,newWord.text))&&(ind!=(-1))){			
				wordArray[ind].numberOfOccurences++;
			}
			else{
				newWord.numberOfOccurences = 1;
				wordArray[j] = newWord;
				j++;
			}
		}
		fclose(textFile);
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
	printf("jestem w funkcji\n");
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
					ngramArray[currentNgramArrayPosition] = newNgram;
					currentNgramArrayPosition++;
				}	
				else
					ngramArray[foundPosition].numberOfOccurences++; 	
			}
			else	{			//wiemy ze liczba slow w pliku jest wieksza od rzedu ngramu
				//znajdujemy sie teraz na poczatku pliku- inicjujemy tworzac pierwszy ngram
				int tempWordIndexArray[ngramLevel];
				for(j=0;j<ngramLevel;j++){
					
					fscanf(textFile,"%s",buffer);		//czytanie slowa z pliku
					//printf("czytam slowo %s\n",buffer);
					temp = findWord(wordArray, wordArraySize, buffer);
					tempWordIndexArray[j] = findWord(wordArray, wordArraySize, buffer);//sprawdzenie indexu slowa  z tablicy slow
					//printf("przeczytalem slowo %d \n",temp);
				}
				
				foundPosition = findNgram(ngramArray, currentNgramArrayPosition, ngramLevel, tempWordIndexArray);
				printf("pozycja ngramu to :%d\n",foundPosition);
						if(foundPosition==(-1)){
							newNgram.ngram=tempWordIndexArray;		//twrzorzymy nowy ngram
							newNgram.numberOfOccurences=1;
							ngramArray[currentNgramArrayPosition] = newNgram;
							//printf("newNgram.ngram to :%d-%d-%d\n",ngramArray[currentNgramArrayPosition].ngram[0],ngramArray[currentNgramArrayPosition].ngram[1],ngramArray[currentNgramArrayPosition].ngram[2]);
								
							lastNgramIndex=currentNgramArrayPosition;
							currentNgramArrayPosition++;
													
						}	
						else{
							ngramArray[foundPosition].numberOfOccurences++; 
							lastNgramIndex=foundPosition;
						}
						
				for(j=1;j<(wordsInText-ngramLevel);j++){
						for(k=0;k<(ngramLevel-1);k++){		//przesuniecie tablicy o jeden w lewo -> prawy brzeg "wolny"
							tempWordIndexArray[k]=tempWordIndexArray[k+1];
						}
						fscanf(textFile,"%s",buffer);			
						tempWordIndexArray[ngramLevel-1] = findWord(wordArray, wordArraySize, buffer);//ostatni element uzupelniamy nowym slowem(jego indexem)
						foundPosition = findNgram(ngramArray, currentNgramArrayPosition, ngramLevel, tempWordIndexArray);//TODO sprawdzic czy to szukanie nie wchodzi na pamiec currentngramPosition!!!
						if(foundPosition==(-1)){
							newNgram.ngram=tempWordIndexArray;		//twrzorzymy nowy ngram
							newNgram.numberOfOccurences=1;
							ngramArray[currentNgramArrayPosition] = newNgram;
																	//tu jest miejsce gdzie zaczynamy linkowac poprzedniego ngram do aktualnego
								foundNext=findNext(ngramArray[lastNgramIndex], currentNgramArrayPosition);
								if(foundNext==-1){								//wypadek gdy nie wystapilo jeszcze takie przejscie
									ngramArray[lastNgramIndex].nextNumber++;
									int nextSize = ngramArray[lastNgramIndex].nextNumber;
									ngramArray[lastNgramIndex].nextArray[nextSize].nextNgram=currentNgramArrayPosition;
								}
								else ngramArray[lastNgramIndex].nextArray[foundNext].numberOfCollocations++;		//gdy takie przejscie juz nastapilo
								// ngramArray[lastNgramIndex].nextArray[]; -chyba niepotrzebne ale boje sie wyrzucac
							lastNgramIndex=currentNgramArrayPosition;
							currentNgramArrayPosition++;
						}	
						else{
							ngramArray[foundPosition].numberOfOccurences++; 
							lastNgramIndex=foundPosition;
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

