#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
typedef int element;
typedef struct {
	element data[MAX_SIZE];
	int front, rear;
} dequetype;
//���� �Լ�
void error(char *mes) {
	fprintf(stderr, "%s\n", mes);
	exit(1);
}

//�ʱ�ȭ
void init_deque(dequetype *q) {
	q->front = q->rear = 0;
}

//���� ���� ����
int is_empty(dequetype *q) {
	return (q->front == q->rear);
}

//��ȭ ���� ����
int is_full(dequetype *q) {
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

//����ť ��� �Լ�
void deque_print(dequetype *q) {
	printf("����ť(front=%d, rear=%d) = ", q->front, q->rear);
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

//����
void enqueue(dequetype *q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

//���� �Լ�
element dequeue(dequetype *q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[q->front];
}

//���� �Լ�
element peek(dequetype *q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[(q->front + 1) % MAX_SIZE];
}

//��� ���� ��ȯ
int get_count(dequetype *q) {
	return (q->rear - q->front) % MAX_SIZE;
}

int main() {
	dequetype deq;
	int element = 0;

	init_deque(&deq);
	printf("--������ �߰� �ܰ�--\n");
	while (!is_full(&deq)) {
		printf("������ �Է��Ͻÿ�: ");
		if (element == 999) break;
		scanf_s("%d", &element);
		enqueue(&deq, element);
		deque_print(&deq);
		
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");

	printf("����ť�� ����� ����\n");
	printf("����ť deq�� ����� ����: %d", get_count(&deq));
	
}