#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int rt(int n);

int main() {
	int n = 0;
	while (1)
	{
		printf("1���� n������ ���� ���ϰ� ���� n�� ���ڸ� �Է�: ");
		scanf("%d", &n);
		printf("1���� n������ ��: %d\n", rt(n));
	}
}

int rt(int n) {
	static int cnt = 0;
	cnt++;
	printf("�����Լ��� �ݺ��� Ƚ��: %d\n", cnt);
	if (n != 0)
		return rt(n - 1) + n;
	else
		return 0;
}