#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void delchar(char *str, const char ch);
void mystrcat(char s1[],char s2[]);

int main()
{
	char a[50];
	char b[50];
	

	gets_s(a);
	scanf("%s", &b);
	printf("%s, %s\n", a, b);
	mystrcat(a, b);
	
	return 0;
}

void mystrcat(char s1[], char s2[]) {
	int i = 0;
	int m = 0;
	char s3[100] = { NULL };

	while (1) {
		if (s1[i] != NULL) {
			s3[i] = s1[i];
			i++;
		}
		else break;
		printf("%d\n", i);
	}
	while (1)
	{
		if (s2[m] != NULL) {
			s3[i] = s2[m];
			i++;
			m++;
		}
		else break;
	}
	printf("%s\n", s3);
}

void delchar(char *str, const char ch) {
	for (int i = 0; str[i] != NULL; i++)
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