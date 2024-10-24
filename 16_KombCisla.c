#include "stdio.h"
#pragma warning(disable:4996)


int faktorial(int a){

	int vysledek = 1;
	for(int i=1; i<=a; i++){
		vysledek *= i;
	}
	return vysledek;
}

int main(void)
{
	int n,k;
	printf("Zadejte horni cast: ");
	scanf("%d", &n);
	printf("Zadejte dolni cast: ");
	scanf("%d", &k);

	int kombCislo = faktorial(n)/(faktorial(k)*faktorial(n-k));
	printf("vysledek: %d", kombCislo);
	
	return 0;
}