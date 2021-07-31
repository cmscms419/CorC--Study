#include <stdio.h>
#include <math.h>

int main(void) {

	int anw = 0;

	for (int i = 1; i <= 5; i++)
	{
		anw = 0;
		
		for (int m = 5;m >= i;m--)
		{
			anw += pow(10,m-i)*(m);
		}
		
		printf("%d\n", anw);
	}

}