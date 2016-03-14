//Download by http://www.NewXing.com
#ifndef _ANIMDATE_H__
#define _ANIMDATE_H__
#pragma once
//==================================================================================
#include"./include/Bmp24.h"
#include"./include/AnimCtrlEx.h"
//===============================================================================
void LoadAnimDate();//加载所有的图片
//==============================================================================
extern CBmp24			BkBmp;				//背景图片
extern CBmp24			foregroundBmp;		//前景图片
extern CMultiBmp		LeftRabbitBmp;		//向左走的兔子
extern CMultiBmp		DownRabbitBmp;		//向下走的兔子
extern CMultiBmp		UpRabbitBmp;		//向上走的兔子
extern CMultiBmp		LeftWaitBmp;		//向左等待的兔子
extern CMultiBmp		DownWaitBmp;		//向下等待的兔子
extern CMultiBmp		UpWaitBmp;			//向上等待的兔子
extern CMultiBmp		LeftExitBmp;		//向左的出口
extern CMultiBmp		UpExitBmp;			//向上的出口
extern CMultiBmp		CloudyBmp;			//用来播放云雾效果的图片
extern CBmp24			MazeWall[5];		//用来拼凑迷宫的5张图片
//=================================================================================
extern SAnimFrame		g_LeftExitFrm[];	//向左的迷宫出口动画帧
extern SAnimFrame		g_UpExitFrm[];		//向上的迷宫出口动画帧
extern SAnimFrame		g_CloudyFrm[];		//云雾效果动画帧
//==================================================================================
#endif