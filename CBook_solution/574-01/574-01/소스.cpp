#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int rt(int n);

int main() {
	int n = 0;
	while (1)
	{
		printf("1부터 n까지의 합을 구하고 싶은 n의 숫자를 입력: ");
		scanf("%d", &n);
		printf("1부터 n까지의 합: %d\n", rt(n));
	}
}

int rt(int n) {
	static int cnt = 0;
	cnt++;
	printf("제귀함수를 반복한 횟수: %d\n", cnt);
	if (n != 0)
		return rt(n - 1) + n;
	else
		return 0;
}