#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

// funkce readline precte 1 radek ze souboru
// vraci pocet prectenych znaku
int readline(char * buf, int max, FILE * f){

    char tmp = ' ';
    int pocet = 0;
    
    while(1){
        tmp = (char) fgetc(f);
        if(tmp == '\n' || tmp == EOF){
            break;
        } else {
            // ukladam do zasobniku
            if(pocet <= max-1){
                buf[pocet] = tmp;
                pocet++;
            }
        }
    }
    buf[pocet] = '\0';

    return pocet;
}

int main(){
   
    char nazevSouboru[20] = "45_vstup.pdf";
    FILE * soubor1 = fopen(nazevSouboru, "r");
    if(soubor1 == NULL){
        int chyba = errno;
        printf("Soubor %s se nepodarilo otevrit.\n", nazevSouboru);
        printf("%s", strerror(chyba));
        return 1;
    }
    char zasobnik[300];
    readline(zasobnik, sizeof(zasobnik), soubor1);
    printf("%s\n", zasobnik);

    fseek(soubor1, 1, SEEK_SET); // reset cteciho ukazatele
    readline(zasobnik, sizeof(zasobnik), soubor1);
    printf("%s\n", zasobnik);

    fclose(soubor1);
    return 0;
}