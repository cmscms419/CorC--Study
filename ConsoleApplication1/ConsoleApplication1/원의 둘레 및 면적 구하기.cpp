#include <stdio.h>
#define PI 3.14

double r = 0;

int main(void)
{

	printf("���� �ѷ��� ������ ���ϰ��� �ϴ� �������� ����:\n");
	scanf_s("%lf", &r);
	printf("���� ����: %.4lf\n���� �ѷ�: %.4lf\n", r*r*PI,2*PI*r);

	return 0;
}