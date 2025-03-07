#include <stdio.h>
#include <errno.h>
#include <string.h>

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

int main(){

    const char * jmenoSouboru = "50_vstup.txt";
    FILE * soubor = fopen(jmenoSouboru, "w");
    if(soubor == NULL ){   
        printf("Soubor %s pro zapis se nepodarilo otevrit.\n", jmenoSouboru);
        return 1;
    }

    int x=-1;
    printf("Zadavejte cela cisla, pro konec zadejte 0:\n" );
    do{
        int kontrola = scanf("%d", &x);
        printf("Kontrola: %d\n", kontrola);
        if(kontrola != 1){
            // vstup selhal
            printf("Zadavejte jenom cela cisla.\n");
            while(getchar()!='\n'); // cisteni vstupu
        } else {
            fprintf(soubor, "%d ", x);
        }

    }while(x != 0);

    printf("Cisla byla zapsana do souboru %s", jmenoSouboru);
    fclose(soubor);

    return 0;
}