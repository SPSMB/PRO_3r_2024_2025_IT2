#include "stdio.h"

int main(){
	
	const char * a = "Stredni prumyslova skola";

	int i=0;
	char b;
	b = *(a+i);
	char * adr;

	while(b!='\0'){
		printf("%c\n", b);
		i+=1;
		b = *(a+i);
		adr = a+i;
	}
	*adr = 'x';

	printf("%s\n", a);
	
	return 0;
}