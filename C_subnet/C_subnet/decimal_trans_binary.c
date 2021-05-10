#include "subnet.h"

//원래 ip의 10진수 <->2진수 변환 함수
void decimal_trans_binary(int decimal, int array[][8], int cnt) {
	int mok, nmg, c = 0;

	do
	{
		mok = decimal / 2;
		nmg = decimal - mok * 2;
		array[cnt][c] = nmg;
		decimal = mok;
		c++;
	} while (mok != 0);

	return;
}
