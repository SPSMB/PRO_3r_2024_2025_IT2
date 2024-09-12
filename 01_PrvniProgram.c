#include "stdio.h"

int main(void){
	
	int rychlost; // deklarace
	int * adr_rychlost;

	adr_rychlost = &rychlost;
	rychlost = 25;
	rychlost = rychlost * 2;

	printf("Rychlost: %dkm/h\n", rychlost);
	printf("Adresa rychlost: %p\n", &adr_rychlost);
	printf("Rychlost z adresy: %d\n", *adr_rychlost);
	

	return 0;
}