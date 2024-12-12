#include "stdio.h"
#include "stdlib.h"
#include "time.h"

// potlaci warning o zastarale funkci (scanf apod)

#pragma warning(disable:4996)

void vypisPole(int * buben, int velikost){
	int count = 0;
	printf("  Vylosovana cisla: ");
	for (int i = 0; i < velikost; ++i)
	{
		if (buben[i] ==1)
		{
			if (count %10 ==0)
			{
				printf("\n  ");
			}
			printf("%d,", i+1);
			count ++;
		}
	}
	printf("\n  [%d]\n", count);
}

void losujCislo(int * buben, int velikost){
	
	int nahodneC = rand()%50;
	//printf("Nahodne cislo: %d\n", nahodneC);
	int i = 0;
	for(; nahodneC >= 0; i++){
		if(buben[i%velikost] == 0){
			nahodneC--;
		}
		if(nahodneC == -1){
			buben[i%velikost] = 1; // nastavim index jako vylosovany
		}
	}

	printf("  Aktualni cislo: %d\n", i%velikost);
	vypisPole(buben, velikost);
}

void restart(int * buben, int velikost){
	printf("Restartujeme\n");
	// inicializace nahodneho generatoru
	srand((unsigned int)time(NULL));

	// vynulovani pole vylosovanaCisla
	for(int i=0; i<velikost; i++){
		buben[i] = 0;
	}

}


int main(void)
{

char vstup ;
int vylosovanaCisla[50] = {0};

do{
	printf("zadejte vstup: L = losovani, R = restart, K = konec.\n  ");
	
	scanf("%c", &vstup);
	while (getchar()!= '\n');
	
	if (vstup == 'L' || vstup == 'l'){
		losujCislo(vylosovanaCisla, 50);
	}
	else if ( vstup == 'R' || vstup == 'r'){
		restart(vylosovanaCisla, 50);
	} else if (vstup == 'K' || vstup == 'k'){
		break;
	} else {
		printf("  chybny vstup\n");
		continue;
	}

}while(vstup != 'K' || vstup != 'k');

printf("Konec hry\n");




	return 0;
}
