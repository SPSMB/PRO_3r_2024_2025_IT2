#include "stdio.h"
#pragma warning(disable:4996)

int main(void){
	
	// prestupny rok
	int rok;
	printf("Zadejte rok: ");
	scanf("%d", &rok);

	if(rok%4==0 && (rok%100!=0 || rok%400==0)){
		printf("Rok JE prestupny.\n");
	} else {
		printf("Rok NENI prestupny.\n");
	}

	return 0;
}