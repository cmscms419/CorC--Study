#include <stdio.h>
#define PI 3.14

double r = 0;

int main(void)
{

	printf("원의 둘레와 면적를 구하고자 하는 반지름의 길이:\n");
	scanf_s("%lf", &r);
	printf("원의 면적: %.4lf\n원의 둘레: %.4lf\n", r*r*PI,2*PI*r);

	return 0;
}