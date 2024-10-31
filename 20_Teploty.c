#include "stdio.h"
#pragma warning(disable:4996)
#include <stdlib.h>

int compare(const void* a, const void* b) {
      
      // If a is smaller, positive value will be returned
    return (*(float*)a - *(float*)b);
}


int main(void)
{
	
	float teploty[4];
	float prumer=0 ;
	printf("zadejte teploty:\n");	
	int velikost = sizeof(teploty)/sizeof(float);

	for (int i = 0; i < velikost ; i++)
	{
		scanf("%f", &teploty[i]);
		
	}

	
	for (int i = 0; i < velikost ; i++)
	{
		printf("%.2lf\n", teploty[i]);
		prumer += teploty[i];
	}

	prumer = prumer/velikost;

	printf("prumer teplot: %f" ,prumer);

	qsort(teploty, velikost, sizeof(float), compare);

	



	return 0;
}
