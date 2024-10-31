#include "stdio.h"
#pragma warning(disable:4996)

int faktorial(int a);
int kombinacniCislo(int dolni, int horni);


int main(void)
{
	int n;	// horni cast kombin. cisla
	int k;	// dolni cast komb. cisla

	printf("Zadejte horni cast: ");
	scanf("%d", &n);
	printf("Zadejte dolni cast: ");
	scanf("%d", &k);

	int kombCislo = kombinacniCislo(k, n);
	printf("vysledek: %d", kombCislo);
	
	return 0;
}

// -------------

int faktorial(int a){

	int vysledek = 1;
	for(int i=1; i<=a; i++){
		vysledek *= i;
	}
	return vysledek;
}

// -------------
// Funkce pocita kombinancni cislo
// (n)
// (k)
int kombinacniCislo(int dolni, int horni){
	return faktorial(horni)/(faktorial(dolni)*faktorial(horni-dolni));
}