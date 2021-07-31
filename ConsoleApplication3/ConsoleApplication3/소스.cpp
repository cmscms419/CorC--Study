#include <stdio.h>

int main()
{
	char b = '*';
	char *a = &b;

	printf("특수 문자: 포인터 a\n주소값: %p\n코드값: %d\n문자: %c\n", a,*a,*a);

	return 0;
}