#include <stdio.h>

int MaxLIS(int* c);
int lower_bound(int start, int end, int* arr, int target);

int s1[13] = { 1,10,5,20,15,12,30,49,25,35,66,75,44 };


int main(void)
{
	int c[13] = { 0, };
	int ans = 0;
	int j = 0;

	c[0] = s1[0];

	for (int i = 1; i < 13; i++)
	{
		if (c[j] < s1[i])
		{
			c[j + 1] = s1[i];
			j++;
		}
		else
		{
			ans = lower_bound(0, j, c, s1[i]);
			c[ans] = s1[i];
		}
	}

	printf("%d", j + 1);

	return 0;
}

int MaxLIS(int* c)
{
	int max = c[0];
	for (int i = 1; i < 13; i++)
	{
		if (max < c[i])
		{
			max = c[i];
		}
	}
	return max;
}

int lower_bound(int start, int end, int *arr, int target)
{
    int mid;

    while (end - start > 0)  // 주어진 범위[start,end]에서 탐색하도록 한다. start == end이면 반복 종료
    {
        mid = (start + end) / 2;
 
		if (arr[mid] < target) // 찾고자 하는 값보다 작으면 오른쪽으로 한 칸만 더 시작 구간 갱신
		{
			start = mid + 1;
		}
		else  // 찾고자 하는 값보다 크면 거기까지 끝 구간 갱신
		{
			end = mid;
		}
    }
    return end; // 찾는 구간에 없는 경우 가장 마지막 +1 위치 전달

//출처: https://www.crocus.co.kr/583 [Crocus]
}