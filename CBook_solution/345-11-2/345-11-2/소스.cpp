#include <stdio.h>
#define MAX 9

int main(void)
{
	int a = 0;

	loop:
	printf("1~9�� ���� ���� ���� �������� �Է�(0�� �Է��ϸ� ��): ");
	scanf_s("%d", &a);

	if (a == 0)	return 0;

	if (a < 1 || a > MAX) {
		printf("�ٽ� �Է��Ͻÿ�.\n");
		goto loop;
	}

	printf("----%d��----\n", a);
	for (int i = 1; i <= MAX; i++)
	{
		printf("%d * %d = %d\n", a, i, a*i);
	}
	goto loop;

	return 0;
}