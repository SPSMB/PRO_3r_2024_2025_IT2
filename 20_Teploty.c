#include "stdio.h"
#pragma warning(disable:4996)
#include <stdlib.h>

int compare(const void* a, const void* b) {
      
    // If a is smaller, positive value will be returned
    if(*(float*)a - *(float*)b < 0){
    	return 1;
    } else if(*(float*)a - *(float*)b > 0){
	return -1;
    } else {
    	return 0;
    }

    //return (*(float*)a - *(float*)b);
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
		prumer += teploty[i];
	}

	prumer = prumer/velikost;

	printf("prumer teplot: %.2f\n" ,prumer);

	qsort(teploty, velikost, sizeof(float), compare);

	printf("Serazene pole: ");
	for(int j=0 ; j<velikost; j++){
		printf("%.1lf ", teploty[j]);
	}
	printf("\n");

	printf("Minimum je: %.2f\n", teploty[velikost-1]);
	printf("Maximum je: %.2f\n", teploty[0]);



	return 0;
}
