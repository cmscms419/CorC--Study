#include <stdio.h>

int is(int a[], int b[], int n/*�迭 ���� ��*/);

int main(void) {
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	int b[] = { 1,2,3,4,5,6,7 };
	int n = 0;

	n = sizeof(a) / sizeof(a[0]);
	printf("a�� b�� �迭 ���Ұ��� ��ġ: %d\n", is(a, b, n));
}

int is(int a[], int b[], int n) {
	int m = 0; // ������ �迭�� ���Ұ��� ��ġ�� Ƚ��
	
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