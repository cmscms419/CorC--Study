#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	int n = 0;
	int m = 0;
	char *s1;
	char *s2;

	scanf("%d", &n);

	s1 = (char*)calloc(n, sizeof(char));
	s2 = (char*)calloc(n, sizeof(char));

	scanf("%s", s1);
	
	// 거꾸로 출력
	for (int i = n - 1; i >= 0; i--)
	{
		printf("%c", s1[i]);
	}


	return 0;
} 
