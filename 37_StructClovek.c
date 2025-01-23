#include "stdio.h"
#include "string.h"

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

typedef struct datum {
	int den;
	int mesic;
	int rok;
} Datum;

typedef struct clovek {
	int vek;
	char jmeno[20];
	Datum datumNarozeni;
} Clovek;

void vypisDatum(Datum * d1){
	printf("%d.%d.%d\n", 
		d1->den, d1->mesic, d1->rok);
}

int main(){
	
	Clovek osoba;
	Clovek zajezd[30];
	osoba.datumNarozeni.rok = 1990;
	osoba.datumNarozeni.mesic = 3;
	osoba.datumNarozeni.den = 15;
	strncpy(osoba.jmeno, "Tom", 19);
	zajezd[0]=osoba;

	printf("%s\n", zajezd[0].jmeno);
	vypisDatum(&osoba.datumNarozeni);

	
	return 0;
}
