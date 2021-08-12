#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 10 //������ �ִ� ũ��
int stack[MAX_SIZE];//1���� �迭
int top = -1;
int n; //���� �迭�� ũ�� �����ϴ� ����

//���� ���� �˻�
int is_empty()
{
	return (top == -1);
}
//��ȭ ���� �˻�
int is_full()
{
	return (top == (MAX_SIZE - 1));
}
//����
void push(int item) {
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����");
		return;
	}
	else stack[++top] = item;
}
//����
int pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����");
		exit(1);
	}
	else return stack[top--];
}

//�迭�� ��� ����
void prt_n() {

	printf("���� �迭�� ũ��: ");
	scanf_s("%d", &n);

	printf("������ �Է��Ͻÿ�:");

	for (int i = 0; i < n; i++)
	{
		int m; //�Լ� push()�� �ް躯�� �� ���
		printf("");
		scanf_s("%d", &m);
		push(m);
	}
}

//�迭 ���� ���
void prt_d() {
	printf("������ ���� �迭: ");
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