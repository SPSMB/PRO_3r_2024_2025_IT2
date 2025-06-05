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

typedef struct statistiky {
	int soucet;
	int prumer;
} Statistiky;

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)


// funkce filtr vypisuje vsechny polozky databaze, ktere splnuji zadane podminky
// parametry:
//  - db - pole zaznamu, ktere mam v databazi
//  - vel - velikost pole *db
//  - kat - vekova kategorie, kterou zadal uzivatel
//  - dat1 - datum od kdy chce uzivatel filtrovat
//  - dat2 - datum do kdy chce uzivatel filtrovat
//  - vypis - kdyz je 1, vypisuji, kdyz je 0, nevypisuji
void filtr( Zaznam * db, int vel, char * kat, char * dat1, char * dat2, int vypis, Statistiky * stat){


	int counter = 0;
	int soucet = 0;
	if(vypis) printf("|ID   |Rok  |Tyden|Hodn.|Kategorie |Datum od  |Datum do  |\n");
	if(vypis) printf("----------------------------------------------------------\n");
	for(int i=0;  i < vel ; i++){
		if(kat[0] == db[i].vek_txt[0] && 
			kat[1] == db[i].vek_txt[1] &&
			strcmp(db[i].cas_do, dat1) >= 0 &&
			strcmp(db[i].cas_od, dat2) <= 0){
			if (counter%15 == 0){
				if(vypis) printf("|ID   |Rok  |Tyden|Hodn.|Kategorie |Datum od  |Datum do  |\n");
			}

			if(vypis) printf("|%5d|%5d|%5d|%5d|%10s|%10s|%10s|\n", 
				i, db[i].rok, db[i].tyden, db[i].hodnota, 
				db[i].vek_txt, db[i].cas_od, db[i].cas_do);
			counter++;
			soucet+=db[i].hodnota;
		}
	}
	for(int z=1;z<=58;z++){if(vypis) printf("-");}if(vypis)printf("\n");
	if(counter == 0){
		if(vypis) printf("Zadanemu filtru neodpovida zadny zaznam.\n");
	} else {
		if(vypis) printf("Celkem nalezeno %d zaznamu.\n\n", counter);
	}
	// vypocet prumeru
	int prumer = soucet / counter;
	(*stat).soucet = soucet;
	stat->prumer = prumer;
}

void analyzaCovidu1(Zaznam * databaze, int vel){
	char kat[D_TEXT] = "celkem";
	char dat1[D_TEXT] = "2011-01-01";
	char dat2[D_TEXT] = "2019-12-31";
	Statistiky s2, s3;
	// krok 1 - zjistim prumer v letech bez covidu
	filtr(databaze, vel, kat, dat1, dat2, 0, &s2);
	int prumerBezCovidu = s2.soucet / 9;
	printf("Prumerny pocet zemrelych za 1 rok bez covidu je %d\n", prumerBezCovidu);

	// krok 2 - zjistim soucet za roky 2020 - 2022
	filtr(databaze, vel, kat, "2020-01-01", "2022-12-31", 0, &s3);
	int soucetBehemCovidu = s3.soucet;
	printf("Soucet zemrelych za roky 2020-2022 je %d\n", soucetBehemCovidu);

	// krok 3 - zjistim pocet zemrelych navic
	int zemreliNavic = soucetBehemCovidu - 3*prumerBezCovidu;
	printf("Pocet mrtvych navic behem covidu: %d\n\n", zemreliNavic);
}

// parametry 
// databaze - ukazatel na databazi
// velikost - velikost databaze (pocet prvku)
void obsluhaUzivatele(Zaznam * databaze, int velikost){

	char vstup;
	Statistiky s1;
	char kat[D_TEXT]; char dat1[D_TEXT]; char dat2[D_TEXT];
	while(1){
		printf("Zadejte volbu: \n");
		printf(" F <kategorie> <od> <do>: Filtruje kategorii od data do data \n");
		printf(" S <kategorie> <od> <do>: Soucet v kategorii od data do data \n");
		printf(" P <kategorie> <od> <do>: Prumer v kategorii od data do data \n");
		printf(" A - analyzaCovidu1");
		printf(" K: Ukonci program\n");
		scanf("%c", &vstup);
		if(vstup == 'F'){
			scanf("%s %s %s", kat, dat1, dat2);
			filtr(databaze, velikost, kat, dat1, dat2, 1, &s1);
		} else if(vstup == 'S'){
			scanf("%s %s %s", kat, dat1, dat2);
			filtr(databaze, velikost, kat, dat1, dat2, 0, &s1);
			printf("Celkovy pocet zemrelych: %d\n\n", s1.soucet);
		} else if(vstup == 'P'){
			scanf("%s %s %s", kat, dat1, dat2);
			filtr(databaze, velikost, kat, dat1, dat2, 0, &s1);
			printf("Prumerny pocet zemrelych: %d\n\n", s1.prumer);
		} else if(vstup == 'A'){
			analyzaCovidu1(databaze, velikost);
		} else if (vstup == 'K'){
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