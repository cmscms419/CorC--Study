#include <stdio.h>
int ft(int n);

int main() {
	int n = 0, r = 0;
	int ncr = ft(n)/(ft(r)*ft(n-r));
	
	for (;n < 10; n++)
	{
		r = 0;
		for (; r <= n; r++)
		{
			ncr = ft(n) / (ft(r)*ft(n - r));
			printf("%d   ", ncr);
		}
		puts("");
	}

	return 0;
}

int ft(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * ft(n - 1);
}