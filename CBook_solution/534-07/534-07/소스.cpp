#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char a = NULL;
	int a_n = 0;
	int a_2 = 0;
	char b[8];

	printf("�� ���ڸ� �Է�: ");
	scanf("%c", &a);
	
	a_n = a;

	printf("10����: %d\n16����: %x\n2����: %s", a,a,b);

	return 0;
}