#include "stdio.h"
#include "string.h"

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

typedef struct clovek{
	char jmeno[30];
	char prijmeni[50];
	int vyska; // v centimetrech
	char mesto[100];
} Clovek;

void vypisInfoClovek(Clovek * c){
	printf("Jmeno: %s\n", c->jmeno);
	printf("Vyska: %d\n", c->vyska);
	// zmenim jmeno
	strncpy(c->jmeno, "Karel", 6);
}

void overujAdresy(Clovek c){
	int u_jmeno = (int)&c.jmeno;
	int u_prijmeni = (int)&c.prijmeni;
	int u_vyska = (int)&c.vyska;
	int u_mesto = (int)&c.mesto;

	printf("Adresa jmeno: %14p\n", &c.jmeno);
	printf("Adresa prijmeni: %11p\n", &c.prijmeni);
	printf("Adresa vyska: %14p\n", &c.vyska);
	printf("Adresa mesto: %14p\n", &c.mesto);

	printf("Delka jmeno = %d\n", u_prijmeni - u_jmeno);
	printf("Delka prijmeni = %d\n", u_vyska - u_prijmeni);
	printf("Delka vyska = %d\n", u_mesto - u_vyska);
	printf("Delka mesta = %d\n", sizeof(c.mesto));
}

int main(){
	
	Clovek c1;
	c1.vyska = 180;
	strncpy(c1.jmeno, "Tom", 30);

	vypisInfoClovek(&c1);
	printf("Jmeno2: %s\n", c1.jmeno);
	overujAdresy(c1);
	
	return 0;
}
