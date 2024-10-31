#include "stdio.h"
#pragma warning(disable:4996)

void posuv(int *a, int *b, int *c, int *d){
	int x = *d;
	*d = *c;
	*c = *b;
	*b = *a;
	*a = x;
}

int main(void)
{
	int a, b, c, d;

	printf("Zadejte 4 cisla: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("Cisla: %d %d %d %d\n", a, b, c, d);

	posuv(&a, &b, &c, &d);
	printf("Cisla: %d %d %d %d\n", a, b, c, d);

	posuv(&a, &b, &c, &d);
	printf("Cisla: %d %d %d %d\n", a, b, c, d);

	return 0;
}
