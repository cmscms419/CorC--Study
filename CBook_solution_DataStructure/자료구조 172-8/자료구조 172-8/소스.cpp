#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
typedef int element;
typedef struct {
	element data[MAX_SIZE];
	int front, rear;
} dequetype;
//오류 함수
void error(char *mes) {
	fprintf(stderr, "%s\n", mes);
	exit(1);
}

//초기화
void init_deque(dequetype *q) {
	q->front = q->rear = 0;
}

//공백 상태 검출
int is_empty(dequetype *q) {
	return (q->front == q->rear);
}

//포화 상태 검출
int is_full(dequetype *q) {
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

//원형큐 출력 함수
void deque_print(dequetype *q) {
	printf("원형큐(front=%d, rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	puts("");
}

//삽입
void enqueue(dequetype *q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

//삭제 함수
element dequeue(dequetype *q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[q->front];
}

//삭제 함수
element peek(dequetype *q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_SIZE];
}

//요소 개수 반환
int get_count(dequetype *q) {
	return (q->rear - q->front) % MAX_SIZE;
}

int main() {
	dequetype deq;
	int element = 0;

	init_deque(&deq);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&deq)) {
		printf("정수를 입력하시오: ");
		if (element == 999) break;
		scanf_s("%d", &element);
		enqueue(&deq, element);
		deque_print(&deq);
		
	}
	printf("큐는 포화상태입니다.\n\n");

	printf("원형큐의 요소의 개수\n");
	printf("원형큐 deq의 요소의 개수: %d", get_count(&deq));
	
}