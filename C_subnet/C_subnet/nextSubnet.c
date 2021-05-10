#include "subnet.h"


void nextSubnet(ip* search) {
	int m = 3;
	int n = binary_trans_decimal(search->p_binary, m);
	while (1)
	{
		if (n + 1 >= 255) {
			decimal_trans_binary(0, search->p_binary, m);
			n = binary_trans_decimal(search->p_binary, --m);
		}
		else break;
	}
	n++;
	decimal_trans_binary(n, search->p_binary, m);
	return;
}