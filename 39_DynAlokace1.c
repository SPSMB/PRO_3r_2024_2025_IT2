#include "stdio.h"
#include "stdlib.h"

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

// Vytvoříme jednoduchý program, který načte od uživatele libovolný počet čísel. 
// Program bude následně v zadaných číslech vyhledávat a zjistí, 
// kolikrát bylo nějaké číslo zadáno:

void vypisPole(int * pole, int vel);
void pridejCisla(int ** starePole, int * staraVel){

	printf("Kolik cisel chcete pridat? ");
	int pridat=0;
	scanf("%d", &pridat);
	int novaVelikost = *staraVel + pridat;
	int * novePole = NULL;

	// musim rozlisit, jestli uz pole existuje nebo jeste neexistuje
	if(staraVel == 0){
		*starePole = (int *) calloc(*staraVel, sizeof(int));
	} else {
		novePole = (int *) realloc(*starePole, *staraVel);
		if(novePole != NULL){
			*starePole = novePole;
		}
	}

	printf("Zadejte cisla, oddelujte mezerami:\n");
	for(int i=*staraVel; i<novaVelikost; i++){
		scanf("%d", &novePole[i]);
	}
	*staraVel = novaVelikost;
}

void hledejCislo(int * pole, int delka){

	int hledam;
	printf("Jake cislo chcete vyhledat? ");
	scanf("%d", &hledam);

	int citac = 0;
	for(int j=0; j<delka; j++){
		//printf("Hledam: %d, ", hledam);
		//printf("J:%d Hodnota:%d\n", j, poleCisel[j]);
		if(pole[j] == hledam){
			citac++;
		}
	}

	printf("Hledane cislo %d se v poli nachazi %dx.\n",
		hledam, citac);
}


int main(){

	int * pole = NULL;
	int vel = 0;
	char volba = 'x';
	do{
		printf("Zadej P (pridej) H (hledej) V (vypis) K (konec): ");
		scanf("%c", &volba);
		if(volba == 'P'){
			pridejCisla(&pole, &vel);
		} else if(volba == 'H'){
			hledejCislo(pole, vel);
		} else if(volba == 'V'){
			// vypisPole(pole, vel);
		} else if(volba == 'K'){
			printf("Program konci.\n");
		} else {
			printf("Toto neni platne zadani. Zkus znovu.\n");
		}
	} while(volba != 'K' || volba != 'k');

	/*
	int velikost;
	printf("Kolik cisel chcete zadat? ");
	scanf("%d", &velikost);

	int * poleCisel = (int *) calloc(velikost, sizeof(int));

	printf("Zadejte cisla, oddelujte mezerami:\n");
	for(int i=0; i<velikost; i++){
		scanf("%d", &poleCisel[i]);
	}
	
	int hledam;
	printf("Jake cislo chcete vyhledat? ");
	scanf("%d", &hledam);

	int citac = 0;
	for(int j=0; j<velikost; j++){
		//printf("Hledam: %d, ", hledam);
		//printf("J:%d Hodnota:%d\n", j, poleCisel[j]);
		if(poleCisel[j] == hledam){
			citac++;
		}
	}

	printf("Hledane cislo %d se v poli nachazi %dx.\n",
		hledam, citac);

	int n;
	printf("Pro ukonceni programu zadejte jakekoliv cislo: ");
	scanf("%d", &n);
	*/
	free(pole);
	return 0;
}
