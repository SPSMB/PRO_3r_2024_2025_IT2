#include "stdio.h"

int main(void){

	/*
	int i1;
	int * pi1;
	double d1;
	double * pd1;
	char c1;
	char * pc1;

	// Zjistim velikost v B
	int velikost1 = sizeof(i1);
	int velikost2 = sizeof(pi1);
	int velikost3 = sizeof(d1);
	int velikost4 = sizeof(pd1);
	int velikost5 = sizeof(c1);
	int velikost6 = sizeof(pc1);

	printf("Velikost i1 : %d\n", velikost1);
	printf("Velikost pi1: %d\n", velikost2);
	printf("Velikost d1 : %d\n", velikost3);
	printf("Velikost pd1: %d\n", velikost4);
	printf("Velikost c1 : %d\n", velikost5);
	printf("Velikost pc1: %d\n", velikost6);

	unsigned int k1 = 3254927976;
	int k2 = (int) k1;
	printf("k2: %d\n", k2);
	printf("k1: %u\n", k1);
	*/

	// Nacitani vstupu

	int prumer;
	int obvod;
	char str[81];

	printf("Zadej prumer a obvod: ");
	scanf_s("%d %d", &prumer, &obvod);

	int * u1 = & prumer;

	printf("Zadej prumer znovu: ");
	scanf_s("%d", u1);

	printf("Zadej retezec znaku bez mezer: ");
	scanf("%81s", str);

	printf("Ulozeno prumer: %d\n", *u1);
	printf("Ulozeno obvod : %d\n", obvod);
	printf("Ulozeny retezec: %s\n", str);

	return 0;
}