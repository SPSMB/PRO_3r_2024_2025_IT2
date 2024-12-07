#include "stdio.h"
#include "string.h"
#include "ctype.h"

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

int main(void)
{
	
	// Načtěte řetězec náhodných znaků ze 
	// standardního vstupu. Uložte si ho. 
	// Vypište z tohoto řetězce na první řádek jen
	// číslice 0 – 9 a na druhý řádek vše ostatní.

	char vstup[200];
	char cisla[200] = "";
	char znaky[200] = "";

	printf("Zadejte znaky: ");
	scanf("%s", vstup);
	printf("Vstup: %s\n", vstup);

	int pocCisla = 0;
	int pocZnaky = 0; 

	for(unsigned int i=0; i<strlen(vstup); i++){
		if(isdigit(vstup[i])){
			cisla[pocCisla] = vstup[i];	
			pocCisla++;		
		} else {
			znaky[pocZnaky++] = vstup[i];
		}
	}
	// ukonceni retezcu znakem \0
	cisla[pocCisla] = '\0';
	znaky[pocCisla] = '\0';

	printf("Cisla: %s\n", cisla);
	printf("Znaky: %s\n", znaky);
	return 0;
}
