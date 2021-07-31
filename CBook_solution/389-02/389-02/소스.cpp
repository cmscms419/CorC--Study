#include <stdio.h>

int main()
{

	int a = 10;
	int b = 20;
	int sum = 0;
	int *p = NULL;

	p = &a;
	sum = *p * *p;
	a = sum;

	b = 2sum;

	p = &b;
	sum += *p;

	printf("%d", sum);
	
	return 0;


}