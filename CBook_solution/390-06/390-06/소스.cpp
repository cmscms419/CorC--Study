#include <stdio.h>

int main() {
	int i = 0x3C405B7B;
	char * p = (char *) &i;

	p += 1;

	printf("*p: %c ", *p);
	printf("��: %X\n", *p);

	printf("*p++: %c ", *p++); *p--;   //���������� ��� �� ����ȭ
	printf("��: %X\n", *p++); *p--;

	printf("*++p: %c ", *++p); *--p;
	printf("��: %X\n", *++p); *--p;

	printf("(*p)++: %c ", (*p)++); (*p)--;
	printf("��: %X\n", (*p)++); (*p)--;

	printf("++*p: %c ", ++*p); --*p;
	printf("��: %X\n", ++*p); --*p;



	return 0;

}