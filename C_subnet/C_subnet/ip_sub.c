#include "subnet.h"

//원래 ip의 주소를 subnet에 넣어준다.
void ip_sub(ip* search, ip* sub) {
	for (int i = 0; i < 4; i++)
	{
		for (int m = 0; m < 8; m++)
		{
			sub->p_binary[i][m] = search->p_binary[i][m];
		}
	}
}
