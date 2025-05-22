#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELKA 300

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

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

void alokujPamet(int ** hodnota, int ** rok, int ** tyden, 
	char *** cas_od, char *** cas_do, char *** vek_txt, int pRadku){

	int delkaRetezce = 12;

	*hodnota = (int *) malloc(pRadku * sizeof(int)); 
	*rok = (int *) malloc(pRadku * sizeof(int)); 
	*tyden = (int *) malloc(pRadku * sizeof(int)); 
	*cas_od = (char **) malloc(pRadku * sizeof(char*));
	*cas_do = (char **) malloc(pRadku * sizeof(char*));
	*vek_txt = (char **) malloc(pRadku * sizeof(char*));

	for(int i = 0; i < pRadku; i++){
		(*cas_od)[i] = (char *) malloc(delkaRetezce*sizeof(char));
		(*cas_do)[i] = (char *) malloc(delkaRetezce*sizeof(char));
		(*vek_txt)[i] = (char *) malloc(delkaRetezce*sizeof(char));
	}

}

void uvolniPamet(int ** hodnota, int ** rok, int ** tyden, 
	char *** cas_od, char *** cas_do, char *** vek_txt, int pRadku){

	for(int i = 0; i<pRadku; i++){
		free((*cas_od)[i]);
		free((*cas_do)[i]);
		free((*vek_txt)[i]);
	}
	free(*hodnota);
	free(*rok);
	free(*tyden);
	free(*cas_od);
	free(*cas_do);
	free(*vek_txt);
	
}

void zpracujRadek(char radek[DELKA], int cRadku, int * hodnota, int * rok, int * tyden, 
	char ** cas_od, char ** cas_do, char ** vek_txt){
	char tmp[12];
	int i = 0; /* index do pole radek */
	int t = 0; /* index do pole tmp */
	int s = 0; /* pocitadlo sloupcu */

	for(; s<=12; i++){
		if(radek[i] == ','){
			tmp[t] = '\0'; // ukoncuji retezec
			if(s == 1) hodnota[cRadku] = atoi(tmp);
			if(s == 7) rok[cRadku] = atoi(tmp);
			if(s == 8) tyden[cRadku] = atoi(tmp);
			if(s == 10) strncpy(cas_od[cRadku], tmp, 12);
			if(s == 11) strncpy(cas_do[cRadku], tmp, 12);
			if(s == 12) strncpy(vek_txt[cRadku], tmp, 12);
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

	int * hodnota; int * rok; int * tyden;
	char ** cas_od;	char ** cas_do;	char ** vek_txt;

	// zjistim pocet radku
	int pRadku = pocetRadku(argv[1]);
	alokujPamet(&hodnota, &rok, &tyden, &cas_od, &cas_do, &vek_txt, pRadku);
	
	char buf[DELKA];
	FILE * f = otevriSoubor(argv[1], "r");
	fscanf(f, "%*[^\n]\n");

	for(int i=1; fgets(buf, DELKA, f) && i<pRadku ; i++){
		zpracujRadek(buf, i, hodnota, rok, tyden, cas_od, cas_do, vek_txt);
		printf("%d, %d, %d, %s, %s, %s\n", rok[i], tyden[i], hodnota[i], vek_txt[i], cas_od[i], cas_do[i]);
	}
	fclose(f);

	uvolniPamet(&hodnota, &rok, &tyden, &cas_od, &cas_do, &vek_txt, pRadku);
	printf("Program konci\n");
	return 0;
}