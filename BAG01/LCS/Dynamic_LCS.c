#include <stdio.h>
int max(int a, int b);
int LIS(int s1[], int* c);

int s1[13] = { 1,10,5,20,15,12,30,49,25,35,66,75,44 };


int main(void)
{
	int c[13] = { 0, };

	printf("%d\n", LIS(s1, c));

	return 0;
}

int LIS(int s1[], int *c)
{
	int maxint = 0;
	for (int i = 0; i < 13; i++)
	{
		if (c[i] == 0)
		{
			c[i] = 1;
		}
		for (int m = 0; m < i; m++)
		{
			if (s1[i] > s1[m])
			{
				c[i] = max(c[m] + 1, c[i]);
				if (maxint < c[i])
				{
					maxint = c[i];
				}
			}
		}
	}

	return maxint;
}

int max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else return b;
}
