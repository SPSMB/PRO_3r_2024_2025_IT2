#include "stdio.h"
#include "string.h"
#include "ctype.h"

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

int main(void)
{

	char s[30];
	memset(s, '*', sizeof(s)-1);
	//s[29] = '\0';
	printf("%s<\n", s);
	printf("Velikost: %d\n\n", sizeof(s));
	
	char jmeno[50] = "";
	printf("Zadejte jmeno: ");
	//scanf("%s", jmeno);
	//printf("Vase jmeno: >%s<", jmeno);
	
	// 1. varianta
	fgets(jmeno, 50, stdin);
	printf("Jmeno: >%s<", jmeno);

	// 2 Varianta
	scanf("%[^\n]%*c", jmeno);
	printf("Jmeno: >%s<", jmeno);



	return 0;
}
