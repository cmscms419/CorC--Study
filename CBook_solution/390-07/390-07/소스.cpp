#include <stdio.h>

int main() {
	int *x = NULL;
	int *y = NULL;
	double aw1 = 0;
	double aw2 = 0;
	char c;

	printf("어떤 사칙연산: + - * /\n");
	scanf_s("%c", &c);
	printf("두개의 정수를 입력 하시오\n");
	scanf_s(" %d", &aw1);
	scanf_s(" %d", &aw2);

	x = (int *)&aw1;
	y = (int *)&aw2;

	if (c == '+')
	{
		printf("답은 %d\n", *x + *y);
	}else if (c == '-')
	{
	printf("답은 %d\n", *x - *y);

	}else if (c == '*')
	{
	printf("답은 %d\n", *x * *y);

	}else if (c == '/')
	{	
	printf("답은 %d\n", *x / *y);
	}
	return 0;

}