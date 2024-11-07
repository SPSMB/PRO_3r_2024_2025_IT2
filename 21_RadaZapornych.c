#include "stdio.h"
#pragma warning(disable:4996)

int main(void)
{
	
	int rada[10];
	int velikost = 10;
	int m_zacatek = 0; // zacatek nejdelsi rady
	int m_delka = 0; // delka nejdelsi rady
	int zacatek = 0; // zacatek aktualni rady
	int delka = 0; // delka aktualni rady

	// 1. krok - nacitam hodnoty od uzivatele
	printf("Zadejte 10 cisel: ");
	for(int i=0; i < velikost; i++){
		scanf("%d", &rada[i]);
	}

	// 2. krok - hledam zapornou radu
	for (int j = 0; j < velikost; ++j){
		if(rada[j] < 0){
			delka++;
			if(delka == 1){
				zacatek = j; // zapamatuji si zacatek aktualni rady
			}
		} else {
			if(delka > m_delka){
				m_delka = delka;
				m_zacatek = zacatek;
			}
			delka = 0;
		}
	}
	if(delka > m_delka){
		m_delka = delka;
		m_zacatek = zacatek;
	}

	printf("Reseni: ");
	// 3 krok - vypis
	for (int k = m_zacatek; k < m_zacatek + m_delka; k++){
		printf("%d ", rada[k]);
	}
	
	return 0;
}
