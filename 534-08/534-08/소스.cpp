#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	const char *delin = " ";

	printf("������ �Է��Ͻÿ�.\n");
	gets_s(str);

	printf("������ �ܾ �յڸ� �ٲٸ� �̷��� �ȴ�.\n");
	char *pt = strtok(str, delin);
	while (pt != NULL)
	{
		for (int i = strlen(pt) - 1; i >= 0; i--)
		{
			printf("%c", pt[i]);
		}
		pt = strtok(NULL, delin);
		if (pt == NULL)
			break;
		else printf(" ");
	}
	puts("");
	return 0;
}