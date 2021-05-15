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
	int array[SIZE];
}subcost;

void init_distance(int distance[], int size);
int choose(int distance[], int n, int knowDistance[]);
void find_dikstra(cost* ospf, cost* sub_ospf, int start, int end);
void trace_path(int start, int end, subcost* router);
void printf_start_end(int s, int e, subcost* router, int distance);

int distance[SIZE]; // �����������κ����� �ִܰ�� �Ÿ�
int knowDistance[SIZE]; // �湮�� ���� ǥ��
int step = 1; // ����� ��� �Ǿ����� Ȯ���ϴ� �뵵
cost sub_ospf = { SIZE, };

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
	int start = 0;
	int end = 0;
	
	while (1)
	{
		printf("���� ����Ϳ� ���� ����� �Է�\n");
		printf("����� 0\n");
		scanf_s("%d %d", &start, &end);
		if (start < 0 || end < 0)
		{
			return 0;
		}
		find_dikstra(&ospf, &sub_ospf, start - 1, end - 1);
	}
	

	find_dikstra(&ospf, &sub_ospf, 5, 4);
	return 0;
}

//distance �迭�� �ʱ�ȭ �����ش�.
void init_distance(int distance[], int size)
{
	for (int i = 0; i < size; i++)
	{
		distance[i] = 0;
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

//Diskatra �˰���
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

void trace_path(int start, int end, subcost *router)
{
	if (start == end)
	{
		return;
	}

	trace_path(start, router->array[end], router);
	printf("%d -> ", router->array[end] + 1);
}

void printf_start_end(int s, int e, subcost* router, int distance)
{
	if (router->array[e] != 0)
	{
		trace_path(s, e, router);
	}
	else
	{
		printf("%d -> ", s + 1);
	}
	printf("%d / Cost : %d\n", e + 1, distance);
}
