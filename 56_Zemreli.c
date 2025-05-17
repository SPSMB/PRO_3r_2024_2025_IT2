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
		*cas_od[i] = (char *) malloc(delkaRetezce*sizeof(char));
		*cas_do[i] = (char *) malloc(delkaRetezce*sizeof(char));
		*vek_txt[i] = (char *) malloc(delkaRetezce*sizeof(char));
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
	
	return 0;
}