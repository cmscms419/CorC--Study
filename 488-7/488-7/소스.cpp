#include <stdio.h>

float slS(int y, float r, int a);
float wlS(int y, float r, int a);

int main() {
	int n; // ����
	int y = 0; // ��������� �Ⱓ
	float r = 0; // ������ (%�� �Ҽ���)
	int a = 0; // ����
	while (1)
	{
		printf("�ܸ� 1��\n������ 2��\n����� 0��\n");
		scanf_s("%d", &n);

		if (n != 0, 1, 2) {
			printf("�ٽ� �Է��Ͻÿ�.\n");
			puts("");
		}

		if (n == 0) {
			return 0;
		}
		else if (n == 1) {
			printf("���ݰ� �ܱ������ �Ⱓ(��),������ ������� �ۼ�\n");
			scanf_s("%d %d %f", &a, &y, &r);
			printf("�ܱ� ����: %.2f\n", slS(y, r, a));
			puts("");
		}
		else if (n == 2) {
			printf("���ݰ� �ܱ������ �Ⱓ,������ ������� �ۼ�\n");
			scanf_s("%d %d %f", &a, &y, &r);
			printf("���� ����: %.2f\n", wlS(y, r, a));
			puts("");
		}
	}
}


float slS(int y, float r, int a) {
	return a*(1 + r*y);
}

float wlS(int y, float r, int a) {
	return a*(1 + r)*y;
}