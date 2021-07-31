#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10


int main(void) {
	int n = 1, guess, input;
	srand((long)time(NULL));
	guess = rand() % MAX + 1;

	printf("1에서 %d사이에서의 정수로 결정된다.\n", MAX);
	printf("이 정수는 무엇인지 7번 안에 맞춰라.\n");

	while (1)
	{
		scanf_s("%d", &input);
		if (n == 7) {
			puts("모든 기회를 쓰셨습니다.");
			return 0;
		}
		if (guess == input) {
			puts("정답 입니다.");
			break;
		}
		else if (guess < input) {
			printf("정답보다 큰 수 입니다.\n");
		}
		else if (guess > input) {
			printf("정답보다 작은 수 입니다.\n");
		}
		n++;
	}
	return 0;
}