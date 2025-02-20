/*27*/ #include <stdlib.h>
/*06*/ #include <stdio.h>
/*07*/ typedef struct zbozi { char nazev[100]; float cena; int pocetKusu; } Zbozi;
/*15*/ void pridejZbozi(Zbozi ** kosik, int * kapacita, int * vyuzito){
/*17*/     int novaKapacita;
/*18*/     // kontrola zaplnenosti kosiku
/*05*/     if(*kapacita == 0){
/*21*/         novaKapacita = 5;
/*22*/         Zbozi * novyKosik = (Zbozi *) malloc(novaKapacita * sizeof(Zbozi));
/*12*/         *kosik = novyKosik;
/*36*/         *kapacita = novaKapacita;
/*19*/     } else if(*kapacita == *vyuzito){
/*31*/         novaKapacita = *kapacita * 4;
/*28*/         Zbozi * novyKosik = (Zbozi *) realloc(kosik, novaKapacita * sizeof(Zbozi));
/*13*/         *kosik = novyKosik;
/*26*/         *kapacita = novaKapacita;
/*11*/     }
/*02*/     vlozDoKosiku(kosik, vyuzito);
/*10*/     *vyuzito = *vyuzito + 1;
/*08*/ }
/*16*/ void odeberZbozi(Zbozi ** kosik, int * kapacita, int * vyuzito){
/*33*/     // zbozi neni nutne fyzicky mazat
/*35*/     if(*vyuzito == 0){
/*30*/         free(*kosik);
/*01*/         *kosik = NULL;
/*20*/     }
/*23*/     *kapacita = *kapacita - 1;
/*29*/ }
/*34*/ int main(){
/*14*/     int kapacita = 0; /* kapacita kosiku */
/*24*/     int vyuzito = 0; /* pocet polozek v kosiku */
/*04*/     Zbozi * kosik = NULL; /* kosik */
/*09*/     cekejNaPokynUzivatele(&kosik, &kapacita, &vyuzito);
/*03*/     free(kosik);
		   kosik = NULL;
/*25*/     return 0;
/*32*/ }