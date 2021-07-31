#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	const char *delin = " ";

	printf("문장을 입력하시오.\n");
	gets_s(str);

	printf("문장의 단어를 앞뒤를 바꾸면 이렇게 된다.\n");
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