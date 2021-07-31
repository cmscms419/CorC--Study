#include <stdio.h>

int main(void) {
	double a[10] = { NULL };
	
	for (int i = 0; i < 10; i++)
	{
		a[i] = 1.0 / ((i + 2.0)*(i + 3.0));
		printf("%d¹øÂ° °ª: %.2f\n", i + 1, a[i]);
	}
	
	return 0;
}