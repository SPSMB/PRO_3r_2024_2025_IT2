#include "stdio.h"
#include "string.h"
#pragma warning(disable:4996)

int main(){
	
	char a[50] = "Stredni prumyslova skola";
	int i;
	printf("Retezec:%s\n",a);
	printf("Zadejte pozici: ");
	int delka = strlen(a);

	do{
		int kontrola = scanf("%d",&i);
		if(kontrola != 1 || i >= delka || i < 0){
			while(getchar() != '\n');
			printf("Chybny vstup, zkuste znovu: ");
		} else {
			printf("Na pozici %d je znak '%c'.\n", i, a[i]);
			break;
		}
	} while(1);
	
	
	return 0;
}