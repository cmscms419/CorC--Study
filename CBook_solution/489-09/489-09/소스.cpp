#include <stdio.h>
int ft(int n);

int main() {
	printf("1부터 20까지의 합: %d\n", ft(20));

	return 0;
}

int ft(int n) {
	if (n == 1)
		return 1;
	else if (n > 1)
		return n + ft(n - 1);
}