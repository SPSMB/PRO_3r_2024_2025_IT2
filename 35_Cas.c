#include "stdio.h"
#include "string.h"

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

typedef struct datum {
	int den;
	int mesic;
	int rok;
} Datum;

void vypisDatum(Datum * d){
	printf("%d.%d.%d\n", d->den, d->mesic, d->rok);
}

Datum * pozdejsiDatum(Datum * d1, Datum * d2){
	if(d1->rok > d2->rok){
		return d1;
	} else if(d2->rok > d1->rok) {
		return d2;
	} else { // roky jsou stejne
		if(d1->mesic > d2->mesic){
			return d1;
		} else if(d2->mesic > d1->mesic){
			return d2;
		} else {
			// mesice jsou stejne
			if(d1->den > d2->den){
				return d1;
			} else {
				return d2;
			}
		}
	}
}

int main(){
	
	Datum zacatek;
	Datum konec;

	zacatek.den = 1;zacatek.mesic = 1; zacatek.rok = 2024;
	konec.den = 5; 	konec.mesic = 3;   konec.rok = 2022;

	vypisDatum(&zacatek);
	vypisDatum(&konec);

	printf("Varianta 1\n");
	Datum * pozdejsi = pozdejsiDatum(&zacatek, &konec);
	printf("Pozdejsi je ");
	vypisDatum(pozdejsi);

	// varianta 2
	printf("Varianta 2\n");
	printf("Pozdejsi je ");
	vypisDatum(pozdejsiDatum(&zacatek, &konec));
	
	return 0;
}
