#include "stdio.h"
#include "math.h"
#pragma warning(disable:4996)

int main(void){
	
	double a,b,c;
	double vysledek;
	double s;

	printf("Zadejte 3 strany: ");
	int kontrola = scanf("%lf %lf %lf", 
		&a, &b, &c);

	if(kontrola != 3){
		printf("Chybne vstupy. Konec.");
		return 1;
	}

	s = (a+b+c)/2;

	vysledek = sqrt(s*(s-a)*(s-b)*(s-c));
	printf("vysledek: %lf", vysledek);

	return 0;
}