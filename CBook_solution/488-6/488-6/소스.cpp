#include <stdio.h>
#define O 3.14

float area(float r);
float circumference(float r);

int main() {
	float r;

	printf("���� ������: ");
	scanf_s("%f", &r);

	printf("���� ����: %.1f\n���� �ѷ�: %.1f\n", area(r), circumference(r));

	return 0;
}

float area(float r) {
	return r*r*O;
}

float circumference(float r) {
	return 2 * O*r;
}