#include <stdio.h>
int max(int a, int b);
int Fbag0_1(int Bag0_1[6][17], int p[6], int w[6], int n, int C);


int main(void)
{
	int C = 17;
	int n = 6;
	int w[6] = { 4,10,6,4,2,2 };
	int p[6] = { 7,4,6,7,5,10 };
	int Bag0_1[6][17];

	printf("%d\n", Fbag0_1(Bag0_1, p, w, n, C));


	return 0;
}

int Fbag0_1(int Bag0_1[6][17], int p[6], int w[6], int n, int C)
{
	
	for (int i = 0; i < n; i++)
	{
		for (int smallc = 0; smallc < C; smallc++)
		{
			if (i == 0)
			{
				if (smallc < w[0])
				{
					Bag0_1[i][smallc] = 0;
				}
				else
				{
					Bag0_1[i][smallc] = p[0];
				}
			}
			else
			{
				if (smallc < w[i])
				{ 
					Bag0_1[i][smallc] = Bag0_1[i - 1][smallc];
				}
				else
				{
					Bag0_1[i][smallc] = max(Bag0_1[i - 1][smallc - w[i]] + p[i], Bag0_1[i - 1][smallc]);
				}
			}
		}
	
	}

	return Bag0_1[n][C];
}

int max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
		return b;
}