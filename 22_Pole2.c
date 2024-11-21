#include "stdio.h"
#pragma warning(disable:4996)

void vypisPole(int pole[], int vel){
	for(int i = 0; i < vel; i++){
		printf("%d ", pole[i]);
	}
	printf("\n");
}

void vypisPoleOdDo(int * pole, int start, int cil){
	for (int k = start; k <= cil; k++){
		printf("%d ", pole[k]);
	}
	printf("\n");
}

int main(void)
{
	
	int c[50] = {10, 9, 8};
	//vypisPoleOdDo(c, 0, sizeof(c)/sizeof(int)-1);

	int d[20];
	//vypisPoleOdDo(d, 0, sizeof(d)/sizeof(int)-1 );
	
	int x = 20;
	int e[x]; // pole e o velikosti x

	vypisPole(c, 100);
	vypisPole(d, 100);
	printf("Kontrola\n");
	return 0;
}
