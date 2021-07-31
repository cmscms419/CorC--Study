#include <stdio.h>

int ag(int n);

int main(void) {
	int n = 0;
	loop :
	printf("정수를 입력하시오: ");
	scanf_s("%d", &n);
	
	if (n <= 0) {
		printf("다시 입력하시오");
		goto loop;
	}

	printf("16진법으로 변환: ");
	ag(n);

	return 0;
}

int ag(int n) {
	printf("%X\n", n);
	return 0;
}