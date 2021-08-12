#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 10 //스택의 최대 크기
int stack[MAX_SIZE];//1차원 배열
int top = -1;
int n; //정수 배열의 크기 결정하는 정수

//공백 상태 검사
int is_empty()
{
	return (top == -1);
}
//포화 상태 검사
int is_full()
{
	return (top == (MAX_SIZE - 1));
}
//삽입
void push(int item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 상태");
		return;
	}
	else stack[++top] = item;
}
//삭제
int pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러");
		exit(1);
	}
	else return stack[top--];
}

//배열에 요소 저장
void prt_n() {

	printf("정수 배열의 크기: ");
	scanf_s("%d", &n);

	printf("정수를 입력하시오:");

	for (int i = 0; i < n; i++)
	{
		int m; //함수 push()에 메계변수 들어갈 요소
		printf("");
		scanf_s("%d", &m);
		push(m);
	}
}

//배열 반전 출력
void prt_d() {
	printf("반전된 정수 배열: ");
	for (int i = n; i > 0; i--)
	{
		printf("%d ", pop());
	}
	puts("");
}
int main() {
	prt_n();
	prt_d();
	
	return 0;
}