#include <stdio.h>

void as(int i) {
	if (i > 1) {
		as(i / 2);
		as(i / 2);
	}
	printf("*");
}

int main()
{
	as(5);
	return 0;
}