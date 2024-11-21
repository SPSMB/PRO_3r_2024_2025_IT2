#include "stdio.h"
#pragma warning(disable:4996)


void vypis2DPole(int ** pole, int pocRadku, int pocSloupcu){
	for(int r=0; r < pocRadku; r++){

		for (int s = 0; s < pocSloupcu; ++s)
		{
			printf("%d ", pole[r][s]);
		}

		printf("\n");

	}
}

int main(void)
{
	// deklarace s inicializaci - verze 1
	int tabulka2[3][4] = {{1,2,3,4},
						 {10,20,30,40},
						 {100,200,300,400}};
	
	// deklarace s inicializaci - verze 2
	int p1[5] = {1,2,3,4,5};
	int p2[5] = {10,20,30,40,50};
	int p3[5] = {101,201,301,401,501};
	int * tabulka[3] = {p1, p2, p3};
	


	vypis2DPole(tabulka, 3, 5);
	return 0;
}
