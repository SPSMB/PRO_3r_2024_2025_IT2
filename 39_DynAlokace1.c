#include "stdio.h"
#include "stdlib.h"

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

// Vytvoříme jednoduchý program, který načte od uživatele libovolný počet čísel. 
// Program bude následně v zadaných číslech vyhledávat a zjistí, 
// kolikrát bylo nějaké číslo zadáno:

int main(){

	int velikost;
	printf("Kolik cisel chcete zadat? ");
	scanf("%d", &velikost);

	int * poleCisel = (int *) calloc(velikost, sizeof(int));

	/*
	printf("Zadejte cisla, oddelujte mezerami:\n");
	for(int i=0; i<velikost; i++){
		scanf("%d", &poleCisel[i]);
	}
	*/
	
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
	
	return 0;
}
