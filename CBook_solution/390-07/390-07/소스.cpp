#include <stdio.h>

int main() {
	int *x = NULL;
	int *y = NULL;
	double aw1 = 0;
	double aw2 = 0;
	char c;

	printf("� ��Ģ����: + - * /\n");
	scanf_s("%c", &c);
	printf("�ΰ��� ������ �Է� �Ͻÿ�\n");
	scanf_s(" %d", &aw1);
	scanf_s(" %d", &aw2);

	x = (int *)&aw1;
	y = (int *)&aw2;

	if (c == '+')
	{
		printf("���� %d\n", *x + *y);
	}else if (c == '-')
	{
	printf("���� %d\n", *x - *y);

	}else if (c == '*')
	{
	printf("���� %d\n", *x * *y);

	}else if (c == '/')
	{	
	printf("���� %d\n", *x / *y);
	}
	return 0;

}