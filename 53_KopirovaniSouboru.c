#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

// program pro kopirovani souboru

// funkce pro bezpecne otevreni souboru
FILE * otevriSoubor(char * nazev, char * mode){
	FILE * soubor = fopen(nazev, mode);
	if(soubor == NULL){
		printf("Nelze otevrit soubor %s\n", nazev);
		exit(1);
	}
	return soubor;
}

int main(int argc, char ** argv){

	if(argc != 3){
		printf("Neni zadano spravny pocet parametru. Ma byt 3: KOP ODKUD KAM\n");
		return 1;
	}
	FILE * soubor1 = otevriSoubor(argv[1], "r");
	FILE * soubor2 = otevriSoubor(argv[2], "w");

	char radek[1000];
	while(1){
		char * hodnota = fgets(radek, 1000, soubor1);
		if(hodnota == NULL){
			break;
		}
		fputs(radek, soubor2);
	}

	printf("Soubor %s byl uspesne vytvoren.\n", argv[2]);

	fclose(soubor1);
	fclose(soubor2);
	
	return 0;

}