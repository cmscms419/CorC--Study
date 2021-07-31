#include <stdio.h>
#define SIZE 5

int main()
{
	double score[SIZE] = { 98.56,78.62,78.69,89.32,95.29 };
	double all = 0;
	double m = 0;

	for (int i = 0; i < SIZE - 1; i++)
	{
		all += score[i];
	}
	m = all / 5;

	printf("¹è¿­ÀÇ ÃÑÇÕ: %.3f\n", all);
	printf("¹è¿­ÀÇ Æò±Õ: %.3f\n", m);

	return 0;
}