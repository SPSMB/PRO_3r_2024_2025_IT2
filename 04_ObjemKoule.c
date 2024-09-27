#include "stdio.h"
#define M_PI 3.141592

int main(void){

	double polomer;
	double pi = M_PI; 

	printf("Zadejte polomer: ");
	scanf("%lf", &polomer);

	double vysledek =4.0/3*pi*polomer*polomer*polomer ;

	printf("Vysledek: %.0lf\n ",vysledek );

	return 0;
}