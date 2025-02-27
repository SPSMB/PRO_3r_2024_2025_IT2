#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
   
    int8_t x = 100;
    printf("Tinyint1: %d\n ", x);

    char nazevSouboru[20] = "45_vstup.txt";
    FILE * soubor1 = fopen(nazevSouboru, "r");

    #ifdef VARIANTA1
    int cislo;
    do {
        fscanf(soubor1, "%d ", &cislo);
        printf("%d ", cislo);
    } while (cislo != 0);
    printf("\n");
    #else
    int pocetZnaku = 0;
    char buffer[300];
    pocetZnaku = readline(buffer, sizeof(buffer), soubor1);
    printf("Pocet znaku: %d\n", pocetZnaku);
    printf(">%s<", buffer);
    #endif


    fclose(soubor1);

    return 0;
}