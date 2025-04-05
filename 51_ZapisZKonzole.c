#include <stdio.h>
#include <errno.h>
#include <string.h>

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

int main(){

	printf("Zadavejte text:\n");

	FILE * soubor = fopen("51_vystup.txt", "w");
	if(soubor == NULL){
		printf("Soubor se nepovedlo otevrit.\n");
		return 1;
	}

	char str[2000]; // sem se ulozi obsah


	// nabirame text z konzole
	char * navratovaHodnota;
	while(1){
		navratovaHodnota = fgets(str, 1000, stdin);
		if(navratovaHodnota == NULL){
			break;
		}
		fputs(str, soubor);
	}


	// zapis 
	fclose(soubor);

	return 0;

}