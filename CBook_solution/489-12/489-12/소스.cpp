#include <stdio.h>

int ag(int n);

int main(void) {
	int n = 0;
	loop :
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &n);
	
	if (n <= 0) {
		printf("�ٽ� �Է��Ͻÿ�");
		goto loop;
	}

	printf("16�������� ��ȯ: ");
	ag(n);

	return 0;
}

int ag(int n) {
	printf("%X\n", n);
	return 0;
}