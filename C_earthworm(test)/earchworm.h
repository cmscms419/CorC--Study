#pragma once

#include <stdio.h>	//표준입출력헤더
#include <stdlib.h>	//malloc, free 등
#include <Windows.h>//windows console api 헤더
#include <time.h>	//랜덤 시드용 time 함수 헤더
#include <conio.h>	//gotoxy에서 사용할 api 헤더, 콘솔 입출력 함수를 제공하는 헤더 파일

#define FIELD_WIDTH 50	//필드가로길이
#define FIELD_HEIGHT 25	//필드세로길이
#define LEFT 75			//키보드 좌 화살표의 char값
#define RIGHT 77		//키보드 우
#define UP 72			//키보드 위
#define DOWN 80			//지보드 아래
#define ITEM_MAX 2		//화면에 표시되는 아이템개수
#define ITEM_GOLD 101	//골드 아이템 인디케이터
#define ITEM_EXP 102	//경험치 아이템 인디케이터
#define LEFT_MARGIN 30	//화면왼쪽마진(공백)
#define TOP_MARGIN 3	//화면 상단마진(공백)
#define DELAYTIME 200	//Sleep함수에 들어갈 x/1000 초