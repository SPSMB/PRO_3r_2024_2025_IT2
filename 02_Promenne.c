#include "stdio.h"

int main(void){

	int teplota; // tady je deklarace
	teplota = 30; // tady inicializace

	// deklarace spolu s  inicializaci na 1 radku
	int * adr_teplota = & teplota;

	// printf("Adresa je: %d\n", adr_teplota);
	// printf("Adresa je: %x\n", adr_teplota);
	printf("1) Adresa je: %p\n", adr_teplota);

	// resetovani ukazatele
	adr_teplota = NULL;
	printf("2) Adresa je: %p\n", adr_teplota);

	// Vypis 

	printf("Procento: %%\n");
	printf("Zpetne lomitko: \\\n");

	double vyska = 1.55;

	printf("Vyska: >%6.3f<\n", vyska);

	int c1 = 5000111222;
	printf("c1: %d\n", c1);
	printf("c1: %x\n", c1);

	int c2 = 11;
	int c3 = 0x2;
	int c4 = c2/c3;

	printf("c4: %d\n", c4);

	char z1 = 'a';

	printf("Znak z1: %c\n", z1);
	printf("Znak z1: %x\n", z1);
	printf("Znak z1: %d\n", z1);

	printf("Integer jako znak: >%c<\n", teplota);

	printf("Zpetne lomitko: \\\n");
	printf("Zpetne lomitko: %c\n", 0x5C);

	// float
	printf("--------------\n");

	float f1 = 85000.003F;
	double d1 = 85000.003;
	double d2 = 1000002;

	printf("f1 %%f: %f\n", f1);
	printf("f1 %%e: %e\n", f1);
	printf("f1 %%g: %g\n", f1);

	printf("d1 %%f: %.3f\n", d1);
	printf("d1 %%e: %e\n", d1);
	printf("d1 %%g: %.3g\n", d1);

	printf("d2 %%f: %.3f\n", d2);
	printf("d2 %%e: %e\n", d2);
	printf("d2 %%g: %.3g\n", d2);

	return 0;
}