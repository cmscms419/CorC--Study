#include <stdio.h>

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
	int array[SIZE];
}subcost;

int choose(int distance[], int n, int knowDistance[]);
void init_distance(int distance[], int size);
void find_dikstra(cost* ospf, cost* sub_ospf, int start, int end);
void trace_path(int start, int end, subcost* router);
void printf_start_end(int s, int e, subcost* router, int distance);

int distance[SIZE]; // 시작정점으로부터의 최단경로 거리
int knowDistance[SIZE]; // 방문한 정점 표시
int step = 1; // 출력이 몇번 되었는지 확인하는 용도

int main(void)
{
	cost sub_ospf = { SIZE, };
	cost ospf = { SIZE,
			{
				{0, 4, 16, 16, 16, 7, 16, 16},
				{4, 0, 8, 16, 16, 16, 16, 2},
				{16, 8, 0, 5, 7, 16, 16, 16},
				{16, 16, 5, 0, 4, 16, 16, 6},
				{16, 16, 7, 4, 0, 16, 3, 3},
				{7, 16, 16, 16, 16, 0,3, 5},
				{16 ,16 ,16 ,16, 3, 3, 0, 6},
				{16, 2 ,16, 6, 3, 5, 6, 0 }
			}
	};
	int start = 0;
	int end = 0;
	
	while (1)
	{
		printf("시작 라우터와 도착 라우터 입력\n");
		printf("종료는 0 미만 입력\n");
		
		scanf_s("%d", &start);
		if (start < 0)
		{
			return 0;
		}

		scanf_s("%d", &end);
		if (end < 0)
		{
			return 0;
		}

		find_dikstra(&ospf, &sub_ospf, start - 1, end - 1);
	}
	
	return 0;
}

//distance 배열을 초기화 시켜준다.
void init_distance(int distance[], int size)
{
	for (int i = 0; i < size; i++)
	{
		distance[i] = 0;
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

//Diskatra 알고리즘
void find_dikstra(cost *ospf,cost* sub_ospf, int start, int end)
{
	int lowdistance = 0;
	subcost router;
	
	router.start = start;
	router.end = end;

	for (int i = 0; i < SIZE; i++)
	{
		router.array[i] = start;
	}

	init_distance(distance, SIZE);

	for (int i = 0; i < ospf->n; i++)
	{
		distance[i] = ospf->protocol[start][i];
		knowDistance[i] = FALSE;
	}

	knowDistance[start] = TRUE;
	distance[start] = 0;

	for (int i = 0; i < ospf->n - 1; i++)
	{
		lowdistance = choose(distance, ospf->n, knowDistance);
		knowDistance[lowdistance] = TRUE;

		for (int m = 0; m < ospf->n; m++)
		{
			if (!knowDistance[m])
			{
				if ((distance[lowdistance] + ospf->protocol[lowdistance][m]) < distance[m])
				{
					distance[m] = distance[lowdistance] + ospf->protocol[lowdistance][m];
					router.array[m] = lowdistance;
				}
			}
		}


	}
	printf_start_end(router.start, router.end, &router, distance[end]);
}

/*끝 라우터 부터 재귀함수 순으로 되돌아가는 순서*/
void trace_path(int start, int end, subcost *router)
{
	if (start == end)
	{
		return;
	}

	trace_path(start, router->array[end], router);
	printf("%d -> ", router->array[end] + 1);
}

// ospf 출력
void printf_start_end(int s, int e, subcost* router, int distance)
{
	printf("%d/", distance);
	if (router->array[e] != 0)
	{
		trace_path(s, e, router);
	}
	else
	{
		printf("%d -> ", s + 1);
	}
	printf("%d/\n", e + 1);
}
