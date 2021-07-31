#include <stdio.h>

int main() {
	int score[10] = { 0 };
	int aw = 0;
	int fq = 0;
	int fq_N = 0;
	int fq_FQ = 0;

	for (int i = 1; i <= 20; i++)
	{
		aw = 0;

		label:
		printf("%d쨰 0~9까지의 정수를 입력하시오. ",i);
		scanf_s("%d", &aw);

		if (aw <= 9 && aw >= 0)
			score[aw]++;
		else
			{
				printf("다시 입력하시오.\n");
				goto label;
			}
	}
	
	fq_FQ = score[0];

	for (int i = 0; i < 9; i++)
	{
		if (fq_FQ < score[i]) {
			fq_FQ = score[i];
			fq_N = i;
		}
	}

	printf("많이 입력 받은 숫자는 %d이고, 빈도수는 %d이다.", fq_N,fq_FQ);

	return 0;
	
}