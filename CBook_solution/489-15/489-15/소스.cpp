#include <stdio.h>

int is(int a[], int b[], int n/*배열 원소 수*/);

int main(void) {
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	int b[] = { 1,2,3,4,5,6,7 };
	int n = 0;

	n = sizeof(a) / sizeof(a[0]);
	printf("a와 b의 배열 원소값의 일치: %d\n", is(a, b, n));
}

int is(int a[], int b[], int n) {
	int m = 0; // 서로의 배열의 원소값이 일치한 횟수
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i])
			m++;
		else if (a[i] != b[i])
			return 0;
		else if (m == n)
			return 1;
	}
}