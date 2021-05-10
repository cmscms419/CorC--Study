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

    while (end - start > 0)  // �־��� ����[start,end]���� Ž���ϵ��� �Ѵ�. start == end�̸� �ݺ� ����
    {
        mid = (start + end) / 2;
 
		if (arr[mid] < target) // ã���� �ϴ� ������ ������ ���������� �� ĭ�� �� ���� ���� ����
		{
			start = mid + 1;
		}
		else  // ã���� �ϴ� ������ ũ�� �ű���� �� ���� ����
		{
			end = mid;
		}
    }
    return end; // ã�� ������ ���� ��� ���� ������ +1 ��ġ ����

//��ó: https://www.crocus.co.kr/583 [Crocus]
}