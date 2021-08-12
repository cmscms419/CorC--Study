#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNUMBER 1002

int lcs2(int a, int b, char a1[], char b1[]);
int MAX(int a, int b);
int c[MAXNUMBER][MAXNUMBER] = { 0, };

int main()
{
	char a[MAXNUMBER] = { 0, };
	char b[MAXNUMBER] = { 0, };

	int x = 0;
	int y = 0;

	scanf("%s", a + 1);
	scanf("%s", b + 1);

	x = (int)strlen(a + 1);
	y = (int)strlen(b + 1);

	printf("%d", lcs2(x, y, a, b));

	return 0;
}

int lcs2(int a, int b, char a1[], char b1[])
{
	for (int i = 1; i <= a; i++)
	{
		for (int m = 1; m <= b; m++)
		{
			if (a1[i] == b1[m])
			{
				c[i][m] = c[i - 1][m - 1] + 1;
			}
			else
			{
				c[i][m] = MAX(c[i - 1][m], c[i][m - 1]);
			}
		}
	}

	return c[a][b];
}

int MAX(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else return b;
}