#include "subnet.h"

//원래 ip의 2진수<->10진수 변환 함수
int binary_trans_decimal(int array[][8], int cnt) {
	int decimal = 0;

	for (int i = 0; i < 8; i++)
	{
		decimal = decimal + array[cnt][i] * (int)pow(2, i);
	}

	return decimal;
}
