#include "subnet.h"


//ip 변수 값을 초기화 해주는 함수
void init_funtion(ip* p) 
{
	for (int i = 0; i < 4; i++)
	{
		for (int m = 0; m < 8; m++)
		{
			p->p_binary[i][m] = 0;
			p->nw_ID[i][m] = 0;
			p->broadcast[i][m] = 0;
		}
	}
	p->subnet = 0;
	p->subnet_ipcnt = 0;

	return;
}