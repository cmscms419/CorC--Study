#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rd(int n);

int main(void) {
	printf("1���� 45������ �������� ����\n");

	for (int i = 0; i <= 5; i++)
	{
		rd(i);
	}
}

int rd(int n) {
	srand(n);

	if (rand() % 50 + 1 < 50)
	{
		printf("%d\n", rand() % 50 + 1);
	}
	else return rd(n);

	return 0;
}