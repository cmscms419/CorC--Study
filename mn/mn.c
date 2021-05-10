#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	밑의 INDEXMAX 값을 설정하면 자동으로 
	m값과 n값이 설정되어서 가장 큰 정사각형의 크기를 구해줍니다.
*/

#define YELLOW 1
#define BLACK 0
#define INDEXMAX 3
#define MAXLOOP 10

void YellowTable(int yellow, int tile[][INDEXMAX], int m, int n);
int YellowCnt(int tile[][INDEXMAX], int m, int n);
int AgainYellowTable(int MYellowcheck, int NYellowcheck, int tile[][INDEXMAX]);
int SquareCheck(int tile[][INDEXMAX], int m, int n);
int Max(int a, int b);

int main()
{
	srand(time(NULL));
	int m = rand() % INDEXMAX;
	while (1)
	{
		if (m > INDEXMAX)
		{
			srand((int)time(NULL));
			m = rand() % INDEXMAX + 1;
		}
		else
			break;
	}

	srand(time(NULL));
	int n = rand() % INDEXMAX;
	while (1)
	{
		if (n > INDEXMAX)
		{
			srand((int)time(NULL));
			n = rand() % INDEXMAX + 1;
		}
		else
			break;
	}
	
	srand(time(NULL));
	int yellow = (m * n) - (rand() % (m * n));
	while (1)
	{
		if (yellow > m * n)
		{
			srand((int)time(NULL));
			yellow = rand() % INDEXMAX + 1;
		}
		else
			break;
	}

	int YellowCheckcnt = 0;
	int MYellowcheck = 0;
	int NYellowcheck = 0;

	int** tile = (int**)calloc(m * n, sizeof(int));
	
	if (yellow <= 0)
	{
		printf("Don't have Yellow\n");
		return 0;
	}
	
	YellowTable(yellow, tile, m, n);
	printf("정사각형의 최대 개수: %d", YellowCnt(tile, m, n));

 	return 0;
}


void YellowTable(int yellow, int tile[][INDEXMAX],int m, int n)
{

	int MYellowcheck = 0;
	int NYellowcheck = 0;

	for (int i = 0; i < yellow; i++)
	{
		srand(time(NULL));
		MYellowcheck = rand() % m;

		if (MYellowcheck < 0)
		{
			MYellowcheck = 0;
			MYellowcheck++;
		}
		else if (MYellowcheck >= m)
		{
			MYellowcheck = MYellowcheck % m;
		}

		srand((int)time(NULL));
		NYellowcheck = rand() % n;

		if (NYellowcheck < 0)
		{
			NYellowcheck = 0;
			NYellowcheck++;
		}
		else if (NYellowcheck >= n)
		{
			NYellowcheck = NYellowcheck % n;
		}

		if (tile[MYellowcheck][NYellowcheck] == BLACK) 
		{
			tile[MYellowcheck][NYellowcheck] = YELLOW;
		}
		else
		{
			AgainYellowTable(MYellowcheck, NYellowcheck, tile);
		}
	}
}

int YellowCnt(int tile[][INDEXMAX], int m, int n)
{
	int check[INDEXMAX][INDEXMAX] = { 0, };
	int Ycnt = 0;
	
	for (int i = 0; i < m; i++)
	{
		for (int k = 0; k < n; k++)
		{
			Ycnt = SquareCheck(tile, i, k);
			
			if (tile[i][k] == YELLOW)
			{
				if (i != 0 && k != 0) 
				{
					if (check[i - 1][k - 1] < Ycnt)
					{
						check[i][k] = Ycnt;
					}
					else
					{
						check[i][k] = Max(check[i - 1][k], check[i][m - 1]);
					}
				}
				else
				{
					check[i][k] = Ycnt;
				}
			}
			else
			{
				if (i != 0 && k != 0)
				{
					check[i][k] = Max(check[i - 1][k], check[i][m - 1]);
				}
				else
				{
					check[i][k] = Ycnt;
				}
			}
		}
	}

	return check[m - 1][n - 1];
}

int SquareCheck(int tile[][INDEXMAX],int m, int n)
{

	int cnt = 1;
	int length = 1; // (m, n) 좌표의 반대편에 있는 좌표를 찾아준다.

	while (1)
	{
		if (tile[m - length][n - length] == YELLOW) 
		{
			for (int i = m - length; i >= m; i--)
			{
				if (tile[i][n - length] == BLACK)
				{
					return cnt;
				}
			}

			for (int i = n - length; i >= n; i--)
			{
				if (tile[m - length][i] == BLACK)
				{
					return cnt;
				}
			}
		}
		else
		{
			return cnt;
		}

		cnt++;
		length++;
	}
}

int AgainYellowTable(int MYellowcheck, int NYellowcheck, int tile[][INDEXMAX])
{

	for (int i = 0; i < MAXLOOP; i++)
	{
		srand(time(NULL));
		MYellowcheck = rand() % INDEXMAX;

		srand(time(NULL));
		NYellowcheck = rand() % INDEXMAX;

		if (tile[MYellowcheck][NYellowcheck] == BLACK)
		{
			tile[MYellowcheck][NYellowcheck] = YELLOW;
			return 0;
		}
	}
	
}

int Max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
		return b;
}