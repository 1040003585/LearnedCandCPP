//Download by http://www.NewXing.com
#ifndef _WINGAME_H_ 
#define  _WINGAME_H_
#pragma once
//=====================================================================================
#include "resource.h"
#include "./include/MemDC.h"
#include "./Include/Bmp24.h"

//======================================================================================
extern unsigned int g_I;						//全局计数器
extern HWND	g_hWnd;
extern CMemDC			g_MemDC;
//=======================================================================================
BOOL MyRegisterClass(HINSTANCE hInstance);//注册窗口类
BOOL InitInstance(HINSTANCE,int);//创建窗体
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);//窗体消息处理回调函数
void OnPaint(HWND hWnd);//绘制窗体
void OnCreate(HWND hWnd);//窗口刚创建时的，用来初始化的函数
void OnDesdroy();//退出时的，销毁函数，做释放内存等善后处理
#endif