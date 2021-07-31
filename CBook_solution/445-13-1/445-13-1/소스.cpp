#include <stdio.h>

int main()
{
	int a[4][3] = { {46,79,78},{35,57,28},{43,68,76},{56,78,98} };
	int b[4][3] = { {78,35,99},{85,82,34},{58,69,29},{34,59,35} };

	for (int i = 0; i < 4; i++)
	{
		for (int m = 0; m < 3; m++)
		{
			printf("%d행 %d열의 합: %d\n", i + 1, m + 1, a[i][m] + b[i][m]);
			
			if (a[i][m] > b[i][m]) {
				printf("%d행 %d열의 차: %d\n", i + 1, m + 1, a[i][m] - b[i][m]);
			} else printf("%d행 %d열의 차: %d\n", i + 1, m + 1, b[i][m] - a[i][m]);
		}
	}
	return 0;
}