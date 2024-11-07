#include "stdio.h"
#pragma warning(disable:4996)
#include <stdlib.h>
#include "float.h"

void vypisPole(float * teploty, int velikost){
	printf("Pole: ");
	for(int j=0 ; j<velikost; j++){
		printf("%.1lf", teploty[j]);
		if(j!=velikost-1){
			printf(", ");
		}
	}
	printf("\n");
}

int main(void)
{
	
	float teploty[4];
	float prumer=0;
	float min = FLT_MAX;
	float max = -FLT_MAX;
	//printf("FLT MIN: %g\n", -FLT_MAX);
	//printf("FLT MAX: %g\n", FLT_MAX);

	printf("zadejte teploty:\n");	
	int velikost = sizeof(teploty)/sizeof(float);

	for (int i = 0; i < velikost ; i++)
	{
		scanf("%f", &teploty[i]);
		prumer += teploty[i];
		if(teploty[i] < min){
			min = teploty[i];
		}
		if(teploty[i] > max){
			max = teploty[i];
		}
	}

	prumer = prumer/velikost;
	printf("prumer teplot: %.2f\n" ,prumer);
	printf("Minimum je: %.2f\n", min);
	printf("Maximum je: %.2f\n", max);

	vypisPole(teploty, velikost);
	return 0;
}
