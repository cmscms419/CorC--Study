#include <stdio.h>
#include <stdlib.h>

typedef struct lnote {
	int data;
	struct lnote *link;
}lnote;

//����
lnote *createN(int data) {
	lnote*temp = (lnote*)malloc(sizeof(lnote));
	temp->link = NULL;
	temp->data = data;
	return temp;
}

//����
void error(char *mes) {
	fprintf(stderr, "%s\n", mes);
	exit(1);
}

//����
lnote* insert(lnote *head, int value) {
	lnote *p = (lnote *)malloc(sizeof(lnote));
		p->data = value;
		p->link = head;
		head = p;
		return head;
}

//�߰�
void addnode(lnote **head, int data) {
	
	lnote *newnote = createN(data);
	
	if (*head == NULL) {
		*head = newnote;
	}
	else
	{
		lnote *temp = *head;
		
		while (temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = newnote;
	}
}

void printf_list(lnote *head) {
	for (lnote *p = head; p != NULL; p = p->link) 
		printf("%d->", p->data);
	printf("NULL\n");
}

int main() {
	lnote *head = NULL;
	int n = 0;
	int ndn = 0;

	printf("����� ����: : ");
	scanf_s("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		printf("��� #%d ������: ", i + 1);
		scanf_s("%d", &ndn);
		addnode(&head, ndn);
		printf_list(head);
	}
	return 0;
}