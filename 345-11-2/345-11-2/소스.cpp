#include <stdio.h>
#define MAX 9

int main(void)
{
	int a = 0;

	loop:
	printf("1~9단 까지 보고 싶은 구구단을 입력(0을 입력하면 끝): ");
	scanf_s("%d", &a);

	if (a == 0)	return 0;

	if (a < 1 || a > MAX) {
		printf("다시 입력하시오.\n");
		goto loop;
	}

	printf("----%d단----\n", a);
	for (int i = 1; i <= MAX; i++)
	{
		printf("%d * %d = %d\n", a, i, a*i);
	}
	goto loop;

	return 0;
}