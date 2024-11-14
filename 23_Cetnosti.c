#include "stdio.h"
#pragma warning(disable:4996)


int main(void)
{
	// nacitani cisel dokud uzivatel nezada 0

	int vstup;

	printf("Zadejte radu cisel, ukoncete vstup nulou:\n");

	do {
		scanf("%d", &vstup);
		// ukladani

	} while(vstup != 0);

	// vypis
	
	return 0;
}
