#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELKA 300
#define D_TEXT 12

typedef struct zaznam {
	int hodnota;
	int rok;
	int tyden;
	char cas_od[D_TEXT];
	char cas_do[D_TEXT];
	char vek_txt[D_TEXT];
} Zaznam;

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

void filtr( Zaznam * db, int vel, char * kat, char * dat1, char * dat2){

	int counter = 0;
	for(int i=0;  i < vel ; i++){
		if(kat[0] == db[i].vek_txt[0] && 
			kat[1] == db[i].vek_txt[1] &&
			strcmp(db[i].cas_do, dat1) >= 0 &&
			strcmp(db[i].cas_od, dat2) <= 0){

			printf("|%5d|%5d|%5d|%5d|%10s|%10s|%10s|\n", 
				i, db[i].rok, db[i].tyden, db[i].hodnota, 
				db[i].vek_txt, db[i].cas_od, db[i].cas_do);
			counter++;
		}
	}
	printf("Celkem nalezeno %d zaznamu.\n", counter);
}

// parametry 
// databaze - ukazatel na databazi
// velikost - velikost databaze (pocet prvku)
void obsluhaUzivatele(Zaznam * databaze, int velikost){

	char vstup;
	while(1){
		printf("Zadejte volbu: \n");
		printf(" F <kategorie> <od> <do>: Filtruje kategorii od data do data \n");
		printf(" K: Ukonci program\n");
		scanf("%c", &vstup);
		if(vstup == 'F'){
			char kat[D_TEXT]; char dat1[D_TEXT]; char dat2[D_TEXT];
			scanf("%s %s %s", kat, dat1, dat2);
			filtr(databaze, velikost, kat, dat1, dat2);
		} else if(vstup == 'K'){
			break;
		} else { // chyba
			printf("Toto neni platny vstup.\n");
		}
		while(getchar()!='\n');
	}
}

FILE * otevriSoubor(const char * filename, char * mode){
	FILE * soubor = fopen(filename, mode);
	// pokud se nepovedlo otevrit soubor
	if(soubor == NULL){
		printf("Soubor %s se nepovedlo otevrit. Program konci.\n", filename);
		exit(1); // konec programu
	} else {
		return soubor;
	}
}

// vraci pocet radku
int pocetRadku(const char * jmenoSouboru){

	FILE * soubor = otevriSoubor(jmenoSouboru, "r");
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

void alokujPamet(Zaznam ** databaze, int pRadku){

	*databaze = (Zaznam *) malloc(pRadku * sizeof(Zaznam));

}

void uvolniPamet(Zaznam ** databaze){

	free(*databaze);
	
}

void zpracujRadek(char radek[DELKA], int cRadku, Zaznam * databaze){
	char tmp[12];
	int i = 0; /* index do pole radek */
	int t = 0; /* index do pole tmp */
	int s = 0; /* pocitadlo sloupcu */

	for(; s<=12; i++){
		if(radek[i] == ','){
			tmp[t] = '\0'; // ukoncuji retezec
			if(s == 1) databaze[cRadku].hodnota = atoi(tmp);
			if(s == 7) databaze[cRadku].rok = atoi(tmp);
			if(s == 8) databaze[cRadku].tyden = atoi(tmp);
			if(s == 10) strncpy(databaze[cRadku].cas_od, tmp, 12);
			if(s == 11) strncpy(databaze[cRadku].cas_do, tmp, 12);
			if(s == 12) strncpy(databaze[cRadku].vek_txt, tmp, 12);
			t = 0; // reset ukazatele do tmp
			s++; // zvysuji index sloupce
		} else if(radek[i] == '"'){
			continue;
		} else if(s==1 || s==7 || s==8 || s==10 || s==11 || s==12){
			tmp[t]=radek[i];
			t++;
		}
	}
}

int main(int argc, char ** argv){

	if(argc != 2){
		printf("Musi byt zadan nazev CSV souboru!\n");
		return 1;
	}

	Zaznam * databaze;

	// zjistim pocet radku
	int pRadku = pocetRadku(argv[1]);
	alokujPamet(&databaze, pRadku);
	
	char buf[DELKA];
	FILE * f = otevriSoubor(argv[1], "r");
	fscanf(f, "%*[^\n]\n");

	for(int i=1; fgets(buf, DELKA, f) && i<pRadku ; i++){
		zpracujRadek(buf, i, databaze);
		//printf("%d, %d, %d, %s, %s, %s\n", 
		//	databaze[i].rok, databaze[i].tyden, databaze[i].hodnota, 
		//	databaze[i].vek_txt,databaze[i].cas_od, databaze[i].cas_do);
	}
	fclose(f);

	obsluhaUzivatele(databaze, pRadku);

	uvolniPamet(&databaze);
	printf("Program konci\n");
	return 0;
}