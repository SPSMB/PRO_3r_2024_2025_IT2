#include "stdio.h"
#include "string.h"
#include "stdlib.h"

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

int * realokacePameti(int * puvodniPole, float * kapacita){
	printf("Jaka je nova velikost? ");
	scanf("%f", kapacita);
	int * nove_pole = realloc(puvodniPole, (size_t) *kapacita * sizeof(int));
	while(nove_pole == NULL){
		printf("Nepodarilo se alokovat pamet o velikosti %.1f B.\nZadejte jinou velikost: ", 
 			*kapacita * sizeof(int));
 		scanf("%f", kapacita);
 		nove_pole = realloc(puvodniPole, (size_t) *kapacita * sizeof(int));
	}
	printf("Ok, alokovano %.1f pameti.\n", *kapacita * sizeof(int));
	return nove_pole;
}

int main(void){

 	float kapacita = 0;
 	printf("Kolik pameti chceme? ");
 	scanf("%f", &kapacita);

 	int * pole = malloc((size_t) kapacita * sizeof(int));
 	while(pole == NULL){
 		printf("Nepodarilo se alokovat pamet o velikosti %.1f B.\nZadejte jinou velikost: ", 
 			kapacita * sizeof(int));
 		scanf("%f", &kapacita);
 		pole = malloc((size_t) kapacita * sizeof(int));
 	}

 	for(int i = 0; i<kapacita; i++){
 		pole[i] = 1;
 	}
	//free(pole); // uvolnim pamet
	printf("Ok, alokovano %.1f pameti.\n", kapacita * sizeof(int));
	
	pole = realokacePameti(pole, &kapacita);
 	for(int i = 0; i<kapacita; i++){
 		pole[i] = 1;
 	}

	scanf("%f", &kapacita);

	return 0;
}