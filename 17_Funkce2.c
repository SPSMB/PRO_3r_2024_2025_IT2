#include "stdio.h"
#pragma warning(disable:4996)

void nasob(int * a, int *b, int* vysledek){
	int prvni = *a;
	int druhy = *b;
	printf("2-Adresa promenne vysledek: %p\n", vysledek);
	*vysledek = prvni * druhy;
}


int main(void)
{
	
	int x, y;
	int v;
	printf("1-Adresa promenne v: %p\n", &v);
	printf("Zadejte 2 cisla: ");
	scanf("%d %d", &x, &y);

	nasob(&x, &y, &v);

	printf("Vysledek nasobeni: %d\n", v);

	return 0;
}
