#include "stdio.h"
#pragma warning(disable:4996)

int main(void){
	
	int vstup;
	double faktorial = 1;

	printf("Zadejte cele cislo: ");
	scanf("%d", &vstup);


	for(int i = 1; i <= vstup; i++){
		faktorial = faktorial * i;
		printf("Faktorial z %d je %.0lf.\n", 
			i, faktorial);
	}

	do {
		// nejaka aktivita
	} while(i < 10);


	return 0;
}