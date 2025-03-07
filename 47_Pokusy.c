#include <stdio.h>

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

// fun
void x();
void y();

// pozor, volani funkce x() z funkce y() a zaroven funkce y() z funkce x()
// vede na nekonecny cyklus
// program sice pujde prelozit, ale rozhodne nebude dobre fungovat

void y(){
    printf("Ja jsem funkce Y.\n");
    x();
}

void x(){
    printf("Ja jsem funkce X.\n");
    y();
}

int main(){
   
    x();
    return 0;
}