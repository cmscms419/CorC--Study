#include "subnet.h"

//�Է¹��� ��Ʈ��ũ �ּҸ� int������ �ٲپ ������ �����Ѵ�.
//�׸��� ������ ������ 10���� ��Ʈ��ũ �ּҸ� 2������ �ٲپ �����Ѵ�.
void networkAddressReturn(char* search_na, ip* search) {
	char* token;
	int cnt = 0;
	int decimal[4];

	token = strtok(search_na, ".");
	decimal[cnt] = atoi(token);
	cnt++;
	for (int i = 1; i < 4; i++)
	{
		token = strtok(NULL, ".");
		if (token == NULL) {
			printf("�ٽ� �Է��ϼ���.");
			exit(1);
		}
		decimal[i] = atoi(token);
	}

	for (int i = 0; i < 4; i++)
	{
		decimal_trans_binary(decimal[i], search->p_binary, i);
	}
	return;
}
