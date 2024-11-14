#include "stdio.h"
#pragma warning(disable:4996)

void vypisPoleOdDo(int * pole, int start, int cil){
	for (int k = start; k <= cil; k++){
		printf("%d ", pole[k]);
	}
	printf("\n");
}

int main(void)
{
	
	int c[50] = {10, 9, 8};
	vypisPoleOdDo(c, 0, sizeof(c)/sizeof(int)-1);

	int d[20];
	vypisPoleOdDo(d, 0, sizeof(d)/sizeof(int)-1 );
	
	return 0;
}
