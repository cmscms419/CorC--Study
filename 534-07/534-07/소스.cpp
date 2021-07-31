#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char a = NULL;
	int a_n = 0;
	int a_2 = 0;
	char b[8];

	printf("한 문자를 입력: ");
	scanf("%c", &a);
	
	a_n = a;

	printf("10집법: %d\n16진법: %x\n2진법: %s", a,a,b);

	return 0;
}