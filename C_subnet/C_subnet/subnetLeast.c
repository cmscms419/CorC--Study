#include "subnet.h"

//����ݿ� �ּ������� �ʿ��� ��� ���� ����ؼ� �ʿ��� 2������ ���� ��ȯ
int subnetLeast(int sn) {
	int n = 0, b_n = 0;
	while (1)
	{
		if (n > sn) break;
		n = n + (int)pow(2, b_n);
		b_n++;
	}
	return b_n;
}
