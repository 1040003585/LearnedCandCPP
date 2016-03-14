// ����˹����.cpp : Defines the entry point for the application.
// Download by http://www.NewXing.com

#include "stdafx.h"
#include <windows.h>
#include <stdlib.h>
#include "mmsystem.h"
#include "resource.h"
#include <mmsystem.h>   
 #pragma comment(lib, "winmm.lib")  

const POINT apt[7][4][4]={{{120,0,140,0,140,20,160,0},{120,20,140,20,140,0,160,20},{120,20,140,0,140,40,140,20},{140,20,140,0,160,20,140,40}},
{{120,0,120,20,140,20,160,20},{120,0,120,20,120,40,140,0},{120,0,140,0,160,0,160,20},{120,40,140,0,140,20,140,40}},
{{140,0,140,20,160,0,160,20},{140,0,140,20,160,0,160,20},{140,0,140,20,160,0,160,20},{140,0,140,20,160,0,160,20}},
{{140,0,140,20,140,40,140,60},{120,40,140,40,160,40,180,40},{140,0,140,20,140,40,140,60},{120,40,140,40,160,40,180,40}},
{{120,20,140,20,160,20,160,0},{120,0,120,20,120,40,140,40},{120,0,120,20,140,0,160,0},{120,0,140,0,140,20,140,40}},
{{120,0,140,0,140,20,160,20},{120,20,120,40,140,0,140,20},{120,0,140,0,140,20,160,20},{120,20,120,40,140,0,140,20}},
{{120,20,140,20,140,0,160,0},{120,0,120,20,140,20,140,40},{120,20,140,20,140,0,160,0},{120,0,120,20,140,20,140,40}}};

int sx,sy; //ͼ�κ����ı���
//int px,py;
int cfk[300][480];  //�淽������
HBRUSH color[3];
int m,n;
static int f; //����
static int dj; //�ȼ�
struct frect
{
 int x;
 int y;
 int dir;
 int sharp;
}Pos;
static TCHAR str[256];


void fangkuai(HDC hdc,int x,int y,int col);
void huabk(HDC hdc,int x,int y,int x1,int y1);
BOOL gameover(void);
void tuxing(HDC hdc,int dir,int sharp,int x,int y,int col);
void Init(void);
BOOL save(HDC hdc,int dir,int sharp,int x,int y);
void load(HDC hdc);
void hua(HDC hdc);
BOOL check(int dir,int sharp,int x,int y);
void CALLBACK timerProc(HWND hwnd,UINT message,UINT timerid,DWORD timer);
void ScrollLeft(TCHAR *str);
LRESULT CALLBACK wndproc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     szCmdLine,
                     int       iCmdShow)
{
 	// TODO: Place code here.
	HWND hwnd;
	MSG msg;
	static TCHAR szappname[]=TEXT("����˹����");
	WNDCLASS wndclass;
	wndclass.style=CS_HREDRAW|CS_VREDRAW;
	wndclass.lpfnWndProc=wndproc;
	wndclass.cbClsExtra=0;
	wndclass.cbWndExtra=0;
	wndclass.hInstance=hInstance;
	wndclass.hIcon=LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1));
	wndclass.hCursor=LoadCursor(hInstance,MAKEINTRESOURCE(IDC_CURSOR1));
	wndclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName=NULL;
	wndclass.lpszClassName=szappname;
	RegisterClass(&wndclass);
	HMENU hMenu=LoadMenu(hInstance,MAKEINTRESOURCE(IDR_MENU1));
	hwnd=CreateWindow(szappname,TEXT("����˹����"),WS_MINIMIZEBOX|WS_SYSMENU,480,100,406,532,
		 NULL,hMenu,hInstance,NULL);
	ShowWindow(hwnd,iCmdShow);
	UpdateWindow(hwnd);
    while(GetMessage(&msg,NULL,NULL,NULL))
	{
	  TranslateMessage(&msg);
	  DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK wndproc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
  static HWND hwndbutton,hwndbutton1,hwndbutton2,hwndbutton3,hwndedit,hwndedit1,hwndedit2,hwndedit3;
  HDC hdc;
  PAINTSTRUCT ps;
  static HINSTANCE hInstance;
  static int speed=600;
  static int pause=1;
  int line;
  switch(message)
  {
  case WM_CREATE:
	  {
	   //PlaySound(TEXT("1/��������.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
	   color[0]=CreateSolidBrush(RGB(0,0,0));  //��ˢ
	   color[1]=CreateSolidBrush(RGB(0,255,0)); //��ˢ
	   color[2]=CreateSolidBrush(RGB(255,0,0));  //��ˢ
	   hwndbutton=CreateWindow(TEXT("BUTTON"),TEXT("��ͣ"),WS_CHILD|WS_VISIBLE,320,140,80,40,hwnd,(HMENU)1,hInstance,NULL);
	   hwndbutton1=CreateWindow(TEXT("BUTTON"),TEXT("�˳�"),WS_CHILD|WS_VISIBLE,320,200,80,40,hwnd,(HMENU)2,hInstance,NULL);
	   hwndbutton2=CreateWindow(TEXT("BUTTON"),TEXT("����Ϸ"),WS_CHILD|WS_VISIBLE,320,260,80,40,hwnd,(HMENU)3,hInstance,NULL);
	   hwndbutton3=CreateWindow(TEXT("BUTTON"),TEXT("ȷ��"),WS_CHILD|WS_VISIBLE,320,450,80,30,hwnd,(HMENU)4,hInstance,NULL);
	   hwndedit=CreateWindow(TEXT("EDIT"),TEXT("����:0"),WS_CHILD|WS_VISIBLE|ES_READONLY,320,320,80,20,hwnd,(HMENU)5,hInstance,NULL);
	   hwndedit1=CreateWindow(TEXT("EDIT"),TEXT("�ȼ�:1"),WS_CHILD|WS_VISIBLE|ES_READONLY,320,350,80,20,hwnd,(HMENU)6,hInstance,NULL);
	   hwndedit2=CreateWindow(TEXT("EDIT"),TEXT(""),WS_CHILD|WS_VISIBLE,320,380,80,20,hwnd,(HMENU)7,hInstance,NULL);
       hwndedit3=CreateWindow(TEXT("EDIT"),TEXT(""),WS_CHILD|WS_VISIBLE|ES_READONLY,320,410,80,20,hwnd,(HMENU)8,hInstance,NULL);
	   SetTimer(hwnd,1,speed,NULL);
	   SetTimer(hwnd,2,400,timerProc);
       return 0;
	  }
  case WM_PAINT:
	  {
		hdc=BeginPaint(hwnd,&ps); 
	    hua(hdc);
		load(hdc);
		huabk(hdc,300,0,0,460);
		huabk(hdc,0,0,0,460);
		Init();
		tuxing(hdc,Pos.dir,Pos.sharp,220,20,1);
		tuxing(hdc,Pos.dir,Pos.sharp,0,0,1);
		EndPaint(hwnd,&ps);
	    return 0;
	  }
  case WM_TIMER:
	  { 
		hdc=GetDC(hwnd);
		if(check(Pos.dir,Pos.sharp,Pos.x,Pos.y+20))
		{
		tuxing(hdc,Pos.dir,Pos.sharp,Pos.x,Pos.y,0);
		Pos.y=Pos.y+20;
        tuxing(hdc,Pos.dir,Pos.sharp,Pos.x,Pos.y,1);
		}
	    else
		{
		  if(gameover())
		  {
		  PlaySound(TEXT("1/luodi.wav"),NULL,SND_FILENAME|SND_ASYNC);
		  line=save(hdc,Pos.dir,Pos.sharp,Pos.x,Pos.y);
		  if(line==1)
		  {
		  TCHAR fs[256];
		  f+=10;
		  wsprintf(fs,"����:%d",f);
		  SetDlgItemText(hwnd,5,fs);
		  if(f==100)
		  {
		   TCHAR dj1[256];
           dj++;
		   wsprintf(dj1,"�ȼ�:%d",dj);
		   SetDlgItemText(hwnd,6,dj1);
		  }
		  if(f==200)
		  {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		  }
		  if(f==400)
		  {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		  }
		  if(f==800)
		  {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		  }
		   if(f==1000)
		   {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		   }
		   if(f==2000)
		   {
			KillTimer(hwnd,1);
			MessageBox(NULL,TEXT(""),TEXT(""),MB_OK);
			ZeroMemory(cfk,sizeof(cfk));
			InvalidateRect(hwnd,NULL,FALSE);
		   }
		  }
		  else if(line>=2&&line<4)
		  {
          TCHAR fs[256];
		  f+=20;
		  wsprintf(fs,"����:%d",f);
		  SetDlgItemText(hwnd,5,fs);
		  if(f==100)
		  {
		   TCHAR dj1[256];
           dj++;
		   wsprintf(dj1,"�ȼ�:%d",dj);
		   SetDlgItemText(hwnd,6,dj1);
		  }
		  if(f==200)
		  {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		  }
		  if(f==400)
		  {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		  }
		  if(f==800)
		  {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		  }
		   if(f==1000)
		   {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		   }
		   if(f==2000)
		   {
			KillTimer(hwnd,1);
			MessageBox(NULL,TEXT(""),TEXT(""),MB_OK);
			ZeroMemory(cfk,sizeof(cfk));
			InvalidateRect(hwnd,NULL,FALSE);
		   }
		  }
		  else if(line>=4&&line<8)
		  {
		  TCHAR fs[256];
		  f+=40;
		  wsprintf(fs,"����:%d",f);
		  SetDlgItemText(hwnd,5,fs);
		  if(f==100)
		  {
		   TCHAR dj1[256];
           dj++;
		   wsprintf(dj1,"�ȼ�:%d",dj);
		   SetDlgItemText(hwnd,6,dj1);
		  }
		  if(f==200)
		  {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		  }
		  if(f==400)
		  {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		  }
		  if(f==800)
		  {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		  }
		   if(f==1000)
		   {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		   }
		   if(f==2000)
		   {
			KillTimer(hwnd,1);
			MessageBox(NULL,TEXT(""),TEXT(""),MB_OK);
			ZeroMemory(cfk,sizeof(cfk));
			InvalidateRect(hwnd,NULL,FALSE);
		   }
		  }
		  else if(line>=8)
		  {
		  TCHAR fs[256];
		  f+=160;
		  wsprintf(fs,"����:%d",f);
		  SetDlgItemText(hwnd,5,fs);
		  if(f==100)
		  {
		   TCHAR dj1[256];
           dj++;
		   wsprintf(dj1,"�ȼ�:%d",dj);
		   SetDlgItemText(hwnd,6,dj1);
		  }
		  if(f==200)
		  {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		  }
		  if(f==400)
		  {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		  }
		  if(f==800)
		  {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		  }
		   if(f==1000)
		   {
		  TCHAR dj1[256];
          dj++;
		  wsprintf(dj1,"�ȼ�:%d",dj);
		  SetDlgItemText(hwnd,6,dj1);
		   }
		   if(f==2000)
		   {
			KillTimer(hwnd,1);
			MessageBox(NULL,TEXT(""),TEXT(""),MB_OK);
			ZeroMemory(cfk,sizeof(cfk));
			InvalidateRect(hwnd,NULL,FALSE);
		   }
		  }
          Init();
		  speed=600;
		  SetTimer(hwnd,1,speed,NULL);
		  InvalidateRect(hwnd,0,FALSE);
		  }
		  else
		{
		 KillTimer(hwnd,1);
		 PlaySound(TEXT("1/����.wav"),NULL,SND_FILENAME|SND_ASYNC);
		 int i=MessageBox(NULL,TEXT(".......@_@�Ƿ�����@_@......"),TEXT("��ʾ"),MB_OKCANCEL);
		 if(i==IDOK)
		 {
		  ZeroMemory(cfk,sizeof(cfk));
		  InvalidateRect(hwnd,0,FALSE);
		  SetTimer(hwnd,1,speed,NULL); 
		 }
		}
		}
		ReleaseDC(hwnd,hdc);
	    return 0;
	  }
  case WM_KEYDOWN:
	  {
		hdc=GetDC(hwnd);
		switch(wParam)
	   {
	   case VK_UP:
	   case VK_SPACE:
		   { 
			 if(check(Pos.dir,(Pos.sharp+1)%4,Pos.x,Pos.y))   //ͬ����������Ĳ���ֵ��ͬ����ÿ���������ص�ֵҲ��ͬ��
			 {
			 PlaySound(TEXT("1/xuanzhuan.wav"),NULL,SND_FILENAME|SND_ASYNC);
			 tuxing(hdc,Pos.dir,Pos.sharp,Pos.x,Pos.y,0);
			 ++Pos.sharp%=4;  //ʹ������tuxing��������һ������ɫ�뱳����ɫһ������һ�����Ǳ�����ɫ
			 tuxing(hdc,Pos.dir,Pos.sharp,Pos.x,Pos.y,1);
			 }
		     return 0;
		   }
	   case VK_LEFT:
		   {
			if(check(Pos.dir,Pos.sharp,Pos.x-20,Pos.y))
			{
			PlaySound(TEXT("1/xuanzhuan.wav"),NULL,SND_FILENAME|SND_ASYNC);
			tuxing(hdc,Pos.dir,Pos.sharp,Pos.x,Pos.y,0);
			Pos.x-=20;
			tuxing(hdc,Pos.dir,Pos.sharp,Pos.x,Pos.y,1);
			}
			return 0;
		   }
	   case VK_RIGHT:
		   {
			if(check(Pos.dir,Pos.sharp,Pos.x+20,Pos.y))
			{
			PlaySound(TEXT("1/xuanzhuan.wav"),NULL,SND_FILENAME|SND_ASYNC);
		    tuxing(hdc,Pos.dir,Pos.sharp,Pos.x,Pos.y,0);
			Pos.x+=20;
			tuxing(hdc,Pos.dir,Pos.sharp,Pos.x,Pos.y,1);
			}
			return 0;
		   }
	   case VK_DOWN:
		   {
			PlaySound(TEXT("1/xuanzhuan.wav"),NULL,SND_FILENAME|SND_ASYNC);
		    speed=100;
			SetTimer(hwnd,1,speed,NULL);
		   }
	   }
	   ReleaseDC(hwnd,hdc);
	   return 0;
	  }
  case WM_COMMAND:
	  {
	   switch(LOWORD(wParam))
	   {
	   case 1:
		   {
			 if(gameover())
			 {
			 if(pause)
			 {
			  PlaySound(TEXT("1/Pause.wav"),NULL,SND_FILENAME|SND_ASYNC);
			  KillTimer(hwnd,1);
			  SetWindowText(hwndbutton,TEXT("����"));
			 }
             else
			 {
			  PlaySound(TEXT("1/Pause.wav"),NULL,SND_FILENAME|SND_ASYNC);
			  SetTimer(hwnd,1,speed,NULL);
			  SetWindowText(hwndbutton,TEXT("��ͣ"));
			  SetFocus(hwnd); //�����뽹�㻻�ص�������
			 }
			 ++pause%=2;
			 }
			 return 0;
		   }
	   case 2:
		   {
			PlaySound(TEXT("1/Pause.wav"),NULL,SND_FILENAME|SND_ASYNC);
			KillTimer(hwnd,1);
			int i=MessageBox(hwnd,TEXT("ȷ��Ҫ�˳���?"),TEXT("��ʾ"),MB_OKCANCEL);
			if(i==IDOK)
			{
            KillTimer(hwnd,1);
	        PostQuitMessage(0);
			}
			else
			{
			 PlaySound(TEXT("1/Pause.wav"),NULL,SND_FILENAME|SND_ASYNC);
			 SetTimer(hwnd,1,speed,NULL);
			}
		    return 0;
		   }
	   case 3:
		   {
			PlaySound(TEXT("1/Pause.wav"),NULL,SND_FILENAME|SND_ASYNC);
			KillTimer(hwnd,1);
			int i=MessageBox(hwnd,TEXT("ȷ��Ҫ���¿�ʼ��?"),TEXT("��ʾ"),MB_OKCANCEL);
			if(i==IDOK)
			{
			ZeroMemory(cfk,sizeof(cfk));
			InvalidateRect(hwnd,NULL,FALSE);
			SetTimer(hwnd,1,speed,NULL); 
			}
			else
			{
			 PlaySound(TEXT("1/Pause.wav"),NULL,SND_FILENAME|SND_ASYNC);
			 SetTimer(hwnd,1,speed,NULL);
			}
			return 0;
		   }
	   case 4:
		   {
           ZeroMemory(str,sizeof(str));
           GetDlgItemText(hwnd,7,str,sizeof(str)/sizeof(TCHAR));
           SetFocus(hwnd);
		   return 0;
		   }
	   case ID_MENUITEM40001:
		   {
			PlaySound(TEXT("1/Pause.wav"),NULL,SND_FILENAME|SND_ASYNC);
            KillTimer(hwnd,1);
			MessageBox(hwnd,TEXT("1.��Ϸ��,��������Ҳ��ȫ.\n"
				                 "2.����Ϸ���ܺ��������е㲻\n"
								 "  ֮ͬ��,�����Ķ����Է�������\n"
								 "3.��!���ҵĲ�֮ͬ������ʱ��\n"
								 "  �����!����ʱ������ȡ��ͬ��\n"
								 "  ����!ʱ��Խ���ٶ�ҲԽ��!@_@\n"),TEXT("˵��"),MB_OK);
			SetTimer(hwnd,1,speed,NULL);
		    return 0;
		   }
	   case ID_MENUITEM40002:
		   {
			PlaySound(TEXT("1/Pause.wav"),NULL,SND_FILENAME|SND_ASYNC);
		    KillTimer(hwnd,1);
			MessageBox(hwnd,TEXT("ͨ������Ϸ�ı��,����֪�����֪ʶ.\n"
				                  "�ر���POINT�ṹ��,�Լ������ʹ��...\n"  
								  "ҲҪ��л�������ҵ���,�ر����ҵ�����\n"
								  "����.�ǳ���л��!!!�һ����Ŭ����!!!"),TEXT("����"),MB_OK);
			SetTimer(hwnd,1,speed,NULL);
			return 0;
		   }
	   }
	   return 0;
	  }
  case WM_DESTROY:
	  {
	   KillTimer(hwnd,1);
	   KillTimer(hwnd,2);
	   PostQuitMessage(0);
	   return 0;
	  }
  }
  return DefWindowProc(hwnd,message,wParam,lParam);
}
void fangkuai(HDC hdc,int x,int y,int col)  //������
{
  int sz=20;
  RECT rect;
  SelectObject(hdc,color[col]);
  FillRect(hdc,&rect,color[col]);
  Rectangle(hdc,x,y,x+sz,y+sz); 
}
void tuxing(HDC hdc,int dir,int sharp,int x,int y,int col) //��ͼ��
{
  int k;
  for(k=0;k<=3;k++)
  {
	sx=apt[dir][sharp][k].x+x;  //��x�������Ʒ�����ƶ���
	sy=apt[dir][sharp][k].y+y;  //ͬ��
    fangkuai(hdc,sx,sy,col);
  }
}

void Init(void)   //��ʼ�ṹ��
{
  Pos.dir=rand()%7;
  Pos.sharp=0;
  Pos.x=0;
  Pos.y=0;
}
BOOL save(HDC hdc,int dir,int sharp,int x,int y)  //���淽���λ��
{
	int i,j;
	bool state;
	int line=0;
	for(i=0;i<=3;i++)
	{
	  sx=apt[dir][sharp][i].x+x;
	  sy=apt[dir][sharp][i].y+y;
	  cfk[sx][sy]=1;
	}
	for(j=0;j<480;j+=20)
	{
		for(i=20;i<300;i+=20)
		{
		  if(cfk[i][j]!=1)
		  {
			 state=false;
             break;
		  }
		}
        if(i==300&&cfk[280][j]==1)
		{
		state=true;
		for(m=0;m<300;m+=20)
		{ 
		fangkuai(hdc,m,j,2);
		PlaySound(TEXT("1/manhang.wav"),NULL,SND_FILENAME|SND_ASYNC);
		Sleep(20);
		}
		line++;
		}
		if(state)
		{
		 for(m=j;m>1;m-=20)
		 {
		  for(n=0;n<300;n+=20)
		  {
		   cfk[n][m]=cfk[n][m-20]; 
		  }
		  //hua(hdc);   //�������ƺ��ػ�  ����
		  //load(hdc);  // ����ȥ������Ϊ��WM_PAINT�����ˣ������õ���INVALIDTAERECT������
		 }
		}
	}   
	return line;
}

void load(HDC hdc)  //��ʾ������ķ���
{
  int i,j;
  for(i=0;i<300;i+=20)
  {
    for(j=0;j<480;j+=20)
	{
	  if(cfk[i][j]==1)
	  {
	  fangkuai(hdc,i,j,1);
	  }
	}
  }
}

BOOL check(int dir,int sharp,int px,int py)  //����Ƿ����   //��װ��������Ҫ�ԣ�
{
 int i,x1,y1;
 for(i=0;i<=3;i++)
 {
   x1=apt[dir][sharp][i].x+px;
   y1=apt[dir][sharp][i].y+py;
   if(x1<=0||x1>=300||y1>=460||cfk[x1][y1]==1)  //�����֮���䣡�ж��Ƿ�����Լ��ж��Ƿ��з���  
   {
    return FALSE;
   }
 }
 return TRUE;
}

void hua(HDC hdc)  //����
{
  RECT rect;
  SetRect(&rect,0,0,300,460);
  FillRect(hdc,&rect,color[0]);
  rect.left=320;
  rect.top=0;
  rect.right=400;
  rect.bottom=480;
  FillRect(hdc,&rect,color[1]);
  rect.left=320;
  rect.top=0;
  rect.right=400;
  rect.bottom=100;
  FillRect(hdc,&rect,color[0]);
}
void huabk(HDC hdc,int x1,int y1,int x2,int y2) //���߿�
{
  int k;
  for(k=0;k<24;k++)
  {
    fangkuai(hdc,x1,y1,2);
	y1+=20;
  }
  for(k=0;k<15;k++)
  {
    fangkuai(hdc,x2,y2,2);
	x2+=20;
  }
}

BOOL gameover(void)
{
  int i,j=40;
  for(i=0;i<=300;i+=20)
  {
   if(cfk[i][j]==1)
   {
    return false;
   }
  }
  return true;
 }

	
void ScrollLeft(TCHAR *str)
{
	//����ߵ��ַ������� 
	TCHAR leftChar = str[0];
	int len = lstrlen(str);
	//�������ң�����ߵ��ַ��滻Ϊ�ұ��Ǹ� 
	for(int i=1;i<len;i++)
	{
		str[i-1] = str[i];
	}
	//�����һ���ַ�����Ϊ��ǰ�ĵ�һ�� 
	str[len-1] = leftChar;
}


VOID  CALLBACK timerProc (HWND hwnd,UINT nMsg,UINT nTimerid,DWORD dwTime)
{   
    //�����ַ� 
	ScrollLeft(str);
	SetDlgItemText(hwnd,8,str);
}
