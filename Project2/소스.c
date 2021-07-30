#include <stdio.h>
#include <stdlib.h>


int main()
{
	int* a = (int*)calloc(1, sizeof(int));
	int pushint = 0;

	scanf_s(" %d", &pushint);
	*a = pushint;

	if (a == NULL)
	{
		a = NULL;
		free(a);
	}

	int* c = (int*)calloc(*a, sizeof(int));

	if (c == NULL)
	{
		c = NULL;
		free(c);
	}

	for (int i = 0; i < *a; i++)
	{
		scanf_s(" %d", &pushint);
		c[i] = pushint;
	}

	
	int* b = (int*)calloc(1, sizeof(int));

	scanf_s(" %d", &pushint);
	*b = pushint;

	if (b == NULL)
	{
		b = NULL;
		free(b);
	}
	
	int* d = (int*)calloc(*b, sizeof(int));
	if (d == NULL)
	{
		d = NULL;
		free(d);
	}

	for (int i = 0; i < *b; i++)
	{
		scanf_s(" %d", &pushint);
		d[i] = pushint;
	}




	free(a);
	free(b);
	free(c);
	free(d);

	return 0;
}

