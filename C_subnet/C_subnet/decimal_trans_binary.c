#include "subnet.h"

//���� ip�� 10���� <->2���� ��ȯ �Լ�
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
