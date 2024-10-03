#include "stdio.h"

int main(void){


	/*
	char str[100];

	printf("Zadej 9 znaku: ");
	fgets(str, 100, stdin);
	printf("Zadano: \"%s\"", str);
	*/

	int i, j, k, l;
	int z;
	int kontrola;

	printf("Zadejte 2 cela cisla: ");
	kontrola = scanf_s("%d %d", &i, &j);
	printf("Kontrola: %d\n", kontrola);
	printf("I: %d, J: %d\n", i, j);

	if(kontrola != 2){
		printf("Neco se nepovedlo.\n");
		// cisteni vstupu
		while(getchar() != '\n');
	}

	printf("Zadejte dalsi 2 cela cisla: ");
	kontrola = scanf_s("%d %d", &k, &l);
	printf("Kontrola: %d\n", kontrola);
	printf("K: %d, L: %d\n", k, l);

	if(kontrola != 2){
		printf("Neco se nepovedlo.\n");
		// cisteni vstupu
		while(getchar() != '\n');
	}

	printf("Z: %d", z);




	return 0;
}