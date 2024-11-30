#include "stdio.h"
#include "string.h"
#pragma warning(disable:4996)

int main(){
	
	char b[50] = "";
	char c[50];

	// 1 ZMENA obsahu
	strncpy(b, "Stredni prumyslova skola", 24);
	printf("%s\n", b);

	// 2 kopirovani
	strncpy(c, b, 50);
	printf("%s\n", c);

	// 3 porovnavani
	int vysledek = strcmp(b, "Sdredni prumyslova skola");
	printf("Porovnani: %d\n", vysledek);	

	// 4 zjisteni delky
	printf("Delka sizeof: %d\n", sizeof(b));
	printf("Delka strlen: %d\n", strlen(b));

	// 5 zjisteni znaku na pozici - []
	printf("Znak na pozici 2 je %c.\n", b[2]);
	printf("Znak na pozici 5 je %c.\n", b[5]);
	
	// 6 pripojeni retezce k jiz existujicimu retezci
	strcat(b, " je dnes ");
	int otevrena = 1;
	char ot[20] = "otevrena";
	char uz[20] = "uzavrena";
	if(otevrena){
		strcat(b, ot);
	} else {
		strcat(b, uz);
	}
	printf("%s\n", b);

	return 0;
}