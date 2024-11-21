#include "stdio.h"
#pragma warning(disable:4996)


void vypis2DPole(int ** pole, int pocRadku, int pocSloupcu){
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
	printf("Nejlepsi skupina je skupina %d.", nejIndex);
}

int main(void)
{
	// deklarace s inicializaci - verze 2
	int sk1[4] = {2,4,4,5};
	int sk2[4] = {6,8,3,2};
	int sk3[4] = {10,7,1,4};
	int sk4[4] = {5,6,7,1};
	int sk5[4] = {9,8,8,1};
	int * tabulka[5] = {sk1, sk2, sk3, sk4, sk5};
	
	bestGroup(tabulka, 5, 4);
	avgAvg(tabulka, 5, 4);
	maxScore(tabulka, 5, 4);

	vypis2DPole(tabulka, 5, 4);
	return 0;
}
