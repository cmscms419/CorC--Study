#include "subnet.h"

//입력받은 네트워크 주소를 int형으로 바꾸어서 변수에 저장한다.
//그리고 변수에 저장한 10진수 네트워크 주소를 2진수로 바꾸어서 저장한다.
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
			printf("다시 입력하세요.");
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
