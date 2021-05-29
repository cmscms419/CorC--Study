#pragma once

#pragma pack(push,1)

//������ ����ü
typedef struct _WORM
{
	int x;	//x��ǥ
	int y;	//y��ǥ
	char direction;	//�������
	struct _WORM* next;	//��������ּ�
	struct _WORM* before;//��������ּ�
}WORM, *pWORM;

//������ ����ü
typedef struct _ITEM
{
	int x;
	int y;
	int itemType;
	int itemNo;
	struct _ITEM* next;
}ITEM, *pITEM;
#pragma pack(pop)