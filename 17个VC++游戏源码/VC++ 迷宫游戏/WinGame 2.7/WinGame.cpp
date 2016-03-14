//Download by http://www.NewXing.com
// WinGame.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
#include "WinGame.h"
#include "./include/MemDC.h"
#include "resource.h"
#include "./Include/Bmp24.h"
#include<windows.h>
#include"./include/Key.h"
#include "WorkThread.h"
#include "./Include/Thread.h"
//=====================================================
HWND	g_hWnd;
CMemDC	g_MemDC;
CThread g_WorkThread;
//=================================================

int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine,int nCmdShow)
{
	MSG msg;
    MyRegisterClass(hInstance);
	InitInstance(hInstance,nCmdShow);
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
	}
	return(int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message) 
	{	
		case WM_COMMAND:
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
		case WM_CREATE:
				OnCreate(hWnd);

				
			break;
		case WM_ERASEBKGND:
		break;

		case WM_PAINT:
			OnPaint(hWnd);
			break;
		case WM_KEYDOWN:
			OnKeyDown(wParam);
			break;
		case WM_KEYUP:
			OnKeyUp(wParam);
			break;
		case WM_DESTROY:	
			OnDesdroy();
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
void OnCreate(HWND hWnd)
{
	g_MemDC.Init(hWnd);
	g_WorkThread.Create(WorkFun,NULL);
}
void OnPaint(HWND hWnd)
{

	PAINTSTRUCT ps;
	HDC hdc,hMemDC;

	::InvalidateRect(hWnd, NULL,0);
	hdc = BeginPaint(hWnd, &ps);

	g_MemDC.Wait();
	hMemDC=g_MemDC.GetDC();
	BitBlt(hdc,0,0,640,480,hMemDC,0,0,SRCCOPY);
	g_MemDC.Release();

	EndPaint(hWnd,&ps);
}
void OnDesdroy()
{
	g_WorkThread.Destroy();
	g_MemDC.Destroy();
}
BOOL MyRegisterClass(HINSTANCE hInstance)
{
	CHAR szWindowClass[]="Maze";
	WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX); 
    wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;//在这里设置了那个消息处理回调函数
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_WINGAME);;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW); ;
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);;
	return RegisterClassEx(&wcex);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{   
	CHAR szTitle[]="迷宫";
	CHAR szWindowClass[]="Maze";
	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_MINIMIZEBOX|WS_SYSMENU|WS_VISIBLE,CW_USEDEFAULT, 0, 640, 512, NULL, NULL, hInstance, NULL);
	if (!hWnd)      return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	g_hWnd=hWnd;
   return TRUE;
}

