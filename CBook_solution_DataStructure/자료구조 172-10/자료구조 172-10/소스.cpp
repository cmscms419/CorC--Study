#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
	int front;
	int rear;
	int data[MAX_SIZE];
} queuetype;

//오류 함수
void error(char *mes) {
	fprintf(stderr, "%s\n", mes);
	exit(1);
}

void init_queue(queuetype *p) {
	p->front = -1;
	p->rear = -1;
}

void queue_print(queuetype *p) {
	for (int i = 0; i <= p->rear; i++)
	{
		if (i <= p->front || i > p->rear)
			printf(" | ");
		else
			printf("%d  |", p->data[i]);
	}
	printf("\n");
}

int is_full(queuetype *p) {
	if (p->rear == MAX_SIZE - 1)
		return 1;
	else
		return 0;
}

int is_empty(queuetype *p) {
	if (p->rear == p->front)
		return 1;
	else
		return 0;
}

void enqueue(queuetype *p, int item) {
	if (is_full(p)) {
		error("큐는 포화 상태입니다.");
		return;
	}
	p->data[++(p->rear)] = item;
}

void dequeue(queuetype *p) {
	if (is_empty(p)) {
		error("큐는 공백 상태입니다.");
		return;
	}
	p->data[++(p->front)] = NULL;
}

void F_enqueue(queuetype *p) {
	int item = 0;
	item = p->data[p->rear] + p->data[p->rear - 1];
	enqueue(p, item);
	dequeue(p);
}

int main() {
	queuetype F;
	init_queue(&F);
	enqueue(&F, 0);
	enqueue(&F, 1);

	for (int i = 0; i < 10; i++)
	{
		F_enqueue(&F);
		queue_print(&F);
		if (is_full(&F))
			break;
	}

	return 0;
}