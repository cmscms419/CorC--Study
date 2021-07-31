#include <stdio.h>
#include <math.h>

int main(void) {
	
	int anw = 0;

	for (int i = 1; i <= 5; i++)
	{
		anw = 0;
		for (int m = 1; m <= i; m++)
		{
			anw += pow(10, i - m)*(i - m + 1);
		}
		printf("%5d\n", anw);
	}

	return 0;
}