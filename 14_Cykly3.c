#include "stdio.h"
#pragma warning(disable:4996)

int main(void){

	int velikost;
	printf("Zadej velikost: ");
	scanf("%d", &velikost);

	// kdyz i*2 > velikost, tak mame zlom
	int i = 0;
	for(;i*2 < velikost; i++){
		for(int j = 0; j < i; j++) printf(" ");	
		
		printf("%d\n", i);
	}

	for(;i < velikost; i++){
		for(int k = i;k<velikost-1;k++)	printf(" ");	
		
		printf("%d\n", i);
	}

	return 0;
}