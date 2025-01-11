#include "stdio.h"
#include "string.h"

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

float nasob(float *a, float *b){
	float vysledek = (*a)*(*b);
	return vysledek;
}

int main(){
	
	char retezec[1000];

	printf("Zadejte retezec, ktery obsahuje *: ");
	scanf("%s", retezec);

	for(unsigned int i = 0; i<strlen(retezec); i++){
		// poznam konce slova podle '*'
		if(retezec[i] == '*'){
			printf("\n");
		} else {
			printf("%c", retezec[i]);
		}
	}




	/*
	float x = 3;
	float y = 3.5;

	printf("Vysledek: %f\n", nasob(&x, &y));
	*/

	return 0;
}
