#include "stdio.h"
#pragma warning(disable:4996)

int main(void){

	// modulo

	int i=14;
	int j=4;

	printf("i: %3d   j: %3d   i/j: %3d,   i%%j: %3d\n",  i,  j,   i/j,   i%j );
	printf("i: %3d   j: %3d   i/j: %3d,   i%%j: %3d\n", -i, -j, -i/-j, -i%-j );
	printf("i: %3d   j: %3d   i/j: %3d,   i%%j: %3d\n",  i, -j,  i/-j,  i%-j );

	// logicke operatory

	char typ;		// typ uctu - A,B,C,D
	double urok = 0;// urok na ucte
	int zustatek;	// zustatek na ucte
	int cas;		// jak dlouho jsem u banky

	printf("Zadejte zustatek: ");
	scanf_s("%d", &zustatek);
	printf("Zadejte cas, jak dlouho jste u banky: ");
	scanf_s("%d", &cas);
	printf("Zadejte typ vaseho uctu: ");
	//while(getchar()!='\n');
	scanf_s(" %c", &typ, 1);

	if(typ == 'A'){
		if(	(zustatek > 10000) && (zustatek < 250000) && (cas > 2)){
			urok = 0.75;
		} else if( cas < 2){
			if(zustatek >= 250000){
				urok = 0.75;
			} else {
				urok = 0.5;
			}
		}
	} else {
		 if((zustatek > 150000) && (cas > 1)){
			urok = 0.5;
		} else {
			urok = 0.25;
		}
	}


	printf("Vas urok je %f", urok);
	return 0;
}