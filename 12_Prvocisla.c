#include "stdio.h"
#include "math.h"
#pragma warning(disable:4996)

int main(void){

	int vstup;
	printf("Zadejte cislo: ");
	scanf("%d, ", &vstup);
	int citac = 0;
	int delitelExistuje = 0;

	for(int i = 2; i <= sqrt(vstup); i++){
		if( vstup%i == 0){
			printf("Cislo je delitelne %d, proto neni prvocislo.\n", i);
			delitelExistuje++;
			break;
		}
		citac++;
	}

	if(delitelExistuje == 0){
		printf("Cislo %d je prvocislo.\n", vstup);
	}
	printf("Citac: %d\n", citac);

	return 0;
}