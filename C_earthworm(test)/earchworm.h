#pragma once

#include <stdio.h>	//ǥ����������
#include <stdlib.h>	//malloc, free ��
#include <Windows.h>//windows console api ���
#include <time.h>	//���� �õ�� time �Լ� ���
#include <conio.h>	//gotoxy���� ����� api ���, �ܼ� ����� �Լ��� �����ϴ� ��� ����

#define FIELD_WIDTH 50	//�ʵ尡�α���
#define FIELD_HEIGHT 25	//�ʵ弼�α���
#define LEFT 75			//Ű���� �� ȭ��ǥ�� char��
#define RIGHT 77		//Ű���� ��
#define UP 72			//Ű���� ��
#define DOWN 80			//������ �Ʒ�
#define ITEM_MAX 2		//ȭ�鿡 ǥ�õǴ� �����۰���
#define ITEM_GOLD 101	//��� ������ �ε�������
#define ITEM_EXP 102	//����ġ ������ �ε�������
#define LEFT_MARGIN 30	//ȭ����ʸ���(����)
#define TOP_MARGIN 3	//ȭ�� ��ܸ���(����)
#define DELAYTIME 200	//Sleep�Լ��� �� x/1000 ��