#include <stdio.h>
int intpow(int m, int n);

int main(void)
{
	int m, n;

	printf("m�� n�� ������ ���� �Է��Ͻÿ�\nm: ");
	scanf_s("%d", &m);
	printf("n: ");
	scanf_s(" %d", &n);
	printf("%d\n", intpow(m, n));

	return 0;
}

int intpow(int m, int n)
{
	return m*n;
}