#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

// program kontroluje zadane rodne cislo, ktere je dano jako parametr programu

int main(int argc, char ** argv){

	if(argc != 2){
		printf("Nespravny pocet argumentu, ma byt 2: \"RC CISLO\"");
		return 1;
	}

	// kontrola delky retezce
	if(strlen(argv[1]) != 10){
		printf("Nespravny pocet znaku, ma byt 10.\n");
		return 1;
	}

	int64_t rc = strtoll(argv[1], NULL, 10);
	printf("Zadane rodne cislo je %I64d\n", rc);

	// Kontrola delitelnosti 11 beze zbytku
	if(rc % 11 != 0){
		printf("Cislo neni delitelne 11, tudiz neni platne.\n");
		return 1;
	}


	// kontrola 2. dvojcisli
	int mesic = rc /1000000;
	mesic = mesic % 100;
	if((mesic >= 1 && mesic <=12) || (mesic >= 50 && mesic <= 62)){
		// OK 
	} else {
		printf("Mesic %d neni v poradku.\n", mesic);
		return 1;
	}


	// kontrola 3. dvojcisli
	int den = rc /10000;
	den = den % 100;
	if(den >= 1 && den <=31){
		// OK 
	} else {
		printf("Den %d neni v poradku.\n", den);
		return 1;
	}

	printf("Vase rodne cislo je platne.\n");
	return 0;

}