#include <stdio.h>
#define MAX_INT 100

int two[10] = { 1,2,4,8,16,32,64,128,256,512 };

void prt(int m[]) {
	for (int i = 0; i < MAX_INT; i++)
	{
		if (two[i] == NULL)
			break;
		printf("two[%d] = %d\n", i, m[i]);
	}

	return;
}

int main() {
	prt(two);

	return 0;
}