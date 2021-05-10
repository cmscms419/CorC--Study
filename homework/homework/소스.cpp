#define _CRT_SECURE_NO_WARNINGS
#define HASH_TABLE 8000
#define FIRST_SIZE 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char key[5];
	char value[100];
}element;

element hash_table[HASH_TABLE];

int hash_lp_add(int key_index, element e, element ht[], int size);
int strlen_keySame(element ht);
int strcmp_keySame(element ht, element key);
int trandsform(char *key);
int hash_function(char *key, int size);
int sizeUp(element ht[], int size);
void hash_search(element search, element ht[], int size);
void init_table(element ht[], int size);


int main()
{
	FILE *f; // ����
	element search; // �˻� �޴� ���
	element e; // �Է� �޴� ���

	int table_size = FIRST_SIZE;
	char buffer[500] = "";
	char *token;
	int key_index = 0; // key�� hashing address�� �ٲ� ���� �޴� ��
	int cnt = 0; // ������ �Ǵ�

	init_table(hash_table, HASH_TABLE);

	f = fopen("CARRIERS.txt", "r");

	if (f == NULL) {
		printf("Don't open file\n");
		exit(1);
	}

	while (fgets(buffer, sizeof(buffer), f) != NULL)
	{
		token = strtok(buffer, "\t");
		strcpy(e.key, token);
		token = strtok(NULL , "\t");
		strcpy(e.value, token);
		token = strtok(NULL, "");

		if (table_size < (cnt + 1) * 2 ) {
			table_size = sizeUp(hash_table, table_size);
			cnt = 0;
		}

		hash_function(e.key, table_size);
		hash_lp_add(key_index, e, hash_table, table_size);

		cnt++;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d ���� �˻�: ", i + 1);
		scanf("%s", search.key);

		hash_search(search, hash_table, table_size);
	}

	return 0;
}

// ��� ���̺� �ʱ�ȭ �ش�.
void init_table(element ht[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		ht[i].key[0] = NULL;
		ht[i].value[0] = NULL;
	}
}

//key�� int�� ��ȯ�� �ش�.
int trandsform(char *key) {
	char *token;
	char string[10];
	int number = 0;
	int cnt = 0;
	
	strtok(key, " ");

	while (key[cnt] != 32 && key[cnt] != NULL && key[cnt] != 40)
	{
		number = number * 51 + key[cnt];
		cnt++;
	}

	return number;
}

// key�� ����ּҸ� ��ȯ�Ѵ�.
int hash_function(char *key, int size) {
	return trandsform(key) % size;
}

// ��� ���̺� key�� value�� �־��ش�.
int hash_lp_add(int key_index, element e, element ht[], int size) {
	if (strlen_keySame(ht[key_index])) {
		if (strcmp_keySame(ht[key_index], e) == 0) {
			strcpy(ht[key_index].value, e.value);
			return key_index;
		}else {
			key_index = (key_index + 1) % size;
			hash_lp_add(key_index, e, ht, size);
			return key_index;
		}
	}
	strcpy(ht[key_index].key, e.key);
	strcpy(ht[key_index].value, e.value);
	return key_index;
}

//key�� �ִ��� �˷��ش�.
int strlen_keySame(element ht) {
	if (strlen(ht.key) == 0) return 0;
	return 1;
}

// key�� ������ �����ش�
int strcmp_keySame(element ht, element key) {
	return strcmp(ht.key, key.key);
}

// �������� 50%�� �Ѿ �� ������ ũ�⸦ 2�� �÷��ش�.
int sizeUp(element ht[], int size) {

	element *htSum = (element *)malloc(sizeof(element) * size);
	int key_indexSum = 0;

	init_table(htSum, size);

	for (int i = 0; i < size; i++){
		if (strlen_keySame(ht[i]) != 0) {
			strcpy(htSum[i].key, ht[i].key);
			strcpy(htSum[i].value, ht[i].value);
		}
	}

	init_table(ht, size);

	for (int m = 0; m < size; m++)
	{
		if (strlen_keySame(htSum[m]) != 0) {
			key_indexSum = hash_function(htSum[m].key, size * 2);
			hash_lp_add(key_indexSum, htSum[m], ht, size * 2);
		}

	}

	size = size * 2;
	free(htSum);

	return size;
}

// �˻��� �ش�.
void hash_search(element search, element ht[], int size) {
	int sKeyIndex = hash_function(search.key, size);
	
	for (int i = 0; i < size; i++)
	{
		if (strcmp_keySame(ht[sKeyIndex], search) == 0) {
			printf("key   ���: %s\n", ht[sKeyIndex].key);
			printf("value ���: %s\n", ht[sKeyIndex].value);
			return;
		}
		sKeyIndex = (sKeyIndex + 1) % size;
	}
	printf("�˻� ����� �����ϴ�.");
	return;
}