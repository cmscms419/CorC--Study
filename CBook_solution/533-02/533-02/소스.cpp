#include <stdio.h>
#include <string.h>
void mystrcat(char s1[],const char s2[]);

int main() {
	char s1[50] = "C ";
	mystrcat(s1, "programming language");
	
	return 0;
}

void mystrcat(char s1[],const char s2[]) {
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