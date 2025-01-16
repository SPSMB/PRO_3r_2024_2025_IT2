#include "stdio.h"
#include "string.h"

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

typedef struct clovek{
	char jmeno[10];
	char prijmeni[20];
	int vaha;
	int vyska;
} Clovek;

void vypisInformace(Clovek * c){
	printf("%s %s (vaha:%d, vyska: %d)\n", 
		c->jmeno, c->prijmeni, c->vaha, c->vyska);
}

// hledame cloveka podle zadaneho textu
// vracime ukazatel na nalezeneho cloveka
// kdyz se nenajde, vracime NULL
Clovek * najdiCloveka(Clovek skupina[], int pocet){

	char hledanyClovek[20];
	printf("Zadejte jmeno hledane osoby: ");
	scanf("%s", hledanyClovek);
	for(int i = 0; i<pocet; i++){
		char * nalezeno = strstr(skupina[i].jmeno, hledanyClovek);
		if(nalezeno != NULL){
			// nasel jsem, takze vracim ukazatel na clovek, ktereho jsem nasel
			return &(skupina[i]);
		}
	}
	return NULL;
}



// vrati index nejvyssiho cloveka v poli
int nejvyssiClovek(Clovek skupina[], int pocet){
	int maxVyska = 0;
	int maxPozice = 0;
	for(int i = 0; i<pocet; i++){
		if(skupina[i].vyska > maxVyska){
			maxVyska = skupina[i].vyska;
			maxPozice = i;
		} 
	}
	return maxPozice;
}

int main(){
	
	Clovek skupina[10];
	skupina[0].vyska = 180;
	skupina[1].vyska = 169;
	skupina[2].vyska = 177;
	skupina[3].vyska = 155;
	skupina[0].vaha = 80;
	skupina[1].vaha = 70;
	skupina[2].vaha = 66;
	skupina[3].vaha = 76;
	strncpy(skupina[0].jmeno, "Tomas", 9);
	strncpy(skupina[1].jmeno, "Marketa", 9);
	strncpy(skupina[2].jmeno, "Josef", 9);
	strncpy(skupina[3].jmeno, "Jarmila", 9);
	strncpy(skupina[0].prijmeni, "Zimmerhakl", 10);
	strncpy(skupina[1].prijmeni, "Novotna", 9);
	strncpy(skupina[2].prijmeni, "Tupy", 9);
	strncpy(skupina[3].prijmeni, "Rychla", 9);

	// i: kde je v poli nejvyssi clovek
	int i = nejvyssiClovek(skupina, 4);
	printf("Nejvyssi clovek je %s a meri %dcm.\n", 
		skupina[i].jmeno, skupina[i].vyska);

	Clovek * hledanyClovek = najdiCloveka(skupina, 4);
	if(hledanyClovek == NULL){
		printf("Clovek se nenasel.\n");
	} else {
		vypisInformace(hledanyClovek);
	}
	
	return 0;
}
