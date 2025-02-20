#include <stdio.h>
#include <stdbool.h>

#include "43_includeB.c"

int main(){
   
	// deklarace s inicializaci - verze 2
	int p1[5] = {1,2,3,4,5};
	int p2[5] = {10,20,30,40,50};
	int p3[5] = {101,201,301,401,501};
	int * tabulka[3] = {p1, p2, p3};

	int pole1D[8] = {9,8,7,6,5,4,3,2};

	bubbleSort(pole1D, sizeof(pole1D)/sizeof(int));
	printf("Vypis pole 1D:\n");
	vypisPole(pole1D, sizeof(pole1D)/sizeof(int));
	printf("Vypis pole 2D:\n");
	vypis2DPole(tabulka, 3, 5);

	return 0;
}