#include <stdio.h>
int ft(int n);

int main() {
	printf("1���� 20������ ��: %d\n", ft(20));

	return 0;
}

int ft(int n) {
	if (n == 1)
		return 1;
	else if (n > 1)
		return n + ft(n - 1);
}