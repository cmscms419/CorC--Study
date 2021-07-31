#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copyarray(int from[], int to[], int n/*배열 원소 수*/);

int main(void) {
	srand((long)time(NULL));
	int n = rand() % 10 + 1; // 배열 원소 수
	int from[] = { NULL };
	int to[] = { NULL };

	for (int i = 0; i < n; i++)
	{
		from[i] = i;
	}

	for (int i = 0; i < n - 1; i++)
	{
		printf("from의 배열 수와 각각의 배열의 값: ");
		printf("%d\n", from[i]);
	}
	//copyarray(from, to, n);
	
	return 0;
}

void copyarray(int from[], int to[], int n) {
	for (int i = 0; i < n; i++)
	{
		to[i] = from[i];
	}
	for (int i = 1; i < n; i++)
	{
		printf("to의 배열 수와 각각의 배열의 값: ");
		printf("%d\n", to[i - 1]);
	}
}