#include "stdio.h"
#pragma warning(disable:4996)

int main(void)
{
	int pole1[50];

	pole1[10] = 152;
	pole1[17] = -1000;

	printf("10: %d\n", pole1[10]);
	printf("17: %d\n", pole1[17]);
	printf("25: %d\n\n", pole1[25]);

	for(int i=10; i<=20; i++){
		printf("%d: %d\n", i, pole1[i]);
	}

	// nazev pole se chova jako ukazatel na jeho 1. prvek
	printf("Ukazatel na 1. prvek pole: %p\n", &(pole1[0]));
	printf("Nazev pole se chova jako Ukazatel na 1. prvek: %p\n", pole1);

	int velikost = sizeof(pole1);
	printf("Velikost pole v B: %d", velikost);
	return 0;
}
