#include "stdio.h"
#include "stdlib.h"

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

// Vytvoříme jednoduchý program, který načte od uživatele libovolný počet čísel. 
// Program bude následně v zadaných číslech vyhledávat a zjistí, 
// kolikrát bylo nějaké číslo zadáno:

void vypisPole(int * pole, float vel){
	for (int i = 0; i < vel; ++i)
	{
		printf("%d, ",pole[i]); 

	}
	printf("\n");
}
	

void pridejCisla(int ** starePole, float * staraVel){

	printf("Kolik cisel chcete pridat? ");
	float pridat = 0.0;
	scanf("%f", &pridat);
	float novaVelikost = *staraVel + pridat;
	int * novePole = NULL;

	// musim rozlisit, jestli uz pole existuje nebo jeste neexistuje
	if(*staraVel == 0){
		printf("Prvni cesta\n");
		novePole = (int *) malloc((size_t) novaVelikost * sizeof(int));
		printf("Adresa nove pole:  %p\n", novePole);
		if(novePole == NULL){
			printf("Alokace se nezdarila. Nic se nestalo.\n");
			return;
		}
		*starePole = novePole;
	} else {
		printf("Druha cesta\n");
		printf("Nova velikost: %.0f\n", novaVelikost);
		novePole = (int *) realloc(*starePole, (size_t) novaVelikost * sizeof(int));
		printf("Adresa stare pole: %p\n", *starePole);
		printf("Adresa nove pole:  %p\n", novePole);
		if(novePole == NULL){
			printf("Realokace se nezdarila. Nic se nestalo.\n");
			return;
		} else {
			*starePole = novePole;
		}
	}

	printf("Alokovano %.0f bytu.\n", (float) novaVelikost * sizeof(int));
	printf("Zadejte cisla, oddelujte mezerami:\n");
	for(int i=(int)*staraVel; i<novaVelikost; i++){
		scanf("%d", &novePole[i]);
	}
	printf("Konec funkce PridejCisla.\n");
	*staraVel = novaVelikost;
}

void hledejCislo(int * pole, float delka){

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
	float vel = 0;
	char volba = 'x';
	do{
		printf("Zadej P (pridej) H (hledej) V (vypis) K (konec): ");
		scanf(" %c", &volba);
		while(getchar()!='\n'); // vycisteni vstupu
		if(volba == 'P'){
			pridejCisla(&pole, &vel);
		} else if(volba == 'H'){
			hledejCislo(pole, vel);
		} else if(volba == 'V'){
			 vypisPole(pole, vel);
		} else if(volba == 'K' || volba == 'k'){
			printf("Program konci.\n");
			break;
		} else {
			printf("Toto neni platne zadani. Zkus znovu.\n");
		}
	} while(volba != 'K' || volba != 'k');

	free(pole);
	return 0;
}
