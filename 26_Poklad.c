#include "stdio.h"

void vypisMrizku(int ** pole, int pRadku, int pSloupcu){
	for(int r=0; r<pRadku; r++){
		for(int s=0; s<pSloupcu; s++){
			if(pole[r][s] == 0){
				printf("-");
			} else {
				printf("%d", pole[r][s]);
			}
		}
		printf("\n");
	}
}

int main(){
	
	int radek1[4] = {0};
	int radek2[4] = {0};
	int radek3[4] = {0,0,0,1};
	int radek4[4] = {0};
	int * mrizka[4] = {radek1, radek2, radek3, radek4};
	
	int x, y; // souradnice, ktere zada uzivatel
	
	vypisMrizku(mrizka, 4, 4);
	
	while(1){
		printf("Hadejte pozici pokladu");
		printf(" - nejprve x, potom y souradnice: ");
		
		
		int kontrola = scanf("%d %d", &x, &y);
		if(kontrola != 2){
			// vycisteni vstupniho zasobniku
			while(getchar()!='\n');
			// dalsi pokus
			continue;
		}
	}
	


	return 0;
}