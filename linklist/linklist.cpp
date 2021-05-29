#include <stdio.h>

typedef struct list
{
	int n;
	list* next;
}list;


int main()
{ 
	list array[7] = { {0},{1},{2},{3},{4},{5},{6} };
	array[0].next->n = 1;
	array[0].next->next->n = 2;
	array[0].next->next->next->n = 5;

	array[1].next->n = 4;

	array[3].next->n = 2;
	array[3].next->next->n = 4;
	array[3].next->next->next->n = 5;
	array[3].next->next->next->next->n = 6;

	array[5].next->n = 2;

	array[6].next->n = 0;
	array[6].next->next->n = 4;

	return 0;
}