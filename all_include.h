#include "stdafx.h"
#include <windows.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 
#include <conio.h> 
#include <shellapi.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")
#define KEY_DOWN    80   /* ���¼�ͷ�� */
#define KEY_UP      72   /* ���ϼ�ͷ�� */
#define KEY_RIGHT   77   /* ���Ҽ�ͷ�� */
#define KEY_LEFT    75   /* �����ͷ�� */
#define KEY_ESC     27   /* ESC�� */
#define KEY_PUSH    32   /* �ո�� */
#define KEY_ADD     43   /* ���� */
#define KEY_NADD    45   /* ���� */
void gotoxy(int x, int y);		//gotoxy��� 
void HideCursor();				//���ؿ���̨�Ĺ�꣬�޲������޷���
int get_key();
void chushihua();
void show_next(int (*now)[4]);
void end_next(int (*now)[4]);
void my_switch();
BOOL found_error(POINT begin_xy,int (*now)[4]);
void set_data(POINT begin_xy,int (*now)[4]);
void change_tx();
void found_end();