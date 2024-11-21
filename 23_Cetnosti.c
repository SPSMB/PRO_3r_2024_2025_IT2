#include "stdio.h"
#pragma warning(disable:4996)


int main(void)
{
	// nacitani cisel dokud uzivatel nezada 0

	int vstup;
	int pole[101] = {0};

	printf("Zadejte radu cisel, ukoncete vstup nulou:\n");

	do {
		scanf("%d", &vstup);
		// ukladani
		if (vstup <= 100 && vstup > 0);
		{
			pole[vstup]++;
		}
	} while(vstup != 0);

	// vypis
	for (int i = 1; i < 101; ++i)
	{
		if (pole[i] > 0)
			{
			printf("cislo %d je %dx \n", i, pole[i]);
		}
	}
	
	return 0;
}
