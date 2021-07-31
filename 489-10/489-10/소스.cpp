#include <stdio.h>

int Fn(int n);

int main(void) {
	for (int i = 0; i <= 10; i++)
	{
		printf("%d의 피보나치 수: %d\n", i, Fn(i));
	}
	return 0;
}
int Fn(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n >= 2)
		return n - 1 + n - 2;
}