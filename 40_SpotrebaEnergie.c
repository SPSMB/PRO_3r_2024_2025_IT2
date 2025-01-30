#include "stdio.h"
#include "string.h"

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

// program pocita cenu ya elektrickou energii podle zadanych parametru

typedef struct cas{
	int hodiny;
	int minuty;
	int sekundy;
} Cas;

int main(void){

	float napeti;
	float proud;
	Cas casSpotreby;
	float casSpotrebyVHodinach;
	float celkovaCena; // vystup programu
	float cenaZaJednotku;
	float vykon;
	float spotreba;

	char odpoved[10];

	printf("Znate vykon spotrebice? (ANO/NE): ");
	scanf("%s", odpoved);
	if(strcmp(odpoved, "ANO") == 0){ // shodne
		printf("Zadejte vykon ve W: ");
		scanf("%f", &vykon);
	} else { // rozdilne
		printf("Zadejte napeti: ");
		scanf("%f", &napeti);
		printf("Zadejte proud: ");
		scanf("%f", &proud);
		vykon = napeti * proud; // watty
	}
	
	vykon /= 1000; // prepocet na kW
	
	printf("Jak dlouho zarizeni bezi? Zadejte hodiny: ");
	scanf("%d", &casSpotreby.hodiny);
	printf(" Zadejte minuty: ");
	scanf("%d", &casSpotreby.minuty);
	printf(" Zadejte sekundy: ");
	scanf("%d", &casSpotreby.sekundy);
	casSpotrebyVHodinach = casSpotreby.hodiny 
		+ ((float)casSpotreby.minuty/60) 
		+ (casSpotreby.sekundy/3600.0f);

	printf("Jaka je vase cena za kWh energie?: ");
	scanf("%f", &cenaZaJednotku);

	spotreba = vykon * casSpotrebyVHodinach;
	celkovaCena = spotreba * cenaZaJednotku;

	printf("Vase celkova cena je %.2f Kc.\n", celkovaCena);

	return 0;
}