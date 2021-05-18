#include <stdio.h>

typedef struct 
{
	int begin; // 시작 시간
	int end;	   // 종료 시간
}signUp;

signUp init = { 0 ,0 };

#define MAXSIZE 8
#define INIT init

signUp studyArray[MAXSIZE] =
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

void schedule(signUp array[]);
int partion(int low, int hight);
int quick(int low, int hight);

int main(void)
{
	quick(0, MAXSIZE - 1);
	schedule(studyArray);


	return 0;
}

void schedule(signUp suarray[])
{
	// 최대한 예약을 할 수 있는 리스트
	signUp j[MAXSIZE] = { suarray[0] };

	// 임시 예약 리스트
	signUp k[MAXSIZE] = { suarray[0] };

	// 임시, 실제 리스트에 
	int ckk = 1;

	for (int i = 1; i < MAXSIZE; i++)
	{
		k[ckk] = suarray[i];

		if (k[ckk - 1].end <= k[ckk].begin)
		{
			j[ckk] = suarray[i];
			ckk++;
		}
		else
		{
			k[ckk] = INIT;
		}
	}

	for (int i = 0; i < ckk; i++)
	{
		printf("예약 시작 시간 : %d\n예약 종료 시간 : %d", j[i].begin, j[i].end);
		printf("\n\n");
	}

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
	studyArray[j] = studyArray[low];
	studyArray[low] = change;
	return j;
}

int quick(int low,int hight)
{
	if (low >= hight)	return 0;
	int pivot = partion(low, hight);
	quick(low, pivot - 1);
	quick(pivot + 1, hight);
}

