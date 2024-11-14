#include "stdio.h"
#pragma warning(disable:4996)

// vraci 0, kdyz chyba, jinak 1
int nacitiCisla(int * pole, int rozsah){

	printf("Zadejte 10 cisel: ");
	int kontrola = 0;
	for(int i=0; i < rozsah; i++){
		kontrola = scanf("%d", &pole[i]);
		if(kontrola == 0){
			printf("Chybny vstup.\n");
			return 0;
		}
	}
	return 1;
}

void hledamRadu(int * pole, int rozsah, int * m_zacatek, int * m_delka){

	int zacatek = 0; // zacatek aktualni rady
	int delka = 0; // delka aktualni rady

	// 2. krok - hledam zapornou radu
	for (int j = 0; j < rozsah; ++j){
		if(pole[j] < 0){
			delka++;
			if(delka == 1){
				zacatek = j; // zapamatuji si zacatek aktualni rady
			}
		} 
		if(pole[j] >= 0) {
			if(delka > *m_delka){
				*m_delka = delka;
				*m_zacatek = zacatek;
			}
			delka = 0;
		}
	}
	if(delka > *m_delka){
		*m_delka = delka;
		*m_zacatek = zacatek;
	}
}

void vypisPoleOdDo(int * pole, int start, int cil){
	printf("Reseni: ");
	for (int k = start; k <= cil; k++){
		printf("%d ", pole[k]);
	}
}

int main(void)
{
	
	int rada[10];
	int velikost = 10;
	int m_zacatek = 0; // zacatek nejdelsi rady
	int m_delka = 0; // delka nejdelsi rady

	// 1. krok - nacitam hodnoty od uzivatele
	nacitiCisla(rada, velikost);

	// 2. krok - hledam zapornou radu
	hledamRadu(rada, velikost, &m_zacatek, &m_delka);

	// 3 krok - vypis
	vypisPoleOdDo(rada, m_zacatek, m_zacatek+m_delka-1);
	
	return 0;
}
