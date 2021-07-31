#include <stdio.h>

int main()
{
	int a[3][4] = { {12,30,82,54},{43,51,32,47},{30,42,41,69} };

	for (int i = 0; i < 3; i++)
	{
		for (int m = 0; m < 4; m++)
		{
			a[i][m] = a[i][m] * 10 + 2;
			printf("%d  ", a[i][m]);
		}
		puts("");
	}

	return 0;
}