#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void delchar(char str[], const char ch);

int main() {
	char str[20];
	char ch = 'a';

	strcpy(str, "java");
	delchar(str, ch);

	return 0;
}

void delchar(char *str, const char ch) {
	for (int i = 0;str[i] != NULL; i++)
	{
		if (str[i] == ch) {
			for (int m = i; str[m] != NULL; m++)
			{
				str[m] = str[m + 1];
			}
			i--;
		}
	}
	printf("%s\n", str);
}