// ����˹����.cpp : Defines the entry point for the console application.
//





#include "stdafx.h"
#include "all_include.h"
extern int fx[4][4];
extern int all_xy[35][60];
extern int lx1[4][4],lx2[4][4],lx3[4][4],lx4[4][4];
extern int sx1[4][4],sx2[4][4],zx1[4][4],zx2[4][4];
extern int tx1[4][4],tx2[4][4],tx3[4][4],tx4[4][4];
extern int jx1[4][4],jx2[4][4],jx3[4][4],jx4[4][4];
extern int ix1[4][4],ix2[4][4];
int (*now)[4],(*next)[4],rand_data=0,olde_rand=0;
int ll=0,ss=0,zz=0,tt=0,ii=0,jj=0,fenshu=0;
POINT begin_xy,print_xy;
int main()
{
	int key,i,j,sleep_time=150,end_hand=0,in_time=0;
	BOOL push=FALSE;
	HWND hwnd = FindWindow("ConsoleWindowClass", NULL);
	
	while(1)
	{
		begin_xy.x=7,begin_xy.y=1,fenshu=0,sleep_time=150;
		srand(time(NULL));next=&fx[0];
		chushihua();
		memset(all_xy,0,sizeof(all_xy));
		my_switch();
		show_next(next);
		for(i=0;i<24;i++)//��ʼ����ά����
		{
			all_xy[i][0]=1;all_xy[22][i*2]=1;all_xy[i][32]=1;
		}
		while(1)
		{
			while(kbhit())			//���������
				{
					key=get_key();		//�õ�����İ�����
					switch(key)			//ƥ�䰴����
					{
						case KEY_PUSH:push=!push;break;
						case KEY_DOWN:
							if(begin_xy.y>=20)break;
							begin_xy.y++;if(!found_error(begin_xy,now))begin_xy.y--;break;
						case KEY_UP:  change_tx();break;
						case KEY_LEFT :begin_xy.x--;if(!found_error(begin_xy,now))begin_xy.x++;break;
						case KEY_RIGHT:begin_xy.x++;if(!found_error(begin_xy,now))begin_xy.x--;break;
						case KEY_ESC:  if(6==MessageBox(hwnd,"�Ƿ��˳���","ѯ��",MB_YESNO|MB_ICONQUESTION))return 0;break;
						case KEY_ADD:/*if(sleep_time>=10)*/sleep_time=150  ;break;
						case KEY_NADD:/*if(sleep_time<1000)*/sleep_time=10;break;
						//default:printf("%d",key);getch();
					}
				}
			if(!push)
			{
				print_xy=begin_xy;
				for(i=0;i<4;i++,print_xy.x++)
					for(j=0,print_xy.y=begin_xy.y;j<4;j++,print_xy.y++)
						if(now[i][j]==1)
						{
							gotoxy(print_xy.x*2,print_xy.y);printf("��");
						}
				Sleep(sleep_time);
				if(!found_error(begin_xy,now))
				{
					if(end_hand==0)
					{
						PlaySound((LPCTSTR)"resource\\aced.wav", NULL, SND_FILENAME | SND_ASYNC);
						if(6==MessageBox(hwnd,"Game over���Ƿ����¿�ʼ��","��Ϸʧ��",MB_YESNO|MB_ICONQUESTION))
							break;
						else
							return 0;
					}
					begin_xy.y-=1;
					set_data(begin_xy,now);
					found_end();
					begin_xy.x=7,begin_xy.y=1,end_hand=0;
					ll=0,ss=0,zz=0,tt=0,ii=0,jj=0;
					end_next(next);
					my_switch();
					show_next(next);
					continue;
				}
				print_xy=begin_xy;end_hand++;
				for(i=0;i<4;i++,print_xy.x++)
					for(j=0,print_xy.y=begin_xy.y;j<4;j++,print_xy.y++)
						if(now[i][j]==1)
						{
							gotoxy(print_xy.x*2,print_xy.y);printf(" ");
						}
				if(in_time++==2)
				{
					begin_xy.y++;in_time=0;
				}
			}
			else
				Sleep(sleep_time);
		}
	}
	return 0;
}

int get_key()
{ 
  int c1,c2;
  if((c1=getch())!=224)return c1;
  c2=getch();
  return c2; 
} 
void my_switch()
{
	now=next;olde_rand=rand_data;
	rand_data=rand()%7; //����������֣����飩
	switch(rand_data)
	{
		case 0:next=&fx[0];break;
		case 1:next=&lx1[0];break;
		case 2:next=&sx1[0];break;
		case 3:next=&zx1[0];break;
		case 4:next=&tx1[0];break;
		case 5:next=&ix1[0];break;
		case 6:next=&jx1[0];break;
	}
}
void change_tx()
{
	int (*olde)[4]=now;
	switch(olde_rand)
	{
		case 0:break;
		case 1:
			if(++ll==4)ll=0;
			switch(ll)
			{
				case 0:now=&lx1[0];break;
				case 1:now=&lx2[0];break;
				case 2:now=&lx3[0];break;
				case 3:now=&lx4[0];break;
			}break;
		case 2:
			if(++ss==2)ss=0;
			switch(ss)
			{
				case 0:now=&sx1[0];break;
				case 1:now=&sx2[0];break;
			}break;
		case 3:
			if(++zz==2)zz=0;
			switch(zz)
			{
				case 0:now=&zx1[0];break;
				case 1:now=&zx2[0];break;
			}break;
		case 4:
			if(++tt==4)tt=0;
			switch(tt)
			{
				case 0:now=&tx1[0];break;
				case 1:now=&tx2[0];break;
				case 2:now=&tx3[0];break;
				case 3:now=&tx4[0];break;
			}break;
		case 5:
			if(++ii==2)ii=0;
			switch(ii)
			{
				case 0:now=&ix1[0];break;
				case 1:now=&ix2[0];break;
			}break;
		case 6:
			if(++jj==4)jj=0;
			switch(jj)
			{
				case 0:now=&jx1[0];break;
				case 1:now=&jx2[0];break;
				case 2:now=&jx3[0];break;
				case 3:now=&jx4[0];break;
			}break;
	}
	if(!found_error(begin_xy,now))now=olde;
}
int fx[4][4]={ 0,0,0,0,
			   0,1,1,0,
			   0,1,1,0,
			   0,0,0,0};
//�����Ƿ���
int lx1[4][4]={0,1,0,0,
			   0,1,0,0,
			   0,1,1,0,
			   0,0,0,0};

int lx2[4][4]={0,0,0,0,
			   0,1,1,1,
			   0,1,0,0,
			   0,0,0,0};

int lx3[4][4]={0,0,0,0,
			   0,1,1,0,
			   0,0,1,0,
			   0,0,1,0};

int lx4[4][4]={0,0,0,0,
			   0,0,1,0,
			   1,1,1,0,
			   0,0,0,0};
//������L��
int jx1[4][4]={0,0,0,0,
			   0,1,0,0,
			   0,1,1,1,
			   0,0,0,0};

int jx2[4][4]={0,0,0,0,
			   0,1,1,0,
			   0,1,0,0,
			   0,1,0,0};

int jx3[4][4]={0,0,0,0,
			   1,1,1,0,
			   0,0,1,0,
			   0,0,0,0};

int jx4[4][4]={0,0,1,0,
			   0,0,1,0,
			   0,1,1,0,
			   0,0,0,0};
//������J��
int sx1[4][4]={0,0,0,0,
			   0,0,1,1,
			   0,1,1,0,
			   0,0,0,0};

int sx2[4][4]={0,1,0,0,
			   0,1,1,0,
			   0,0,1,0,
			   0,0,0,0};
//������S��
int zx1[4][4]={0,0,0,0,
			   1,1,0,0,
			   0,1,1,0,
			   0,0,0,0};

int zx2[4][4]={0,0,1,0,
			   0,1,1,0,
			   0,1,0,0,
			   0,0,0,0};
//������Z��
int tx1[4][4]={1,1,1,0,
			   0,1,0,0,
			   0,0,0,0,
			   0,0,0,0};

int tx2[4][4]={0,0,1,0,
			   0,1,1,0,
			   0,0,1,0,
			   0,0,0,0};

int tx3[4][4]={0,0,0,0,
			   0,0,1,0,
			   0,1,1,1,
			   0,0,0,0};

int tx4[4][4]={0,1,0,0,
			   0,1,1,0,
			   0,1,0,0,
			   0,0,0,0};
//������T��
int ix1[4][4]={0,1,0,0,
			   0,1,0,0,
			   0,1,0,0,
			   0,1,0,0};

int ix2[4][4]={0,0,0,0,
			   1,1,1,1,
			   0,0,0,0,
			   0,0,0,0};
//������I��
int all_xy[35][60];
extern int fenshu;
void found_end()
{
	int i=21,j,k,how=0;
	BOOL yes=TRUE,end=TRUE;
	for(i=21;i>0;i--)
	{
		for(j=1,yes=TRUE;j<16;j++)
			if(all_xy[i][j*2]!=1)
			{
				yes=FALSE;break;
			}
		if(yes)
		{
			how++;fenshu++;
			for(k=i;k>1;k--)
			{
				for(j=1,end=TRUE;j<16;j++)
				{	
					all_xy[k][j*2]=all_xy[k-1][j*2];
					if(all_xy[k-1][j*2]==1)end=FALSE;
				}
				if(end)break;//���һ����һ�����鶼û��ֹͣ��ֵ
			}
			i=22;
		}
	}
	if(how!=0)
	{
		for(k=21;k>1;k--)
			for(j=1;j<16;j++)
				if(all_xy[k][j*2]==1)
				{
					gotoxy(j*2,k+1);printf("��");
				}
				else
				{
					gotoxy(j*2,k+1);printf(" ");
				}
		switch(how)
		{
			case 0:break;
			case 1:PlaySound((LPCTSTR)"resource\\shutdown.wav", NULL, SND_FILENAME | SND_ASYNC);break;
			case 2:PlaySound((LPCTSTR)"resource\\doublekill.wav", NULL, SND_FILENAME | SND_ASYNC);break;
			case 3:PlaySound((LPCTSTR)"resource\\triplekill.wav", NULL, SND_FILENAME | SND_ASYNC);break;
			default:PlaySound((LPCTSTR)"resource\\godlike.wav", NULL, SND_FILENAME | SND_ASYNC);break;
		}
		if(how>1)
			fenshu+=how;
		gotoxy(40,9);
		printf("%d��",fenshu);
		if(fenshu%5==1)
			system("color 1a");
		if(fenshu%5==2)
			system("color 1b");
		if(fenshu%5==3)
			system("color 1c");
		if(fenshu%5==4)
			system("color 1d");
		if(fenshu%5==0)
			system("color 1e");
	}
}
void set_data(POINT begin_xy,int (*now)[4])
{
	int i,j;
	POINT print_xy=begin_xy;
	for(i=0;i<4;i++,print_xy.x++)
		for(j=0,print_xy.y=begin_xy.y;j<4;j++,print_xy.y++)
			if(now[i][j]==1)
				all_xy[print_xy.y][print_xy.x*2]=1;
}
BOOL found_error(POINT begin_xy,int (*now)[4])
{
	int i,j;
	POINT print_xy=begin_xy;
	for(i=0;i<4;i++,print_xy.x++)
		for(j=0,print_xy.y=begin_xy.y;j<4;j++,print_xy.y++)
			if(now[i][j]==1)
				if(all_xy[print_xy.y][print_xy.x*2]==1)
					return FALSE;
	return TRUE;
}


COORD coord;
void HideCursor()//���ؿ���̨�Ĺ�� 
{
	 CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y)
{
	 coord.X = x,coord.Y=y;
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void chushihua()
{
	int i,j,x=36,y=1,sleep_time=10;
	//system("color 1a");
	system("mode con cols=52 lines=25");//�ı�dos���ڴ�С��ȥ��������
	for(i=0;i<16;i++)
	{
		gotoxy(i*2,0);printf("��");
		gotoxy(0,i);printf("��");
		Sleep(sleep_time);
	}
	for(;i<23;i++)
	{
		gotoxy(0,i);printf("��");
		Sleep(sleep_time);
	}
	for(i=0;i<=16;i++)
	{
		gotoxy(i*2,23);printf("��");
		gotoxy(32,i);printf("��");
		Sleep(sleep_time);
	}
	for(;i<=23;i++)
	{
		gotoxy(32,i);printf("��");
		Sleep(sleep_time);
	}
	for(j=0;j<23;j+=6)
		for(i=16;i<26;i++)
		{
			gotoxy(i*2,j);printf("��");
			Sleep(sleep_time);
		}
	for(i=16;i<26;i++)
	{
		gotoxy(i*2,23);printf("��");
		Sleep(sleep_time);
	}
	for(i=23;i>=0;i--)
	{
		gotoxy(50,i);printf("��");
		Sleep(sleep_time);
	}
	gotoxy(x,y++);
	printf("��ʹ�ù���");
	gotoxy(x-2,y++);Sleep(sleep_time);
	printf("��:���� +:�ٶȼ�");
	gotoxy(x-2,y++);Sleep(sleep_time);
	printf("��:���� -:�ٶȼ�");
	gotoxy(x-2,y++);Sleep(sleep_time);
	printf("��:���� ESC:�˳�");
	gotoxy(x,y++);Sleep(sleep_time);
	printf("  �ո�:��ͣ");
	Sleep(sleep_time);y++;
	gotoxy(x,y++);
	printf("����ǰ������");
	gotoxy(x,++y);Sleep(sleep_time);
	printf("     0��");
	Sleep(sleep_time);y+=4;
	gotoxy(x,y++);
	printf("���¸�ͼ�Ρ�");
	Sleep(sleep_time);y+=5;
	gotoxy(x+2,y++);
	printf("�����ߡ�");
	gotoxy(x,++y);
	printf("     804");
	gotoxy(10,10);
	printf("���������ʼ��");
	getch();HideCursor();
	gotoxy(10,10);
	printf("              ");
}
void show_next(int (*now)[4])
{
	int i,j;
	POINT print_xy={20,14};
	for(i=0;i<4;i++,print_xy.x++)
		for(j=0,print_xy.y=14;j<4;j++,print_xy.y++)
			if(now[i][j]==1)
			{
				gotoxy(print_xy.x*2,print_xy.y);printf("��");
			}
}
void end_next(int (*now)[4])
{
	int i,j;
	POINT print_xy={20,14};
	for(i=0;i<4;i++,print_xy.x++)
		for(j=0,print_xy.y=14;j<4;j++,print_xy.y++)
			if(now[i][j]==1)
			{
				gotoxy(print_xy.x*2,print_xy.y);printf("  ");
			}
}
