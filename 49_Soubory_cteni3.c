#include <stdio.h>
#include <errno.h>
#include <string.h>

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

int main(){

    FILE * soubor = fopen("45_vstup.txt", "r");
    
    char c;
    do{
        c = (char) fgetc(soubor);
        printf("%c", c);
    } while(c != EOF);

    return 0;
}