#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10


int main(void) {
	int n = 1, guess, input;
	srand((long)time(NULL));
	guess = rand() % MAX + 1;

	printf("1���� %d���̿����� ������ �����ȴ�.\n", MAX);
	printf("�� ������ �������� 7�� �ȿ� �����.\n");

	while (1)
	{
		scanf_s("%d", &input);
		if (n == 7) {
			puts("��� ��ȸ�� ���̽��ϴ�.");
			return 0;
		}
		if (guess == input) {
			puts("���� �Դϴ�.");
			break;
		}
		else if (guess < input) {
			printf("���亸�� ū �� �Դϴ�.\n");
		}
		else if (guess > input) {
			printf("���亸�� ���� �� �Դϴ�.\n");
		}
		n++;
	}
	return 0;
}