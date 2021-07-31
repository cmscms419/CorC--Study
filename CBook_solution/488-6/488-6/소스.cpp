#include <stdio.h>
#define O 3.14

float area(float r);
float circumference(float r);

int main() {
	float r;

	printf("원의 반지름: ");
	scanf_s("%f", &r);

	printf("원의 면적: %.1f\n원의 둘레: %.1f\n", area(r), circumference(r));

	return 0;
}

float area(float r) {
	return r*r*O;
}

float circumference(float r) {
	return 2 * O*r;
}