#include <stdio.h>

int main() {
	int i = 0x3C405B7B;
	char * p = (char *) &i;

	p += 1;

	printf("*p: %c ", *p);
	printf("값: %X\n", *p);

	printf("*p++: %c ", *p++); *p--;   //증감연산자 사용 후 정상화
	printf("값: %X\n", *p++); *p--;

	printf("*++p: %c ", *++p); *--p;
	printf("값: %X\n", *++p); *--p;

	printf("(*p)++: %c ", (*p)++); (*p)--;
	printf("값: %X\n", (*p)++); (*p)--;

	printf("++*p: %c ", ++*p); --*p;
	printf("값: %X\n", ++*p); --*p;



	return 0;

}