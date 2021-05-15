#include <stdio.h>

typedef struct 
{
	int begin; // 시작 시간
	int end	   // 종료 시간
}signUp;

signUp studyArray[8] =
{
	{900, 1000},
	{1130, 1230},
	{1000, 1200},
	{1530, 1700},
	{1100, 1230},
	{1500, 1600},
	{1200, 1400},
	{1400, 1530}
};

int partion(int low, int hight);
int quick(int low, int hight);

int main(void)
{


	return 0;
}

int partion(int low,int hight)
{
	int i = low;
	int j = hight + 1;
	signUp change;

	while (1)
	{
		while (studyArray[++i].end < studyArray[low].end)
		{
			if (i >= hight)
			{
				break;
			}
		}

		while (studyArray[--j].end > studyArray[low].end) 
		{
			if (j <= low)
			{
				break;
			}
		}

		if (i >= j)
		{
			break;
		}
		change = studyArray[j];
		studyArray[j] = studyArray[i];
		studyArray[i] = change;
	}
	change = studyArray[j];
	studyArray[low] = studyArray[j];
	studyArray[low] = change;
	return j;
}

int quick(int low,int hight)
{
	if (low >= hight)
	{
		return 0;
	}

	int pivot = partion(low, hight);
	quick(low, pivot - 1);
	quick(pivot + 1, hight);
}

