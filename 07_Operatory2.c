#include "stdio.h"
#pragma warning(disable:4996)

int main(void){
	/*
	int x = 1;
	int y = 2;

	printf("x&y: %d\n", x&y);
	printf("x&&y: %d\n", x&&y);
	*/

	double cislo;
	int kontrola;
	printf("Zadejte cislo: ");
	kontrola = scanf("%lf", &cislo);

	if( kontrola != 1){
		printf("chyba" );
	}else {
		if (cislo < 0){
		cislo = -cislo;
		
		}
		printf("absolutni hodnota je %.2lf\n", cislo);
	}

	



	return 0;
}