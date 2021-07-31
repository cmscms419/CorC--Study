#include <stdio.h>
#include <math.h>

int main(void) {

	int anw_1 = 0, anw_2 = 0;

	printf("%8d\n", 0);

	for (int a = 1; a <= 7; a++)
	{
		 int anw_1 = 0;
		 int anw_2 = 0;
		for (int i = 1; i <= a; i++){
			anw_1 += pow(10, a - i)*(a - i + 1);
			}
		 printf("%7d", anw_1);
		 printf("0");
		for (int m = 1; m <= a; m++){
			anw_2 += pow(10, a - m)*m;
		}
		printf("%d\n", anw_2);
	}
	return 0;
}