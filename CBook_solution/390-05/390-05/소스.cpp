#include <stdio.h>

int main(void) {
	int i = 0x324F3A24;
	char *p = (char *) &i;

	for (int m = 3; m >= 0; m--)
	{
		printf("%X", *(p + m));
	}

	puts("");

	return 0;
}