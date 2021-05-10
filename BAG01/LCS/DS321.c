#include <stdio.h>

int DS321(int n);
int Dynamic_DS321(int n,int DD[]);
int Minimum(int a, int b);

int main()
{
	int DD[20];
	Dynamic_DS321(10, DD);

	return 0;
}

int DS321(int n)
{
	if (n <= 1)
	{
		return 0;
	}
	else if (n % 3 == 0)
	{
		return DS321(n / 3) + 1;
	}
	else if (n % 2 == 0)
	{
		return DS321(n / 2) + 1;
	}
	else
	{
		return (DS321(n - 1) + 1);
	}
}

int Dynamic_DS321(int n, int DD[])
{
	DD[0] = 0;
	int ds321ch = 0;
	for (int i = 1; i <= n; i++)
	{
		ds321ch = DS321(i);
		
		if (DD[i - 1] + 1 < ds321ch)
		{
			DD[i] = DD[i - 1] + 1;
		}
		else
		{
			DD[i] = Minimum(DD[i - 1] + 1, ds321ch);
		}
	}
}

int Minimum(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}