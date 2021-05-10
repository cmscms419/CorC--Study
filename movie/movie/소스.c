#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 500

typedef struct movie
{
	char movie_N[100];
	char acter_N[200];
	int OpenYear;
	int adnc;
} movie;


int main() {
	void check_atoi(movie *m, char *ptoken, int m_num, int cnt);
	int partition(int low, int high, movie *m);
	void quickSort(int low, int high, movie *m);

	FILE *f;
	movie m[26];
	char name[MAX];
	char *title;
	char *tokn = "\t";
	char *ptoken;
	int j = 0;

	f = fopen("movie.txt", "r");

	if (f == NULL) {
		printf("Don't open file\n");
		exit(1);
	}
	for (int i = 0; i < 26; i++) {
		title = fgets(name, sizeof(name), f);
		printf("%s \n", title);
		ptoken = strtok(title, tokn);
		j = 0;
		while (ptoken != NULL)
		{
			check_atoi(m, ptoken, i, j);
			ptoken = strtok(NULL, tokn);
			j++;
		}
	}
	fclose(f);

	quickSort(0, 25, m);

	for (int i = 25; i >= 0; i--) {
		printf("%-s %20s %5d %5d\n", m[i].movie_N, m[i].acter_N, m[i].OpenYear, m[i].adnc);
	}

	return 0;
}

void check_atoi(movie *m, char *ptoken, int m_num, int cnt) {
	if (cnt > 3) return;

	if (cnt == 0) {
		strcpy(m[m_num].movie_N, ptoken);
	}
	if (cnt == 1) {
		strcpy(m[m_num].acter_N, ptoken);
	}

	if (cnt == 2) {
		m[m_num].OpenYear = atoi(ptoken);
	}

	if (cnt == 3) {
		m[m_num].adnc = atoi(ptoken);
	}
}

int partition(int low, int high, movie *m) {
	int i = low;
	int j = high + 1;
	movie sub_file;
	while (1)
	{
		while (m[++i].adnc < m[low].adnc)
			if (i == high) break;
		while (m[low].adnc < m[--j].adnc)
			if (j == low) break;
		if (i >= j) break;
		sub_file = m[i];
		m[i] = m[j];
		m[j] = sub_file;
	}
	sub_file = m[low];
	m[low] = m[j];
	m[j] = sub_file;

	return j;
}

void quickSort(int low, int high, movie *m) {
	if (low >= high) return;
	int pivot = partition(low, high, m);
	quickSort(low, pivot - 1, m);
	quickSort(pivot + 1, high, m);
}