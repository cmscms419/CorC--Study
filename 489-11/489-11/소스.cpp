#include <stdio.h>
#include <math.h>

double xy(int n);

int main() {
	for (int i = 0; i <= 10; i++)
	{
		printf("6ÀÇ %d½Â: %.0lf\n", i, xy(i));
	}

	return 0;
}

double xy(int n) {
	if (n == 0)
		return 0;
	if (n >= 1)
		return pow(6, n);
}