#include <stdio.h>

int main()
{
	int a[] = { 4,7,9,3,6 };
	int b[] = { 10,20,30,40,50,60 };
	
	printf("a�� �迭: ");
	for (int i = 0; i < sizeof(a)/4; i++)
	{
		a[i] = b[i];
		printf("%d ", a[i]);
	}
	puts("");

	printf("b�� �迭: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", b[i]);
	}
	puts("");

	return 0;
}