#include "subnet.h"

void descending(int* arrayInt) {

	int d_arrayInt;
	int j = 0;
	for (int i = 1; i < sizeof(arrayInt); i++)
	{
		d_arrayInt = arrayInt[i];
		j = i - 1;
		while (j >= 0 && arrayInt[j] < d_arrayInt)
		{
			arrayInt[j + 1] = arrayInt[j];
			j--;
			arrayInt[j + 1] = d_arrayInt;
		}
	}
	return;
}