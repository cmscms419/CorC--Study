#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
	int p_binary[4][8]; // ��Ʈ��ũ �ּҸ� 2�������� ������ ��
	int nw_ID[4][8];	// �� �ּ��� Network ID(first address)
	int broadcast[4][8];// �� �ּ��� last address
	int subnet;			// subnet
	int subnet_ipcnt;	// �� ����� �Ҵ� �ּ� ��
}ip;

void init_funtion(ip* p);
void decimal_trans_binary(int decimal, int array[][8], int cnt);
void networkAddressReturn(char* search_na, ip* search);
void fabaAndRange(ip* search, ip* sub, int b_n);
void ip_sub(ip* search, ip* sub);
void first_address(ip* sub, int b_n);
void broadcast(ip* sub, int b_n);
void nextSubnet(ip* search);
int subnetLeast(int sn);
int binary_trans_decimal(int array[][8], int cnt);
