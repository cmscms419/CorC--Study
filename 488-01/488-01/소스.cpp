#include <stdio.h>
double ch(int a);

int main()
{
	int a;
	
	printf("�� ��ġ ���� �Է��Ͻÿ�: ");
	scanf_s("%d", &a);
	printf("inch: %d, cm: %.3f\n", a, ch(a));

	return 0;
}

double ch(int a) {
	return (a*2.54);
}