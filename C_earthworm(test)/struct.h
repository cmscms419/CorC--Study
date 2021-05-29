#pragma once

#pragma pack(push,1)

//지렁이 구조체
typedef struct _WORM
{
	int x;	//x좌표
	int y;	//y좌표
	char direction;	//진행방향
	struct _WORM* next;	//다음노드주소
	struct _WORM* before;//이전노드주소
}WORM, *pWORM;

//아이템 구조체
typedef struct _ITEM
{
	int x;
	int y;
	int itemType;
	int itemNo;
	struct _ITEM* next;
}ITEM, *pITEM;
#pragma pack(pop)