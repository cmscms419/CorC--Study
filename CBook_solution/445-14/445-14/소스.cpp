#include <stdio.h>

int main()
{
	int a[3][2] = { {3,5},{4,2},{5,7} };
	int b[2][3] = { {3,8,2},{2,4,6} };
	int x_y[3][3] = { 0 };

	for (int i = 0; i < 3; i++)
	{
		for (int m = 0; m < 2; m++)
		{
			for (int n = 0; n < 3; n++)
			{
				x_y[i][n] = a[i][m] * b[m][n];
				printf("x_y[%d][%d] = %d\n", i+1, n+1, x_y[i][n]);
			}
		}
	}

	return 0;
}