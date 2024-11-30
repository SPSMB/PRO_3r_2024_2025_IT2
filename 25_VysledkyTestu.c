#include "stdio.h"
#pragma warning(disable:4996)


void vypis2DPole(int ** pole, int pocRadku, int pocSloupcu);
void bestGroup(int ** pole, int pocRadku, int pocSloupcu);
void avgAvg(int ** pole, int pocRadku, int pocSloupcu);
void maxScore(int ** pole, int pocRadku, int pocSloupcu);


int main(void)
{
	// deklarace s inicializaci - verze 2
	int sk0[4] = {10,4,4,5};
	int sk1[4] = {6,8,9,9};
	int sk2[4] = {9,7,10,4};
	int sk3[4] = {5,6,7,1};
	int sk4[4] = {9,8,10,10};
	int * tabulka[5] = {sk0, sk1, sk2, sk3, sk4};
	
	bestGroup(tabulka, 5, 4);
	avgAvg(tabulka, 5, 4);
	maxScore(tabulka, 5, 4);

	vypis2DPole(tabulka, 5, 4);
	return 0;
}

void vypis2DPole(int ** pole, int pocRadku, int pocSloupcu){
	printf("Vypis pole:\n");
	for(int r=0; r < pocRadku; r++){
		for (int s = 0; s < pocSloupcu; ++s){
			printf("%d ", pole[r][s]);
		}
		printf("\n");
	}
}

void bestGroup(int ** pole, int pocRadku, int pocSloupcu){
	
	int nejIndex = 0;
	int nejSoucet = 0;
	int soucet = 0;
	for(int r=0; r < pocRadku; r++){
		for (int s = 0; s < pocSloupcu; ++s){
			soucet += pole[r][s];
		}
		if(soucet > nejSoucet){
			nejIndex = r;
		}
		soucet = 0;
	}
	printf("Nejlepsi skupina je skupina %d.\n", nejIndex);
}

void avgAvg(int ** pole, int pocRadku, int pocSloupcu){

	float soucet = 0;

	for(int r=0; r < pocRadku; r++){
		for(int s=0; s < pocSloupcu; s++){
			soucet += pole[r][s];
		}
		float prumer = soucet / pocSloupcu;
		printf("Prumer skupiny %d je %.1lf.\n", r, prumer);
		soucet = 0;
	}
}

void maxScore(int ** pole, int pocRadku, int pocSloupcu){

	// nemuzu pouzit presne cislo na pocet radku
	int max[1000] = {0};
	int maxExistuje = 0;
	for(int r=0; r<pocRadku; r++){
		for(int s=0; s<pocSloupcu; s++){
			if(pole[r][s] == 10){
				max[r] = 1;
				maxExistuje = 1;
				break;
			}
		}
	}
	if(maxExistuje){
		 printf("Maximum nalezeno ve skupinach: ");
		 for(int r=0; r<1000; r++){
		 	if(max[r] == 1){
		 		printf("%d, ", r);
		 	}
		 }
		 printf("\n");
	} else {
		printf("Zadna skupina neobsahuje maximalni skore.\n");
	}

}