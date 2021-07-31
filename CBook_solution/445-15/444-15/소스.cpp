#include <stdio.h>

int main() {
	int pascal[10][10] = { {1},{1,1} };
	
	for (int i = 0; i < 10; i++)
	{
		for (int m = 0; m <= i; m++)
		{
			if (i <= 1)
				printf("1    ");
			else
			{
				pascal[i][m] = pascal[i - 1][m - 1] + pascal[i - 1][m];
				printf("%d    ", pascal[i][m]);
			}
		}
		puts("");
	}
	
	return 0;
}