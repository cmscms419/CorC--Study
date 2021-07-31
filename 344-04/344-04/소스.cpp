#include <stdio.h>

int main(void) {

	int cnt = 1;

	for (int i = 1; i <= 100; i++)
	{
		if (1 == i % 2 && i % 3 && i % 5 && i % 7)
		{
			printf("%2d  ", i);
			if (cnt % 10 == 0) {
				puts("");
			}
			cnt++;
		}
	}
	puts("");
	return 0;
}