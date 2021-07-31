#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void mystrcat(char s1[], char s2[]);

int main() {

	char s1[50];
	char s2[50];

	puts("문장을 두번 입력하시오-->");
	gets_s(s1, 50);
	gets_s(s2, 50);

	mystrcat(s1, s2);

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