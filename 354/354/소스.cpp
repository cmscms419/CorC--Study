#include <stdio.h>

int main() {
	int a, b;
	
	for (int i = 10; i >= 1; i--)
	{
		for  (int m = 1; m <= i; m++)
		{
			printf("  ");
		}
	}
	for (a = 2; a <= 257; a++) {
		for (b = 2; b <= a; b++)
		{
			if (a % b == 0) break;
		}
	}

	return 0;
}