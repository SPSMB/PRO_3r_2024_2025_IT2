#include <stdio.h>
#include <errno.h>
#include <string.h>

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

// program vypisuje vsechny chybove hlasky,
// ke kterym muze dojit v souvislosti se ctenim a zapisem do souboru

int main(){

    for (int i = 0; i < 300; ++i)
    {
        printf("%d: %s\n", i, strerror(i));
    }
    return 0;
}