#include <stdio.h>
double chf(double c);

int main(void)
{
	double c = NULL;
	for (double i = 0; i <= 100; i += 0.5)
	{
		printf("¼·¾¾¿Âµµ(C): %.1f, È­¾¾¿Âµµ(F): %.2f\n", i, chf(i));
	}
}

double chf(double c)
{
	return 1.8*c + 32;
}