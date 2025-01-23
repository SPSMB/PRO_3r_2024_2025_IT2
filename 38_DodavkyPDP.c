#include "stdio.h"
#include "string.h"

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

// Přepravní firma PDP uchovává záznamy o všech svých dodávkách. Pro každou dodávku jsou uchovávány tyto parametry:
// SPZ, kapacita v m3, dojezd, rok výroby, jméno řidiče

// Vytvořte pole struktur, kam budete informace o všech dodávkách ukládat a naplňte ho informacemi alespoň o 3 dodávkách.
// Pak vytvořte funkci nejDojezd(), která přehledně vypíše všechny informace o dodávce s největším dojezdem.

typedef struct dodavka {
	char spz[10];
	double kapacita;
	int dojezd;
	int rok;
	char jmeno[30];
} Dodavka;

void vypisDodavku(Dodavka * d){
	printf("SPZ:      %s\n", d->spz);
	printf("Jmeno:    %s\n", d->jmeno);
	printf("Rok:      %d\n", d->rok);
	printf("Kapacita: %.2f\n", d->kapacita);
	printf("Dojezd:   %d\n", d->dojezd);
}

void nejDojezd(Dodavka * seznam, int pocet){

	int nejvetsiDojezd = 0;
	int nejIndex = 0;
	for(int i = 0; i < pocet; i++){
		if(seznam[i].dojezd > nejvetsiDojezd){
			nejvetsiDojezd = seznam[i].dojezd;
			nejIndex = i;
		}
	}

	// vypisu dodavku s nejvetsim dojezdem
	vypisDodavku(&seznam[nejIndex]);

}

int main(){

	Dodavka pdp[3];
	strncpy(pdp[0].spz, "3A9 15-98", 10);
	strncpy(pdp[0].jmeno, "Karel", 6);
	pdp[0].dojezd = 920;
	pdp[0].rok = 2015;
	pdp[0].kapacita = 15.6;
	strncpy(pdp[1].spz, "7A6 11-13", 10);
	strncpy(pdp[1].jmeno, "Josef", 6);
	pdp[1].dojezd = 620;
	pdp[1].rok = 2021;
	pdp[1].kapacita = 11.6;
	strncpy(pdp[2].spz, "2AP 06-08", 10);
	strncpy(pdp[2].jmeno, "Jaromir", 8);
	pdp[2].dojezd = 910;
	pdp[2].rok = 2024;
	pdp[2].kapacita = 10.1;

	nejDojezd(pdp, 3);
	
	return 0;
}
