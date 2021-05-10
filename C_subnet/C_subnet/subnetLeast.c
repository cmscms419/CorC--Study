#include "subnet.h"

//서브넷에 최소한으로 필요한 블록 수를 계산해서 필요한 2진수의 개수 반환
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
