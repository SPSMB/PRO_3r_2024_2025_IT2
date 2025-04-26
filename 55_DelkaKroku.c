#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

// vraci pocet radku
int pocetRadku(const char * jmenoSouboru){

	FILE * soubor = fopen(jmenoSouboru, "r");
	char c;
	int counter = 0;
	while(1){
		c = (char) fgetc(soubor);
		if(c == EOF){
			break;
		} 
		if(c == '\n'){
			counter++;
		}
	}
	printf("Soubor ma %d radku.\n", counter);
	fclose(soubor);
	return counter;
}

// vraci 1, kdyz je radek vadny, jinak 0
int nacti1Radek(FILE * soubor, int * radek){
	
	char radekTMP[20];
	fgets(radekTMP, 20, soubor);
	int delkaradku = strlen(radekTMP);
	printf("Delka radku: %d\n", delkaradku);

	if(delkaradku >= 8){
		char * token = strtok(radekTMP, ";");
		int s = 0;
		while(token != NULL){
			//printf(" token = %s\n", token);
			radek[s] = atoi(token);
			token = strtok(NULL, ";");
			s++;
		}
	} else {
		printf("Delka radku je %d, preskakuji.\n", delkaradku);
		return 1;
	}
	return 0;
}

void nactiDataZeSouboru(const char * nazev, int ** tabulka, int * pRadku){
	FILE * soubor = fopen(nazev, "r");
	int chybneRadky = 0;
	for(int r = 0; r<*pRadku; r++){
		chybneRadky += nacti1Radek(soubor, tabulka[r]);
		//chybneRadky += nacti1Radek(soubor, tabulka[r-chybneRadky]);
	}
	fclose(soubor);
	*pRadku = *pRadku - chybneRadky;
}

void vypis2DPole(int ** tabulka, int pRadku, int pSloupcu){
	for(int r = 0; r < pRadku; r++){
		for(int s = 0; s < pSloupcu; s++){
			if(s == pSloupcu - 1 ){
				printf("%10d ", tabulka[r][s]);
			} else {
				printf("%10d, ", tabulka[r][s]);
			}
		}
		printf("\n");
	}
}

int main(int argc, char ** argv){

	// soubor CSV se zada jako parametr programu do prikazove radky
	if(argc != 2){
		printf("Jako parametr musi byt zadan nazev CSV souboru!\n");
		return 0;
	}
	int pRadku = pocetRadku(argv[1]);
	int pSloupcu = 4;

	int ** tabulka = (int **) malloc(pRadku * sizeof(int *));

	for(int i = 0; i < pRadku; i++){
		tabulka[i] = (int *) malloc(pSloupcu * sizeof(int));
	}
	
	nactiDataZeSouboru(argv[1], tabulka, &pRadku);
	printf("Po nacteni dat mam %d platnych radku.\n", pRadku);
	vypis2DPole(tabulka, pRadku, pSloupcu);

	// uvolneni pameti - radky
	for(int i = 0; i < pRadku; i++){
		free(tabulka[i]);
	}
	// uvolneni pameti - cela tabulka
	free(tabulka);
	return 0;
}