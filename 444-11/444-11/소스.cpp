#include <stdio.h>

int main()
{
	int tc[5][4] = { {97,90,88,95},{76,89,75,83},{60,70,88,82},{83,89,92,85},{75,73,72,78} };
	char stn[5][8] = {"������","����","�����","�����","�̸��"};
	int acp = 0;
	int aca = 0;

	for (int i = 0; i < 5; i++)
	{
		acp = 0; aca = 0;
		for (int m = 0; m < 4; m++)
		{
			acp += tc[i][m];
		}
		aca = acp / 4;

		printf("%s", stn[i]);
		printf(": ������ �� %d ������ ��� %d\n", acp,aca);
	}

	return 0;
}