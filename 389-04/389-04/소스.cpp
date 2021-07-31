#include <stdio.h>

int main() {
	int value = 0x2F24263F;
	char *pc = (char *) &value;


	printf(" 저장값 주소값\n");
	for (int i = 0; i < 4; i++)
	{
		printf("   %c   %u\n", *(pc + i), pc + i);
	}

	return 0;
}