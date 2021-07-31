#include <stdio.h>

float slS(int y, float r, int a);
float wlS(int y, float r, int a);

int main() {
	int n; // 선택
	int y = 0; // 만기까지의 기간
	float r = 0; // 이자율 (%를 소수로)
	int a = 0; // 원금
	while (1)
	{
		printf("단리 1번\n복리는 2번\n종료는 0번\n");
		scanf_s("%d", &n);

		if (n != 0, 1, 2) {
			printf("다시 입력하시오.\n");
			puts("");
		}

		if (n == 0) {
			return 0;
		}
		else if (n == 1) {
			printf("원금과 단기까지의 기간(년),이율을 순서대로 작성\n");
			scanf_s("%d %d %f", &a, &y, &r);
			printf("단기 이자: %.2f\n", slS(y, r, a));
			puts("");
		}
		else if (n == 2) {
			printf("원금과 단기까지의 기간,이율을 순서대로 작성\n");
			scanf_s("%d %d %f", &a, &y, &r);
			printf("복리 이자: %.2f\n", wlS(y, r, a));
			puts("");
		}
	}
}


float slS(int y, float r, int a) {
	return a*(1 + r*y);
}

float wlS(int y, float r, int a) {
	return a*(1 + r)*y;
}