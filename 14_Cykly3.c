#include "stdio.h"
#pragma warning(disable:4996)

int main(void){

	int velikost;
	printf("Zadej velikost: ");
	scanf("%d", &velikost);

	for(int i = 0 ;i < velikost; i++){
		
		// kdyz i*2 > velikost, tak mame zlom

		for(int j=0; j < i; j++){
		
			printf(" ");
		
		}
		printf("%d\n", i);
	}

	return 0;
}