#include <stdio.h>

int main(void) 
{
	int data[] = { 3,21,35,57,24,82,8 };
	
	for (int i = 0; i <= 6; i++)
	{
		*(data + i) += 10;
	}

	for (int m = 0; m <= 6; m++)
	{
		printf("data[%d] = %d\n", m, data[m]);
	}
	
	return 0;
}