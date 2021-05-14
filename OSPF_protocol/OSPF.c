#include <stdio.h>

#define MAX 16
#define SIZE 8
#define FALSE 0
#define TRUE 1
#define _CRT_SECURE_NO_WARNINGS


typedef struct
{
	int n; //������ ����
	int  protocol[SIZE][SIZE]; // �� ������ �� �� �ִ� ���
} cost;

typedef struct
{
	int start;
	int end;
	int cnt;
	int array[SIZE];
}subcost;

void dikstra(cost* ospf_d, cost* ospf, int start, int end);
void init(int distance[], int size);
int choose(int distance[], int n, int knowDistance[]);

int distance[SIZE]; // �����������κ����� �ִܰ�� �Ÿ�
int knowDistance[SIZE]; // �湮�� ���� ǥ��
subcost dis; // 1. ���� �����, 2. ������ �����, 3 ������� ���
int step = 1; // ����� ��� �Ǿ����� Ȯ���ϴ� �뵵

int main(void)
{
	cost ospf = { SIZE,
			{
				{0, 2, 16, 16, 16, 3, 16, 16},
				{2, 0, 1, 4, 16, 16, 16, 16},
				{16, 1, 0, 16, 3, 16, 16, 16},
				{16, 4, 16, 0, 3, 16, 2, 16},
				{16, 16, 3, 3, 0, 16, 16, 4},
				{3, 16, 16, 16, 16, 0, 6, 16},
				{16, 16, 16, 2, 16, 6, 0, 4},
				{16, 16, 16, 16, 4, 16, 4, 0}
			}
	};

	cost ospf_d = { SIZE, }; // �� ����͵��� �ּ� ��� ���� �����Ѵ�.


	int n = 0;

	printf("%d ��°\n", 1);
	dikstra(&ospf_d, &ospf, 1, 3);
	

	return 0;
}

//distance �迭�� �ʱ�ȭ �����ش�.
void init(int distance[], int size)
{
	for (int i = 0; i < size; i++)
	{
		distance[i] = 0;
	}
}

//Diskatra �˰���
void dikstra(cost * ospf_d, cost* ospf, int start, int end)
{
	int lowdistance = 0;
	
	dis.start = start;
	dis.end = end;
	dis.cnt = 0;
	dis.array[dis.cnt++] = start;

	for (int i = 0; i < ospf->n; i++)
	{
		distance[i] = ospf->protocol[start][i];
		knowDistance[i] = FALSE;
	}

	int a = distance[end];
	knowDistance[start] = TRUE;
	distance[start] = 0;

	for (int i = 0; i < ospf->n; i++)
	{
		a = distance[end];
		lowdistance = choose(distance, ospf->n, knowDistance);
		knowDistance[lowdistance] = TRUE;

		for (int m = 0; m < ospf->n; m++)
		{
			if (!knowDistance[m])
			{
				if ((distance[lowdistance] + ospf->protocol[lowdistance][m]) < distance[m])
				{
					distance[m] = distance[lowdistance] + ospf->protocol[lowdistance][m];
				}
			}
		}


		if (distance[end] < a)
		{
			dis.array[dis.cnt++] = lowdistance;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		ospf_d->protocol[start][i] = distance[i];
	}

}

// ���� �߰����� ���� ���� �߿��� ���� ����� ���� ���� ��ȯ�� �ش�.
int choose(int distance[], int n, int knowDistance[])
{
	int minpos = -1;
	int min = _CRT_INT_MAX;

	for (int i = 0; i < n; i++)
	{
		if ((distance[i] < min) && !knowDistance[i])
		{
			min = distance[i];
			minpos = i;
		}
	}

	return minpos;
}
