#include "stdio.h"
#pragma warning(disable:4996)

int main(void){
	int spodni,horni;

	printf("Zadej spodni hranici: ");
	scanf("%d", &spodni);
	printf("Zadej horni hranici: ");
	scanf("%d", &horni);

	for (int i = horni*2; i >= 2*spodni; i -= 2)
	{
		printf("%d ", i);
	}

	return 0;
}