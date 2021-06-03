#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NODE 8
#define MAX_EAGE 14

typedef int element;
typedef int weight;

typedef struct {
	element data;
	weight number;
	struct ListNode* link;
} ListNode;


ListNode* insert_first(ListNode* head, int value, int weight) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	p->number = weight;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, int value, int weight) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	p->number = weight;
	head->link = p;
	return head;
}

void headfree(ListNode* head)
{

	ListNode* remove;
	if (head == NULL)
	{
		return NULL;
	}

	remove = head;
	head = remove->link;
	free(remove);
}

int main()
{
	FILE* f = fopen("Graph_11.txt", "r");
	if (f == NULL)
	{
		printf("fopen error\n");
		return 0;
	}

	
	// 연결리스트
	ListNode* head[MAX_NODE] = { NULL, };

	// 정점이 무엇이 있는지 알려주 었다.
	for (int i = 0; i < MAX_NODE; i++)
	{
		head[i] = insert_first(&head[i], i, 0);
	}

	for (int i = 0; i < MAX_EAGE; i++)
	{

	}




	fclose(f);
	
	return 0;
}