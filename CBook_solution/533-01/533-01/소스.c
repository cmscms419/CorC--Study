#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mastrlen(const char *p);

int main() {
	char p[50];

	gets(p);
	printf("mystrlen = %d\n",mastrlen(p));
	printf("strlen = %d\n", strlen(p));

	return 0;
}

int mastrlen(const char *p) {
	int n = 0;
	while (1) {
		if (p[n] != '\0')
			n++;
		else 
			break;
	}

	return n;
}