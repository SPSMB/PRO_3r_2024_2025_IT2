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
		chybneRadky += nacti1Radek(soubor, tabulka[r-chybneRadky]);
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

void alokujTabulku(int *** tabulka, int pRadku, int pSloupcu){
	*tabulka = (int **) malloc(pRadku * sizeof(int *));
	if(*tabulka == NULL){
		printf("Nepovedlo se alokovat pamet pro tabulku.\nProgram konci.\n");
		exit(1);
	}

	for(int i = 0; i < pRadku; i++){
		(*tabulka)[i] = (int *) malloc(pSloupcu * sizeof(int));
		if((*tabulka)[i] == NULL){
			printf("Nepovedlo se alokovat pamet pro tabulku.\nProgram konci.\n");
			exit(1);
		}
	}
}

void uvolniPamet(int ** tabulka, int pRadku){
	// uvolneni pameti - radky
	for(int i = 0; i < pRadku; i++){
		free(tabulka[i]);
	}
	// uvolneni pameti - cela tabulka
	free(tabulka);
}

/* analyza delky kroku podle veku bez ohledu na ostani ukazatele */
void analyza1(int ** tabulka, int pRadku){
    int pocetDo30 = 0; int pocetDo60 = 0; int pocetNad60 = 0;
    int soucetDo30 = 0; int soucetDo60 = 0; int soucetNad60 = 0;
    for(int r = 0; r < pRadku; r++){
       if(tabulka[r][1] <= 30){
           pocetDo30++;
           soucetDo30+=tabulka[r][3];
       } else if(tabulka[r][1] > 60){
           soucetNad60+=tabulka[r][3];
           pocetNad60++;
       } else {
           pocetDo60++;
           soucetDo60+=tabulka[r][3];
       }
    }
    printf("Prumerna delka kroku ve skupine do 30:  %.2f\n", (double)soucetDo30/(double)pocetDo30 );
    printf("Prumerna delka kroku ve skupine do 60:  %.2f\n", (double)soucetDo60/pocetDo60 );
    printf("Prumerna delka kroku ve skupine nad 60: %.2f\n", (double)soucetNad60/pocetNad60 );
}

int main(int argc, char ** argv){

	// soubor CSV se zada jako parametr programu do prikazove radky
	if(argc != 2){
		printf("Jako parametr musi byt zadan nazev CSV souboru!\n");
		return 0;
	}
	int pRadku = pocetRadku(argv[1]);
	int pSloupcu = 4;
	int ** tabulka;

	alokujTabulku(&tabulka, pRadku, pSloupcu);
	nactiDataZeSouboru(argv[1], tabulka, &pRadku);
	printf("Po nacteni dat mam %d platnych radku.\n", pRadku);
	vypis2DPole(tabulka, pRadku, pSloupcu);
	analyza1(tabulka, pRadku);

	uvolniPamet(tabulka, pRadku);
	return 0;
}