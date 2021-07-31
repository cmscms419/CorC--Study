#include <stdio.h>

int main() {
	int vy[4][4] = { {78,48,78,98},{99,92,83,29},{29,64,83,89},{34,78,92,56} };
	int row = 0;
	int line = 0;
	int aa = 0;

	for (int i = 0; i < 4; i++)
	{
		row = 0; line = 0;
		for (int m = 0; m < 4; m++)
		{
			row += vy[i][m];
		}

		for (int x = 0; x < 4; x++)
		{
			line += vy[x][i];
		}

		aa += row;

		printf("%d번째 세로의 합: %d\n%d번쨰 가로의 합: %d\n", i + 1, line, i + 1, row);

	}
	
	printf("모든 수의 합: %d\n", aa);

	return 0;
}