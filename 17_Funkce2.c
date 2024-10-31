#include "stdio.h"
#pragma warning(disable:4996)

void nasob(int * a, int *b, int* vysledek){
	int prvni = *a;
	int druhy = *b;
	*vysledek = prvni * druhy;
}


int main(void)
{
	
	int x, y;
	printf("Zadejte 2 cisla: ");
	scanf("%d %d", &x, &y);

	nasob(x, y, vysledek);

	printf("Vysledek nasobeni: %d", vysledek);

	return 0;
}
