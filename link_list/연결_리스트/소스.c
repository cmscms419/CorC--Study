#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode  *head, int value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode  *head, int value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	head->link = p;
	return head;
}

int count_ListNode(ListNode *head) {
	int ListNode_count_num = 0;

	for (ListNode *p = head; p != NULL; p = p->link)
	{
		ListNode_count_num++;
	}
	
	return ListNode_count_num;
}
int main()
{
	ListNode *head = NULL;
	int count = 0;
	int value = 0;

	printf("노드의 개수 : ");
	scanf_s("%d", &count);

	for (int i = 0; i < count; i++)
	{
		printf("노드 #%d 데이터 : ", i + 1);
		scanf_s("%d", &value);
		head = insert_first(head, value);
	}

	printf("연결 리스트 노드의 개수: %d", count_ListNode(head));

	return 0;
}