#include "subnet.h"


// first address 구하기
void first_address(ip* sub, int b_n) {
	int n = 32 - b_n;
	int sum = pow(2, b_n);
	int check = 0;
	int b_n_ga = b_n % 8;
	int ncke = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int m = 0; m < 8; m++)
		{
			sub->nw_ID[i][m] = sub->p_binary[i][m];
		}
	}

	for (int m = 3; m > 0; m--)
		{
			for (int i = 0; i < 8; i++)
			{
				if (check >= pow(2, b_n) - 1) break;
				sub->nw_ID[m][i] = 0;
				check = check + pow(2, ncke);
				ncke++;
			}
		}
	
	return;
}

//broadcast 구하기
void broadcast(ip* sub, int b_n) {
	int n = 32 - b_n;
	int sum = pow(2, b_n);
	int check = 0;
	int b_n_ga = b_n % 8;
	int ncke = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int m = 0; m < 8; m++)
		{
			sub->broadcast[i][m] = sub->nw_ID[i][m];
		}
	}

	for (int m = 3; m > 0; m--)
	{
		for (int i = 0; i < 8; i++)
		{
			if (check >= pow(2, b_n) - 1) break;
			sub->broadcast[m][i] = 1;
			check = check + pow(2, ncke);
			ncke++;
		}
	}


	return;
}
