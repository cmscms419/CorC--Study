/*
���α׷� ��: C_subnet
�ۼ���: ä�μ�
�ۼ�����: 2021/04/22 ~ 2021/04/27
����: Visual Studio 2019
*/
#include "subnet.h"

int main(void) {
	ip search;
	ip sub;

	char search_NA[20] = "\0";
	int Least_b = 0;
	int sum = 0;
	int *subnet;
	int firstSubnetIpcnt = 0;

	init_funtion(&search);
	init_funtion(&sub);

	printf("- ��Ʈ��ũ �ּ�: ");
	scanf("%s", search_NA);

	networkAddressReturn(search_NA, &search);

	printf("- �⺻ Subnet  : ");
	scanf(" %d", &search.subnet);
	search.subnet = (int)search.subnet;

	printf("- ���ϴ� ����� ��: ");
	scanf(" %d", &firstSubnetIpcnt);
	firstSubnetIpcnt = (int)firstSubnetIpcnt;

	if (search.subnet <= 0 && firstSubnetIpcnt <= 0) {
		printf("�ٽ� �Է����ּ���");
		exit(1);
	}

	subnet = (int *)calloc(search.subnet_ipcnt, sizeof(int));
	search.subnet_ipcnt = firstSubnetIpcnt;

	printf("- ��Ʈ��ũ �ּ�\n");
	for (int i = 0; i < firstSubnetIpcnt; i++)
	{
		printf("SN%d: ", i + 1);
		scanf(" %d", &subnet[i]);
		sum = sum + subnet[i];
	}

	descending(subnet);

	printf("	NW ID		Broadcast		Range\n");
	for (int i = 0; i < firstSubnetIpcnt; i++)
	{
		printf("SN%d : ", i + 1);
		Least_b = subnetLeast(subnet[i]);
		fabaAndRange(&search, &sub, Least_b);

		if (search.subnet_ipcnt <= 0) {
			printf("��� ������� �Ҵ��Ͽ����ϴ�.\n");
			break;
		}
	}
	
	free(subnet);

	return 0;
}

void fabaAndRange(ip* search, ip* sub, int b_n) {
	int fa[4];
	int bc[4];
	int n = search->subnet / 8;
	int m = search->subnet % 8;

	if (n >= 4) {
		printf("���̻� ����� ���� �Ұ��� �մϴ�\n");
		exit(1);
	}

	ip_sub(search, sub);

	// first address
	first_address(sub, b_n);

	for (int i = 0; i < 4; i++)
	{
		fa[i] = binary_trans_decimal(sub->nw_ID, i);
		if (i >= 3) {
			printf("%-10d", fa[i]);
			break;
		}
		printf("%d.", fa[i]);
	}
	

	//broadcast
	broadcast(sub, b_n);
	for (int i = 0; i < 4; i++)
	{
		bc[i] = binary_trans_decimal(sub->broadcast, i);
		if (i >= 3) {
			printf("%-10d", bc[i]);
			break;
		}
		printf("%d.", bc[i]);
	}


	sub->subnet = 32 - b_n;// ������� subnet mask

	//Range
	printf("%d.%d.%d.%d ~ %d.%d.%d.%d   /%d\n",
		fa[0], fa[1], fa[2], fa[3] + 1,
		bc[0], bc[1], bc[2], bc[3] - 1,
		sub->subnet);

	for (int i = 0; i < 4; i++)
	{
		for (int m = 0; m < 8; m++)
		{
			search->p_binary[i][m] = sub->broadcast[i][m];
		}
	}

	nextSubnet(search);
	search->subnet = sub->subnet;
	search->subnet_ipcnt--;

	return;
}