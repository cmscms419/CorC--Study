#include <stdio.h>

#define MAX 16
#define SIZE 8
#define FALSE 0
#define TRUE 1
#define _CRT_SECURE_NO_WARNINGS


typedef struct
{
	int n; //정점의 개수
	int  protocol[SIZE][SIZE]; // 각 정점의 갈 수 있는 비용
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

int distance[SIZE]; // 시작정점으로부터의 최단경로 거리
int knowDistance[SIZE]; // 방문한 정점 표시
subcost dis; // 1. 시작 라우터, 2. 마지막 라우터, 3 라우터의 경로
int step = 1; // 출력이 몇번 되었는지 확인하는 용도

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

	cost ospf_d = { SIZE, }; // 각 라우터들의 최소 비용 값을 저장한다.


	int n = 0;

	printf("%d 번째\n", 1);
	dikstra(&ospf_d, &ospf, 1, 3);
	

	return 0;
}

//distance 배열을 초기화 시켜준다.
void init(int distance[], int size)
{
	for (int i = 0; i < size; i++)
	{
		distance[i] = 0;
	}
}

//Diskatra 알고리즘
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

// 아직 발견하지 못한 정점 중에서 제일 비용이 낮은 곳을 반환해 준다.
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
