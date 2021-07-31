#include <stdio.h>
double ch(int a);

int main()
{
	int a;
	
	printf("몇 인치 인지 입력하시오: ");
	scanf_s("%d", &a);
	printf("inch: %d, cm: %.3f\n", a, ch(a));

	return 0;
}

double ch(int a) {
	return (a*2.54);
}