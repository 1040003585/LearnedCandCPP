// AnimDate.cpp: implementation of the AnimDate class.
// Download by http://www.NewXing.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AnimDate.h"
CBmp24 BkBmp,foregroundBmp;
CMultiBmp LeftRabbitBmp,DownRabbitBmp,UpRabbitBmp;
CMultiBmp LeftWaitBmp,DownWaitBmp,UpWaitBmp;
CMultiBmp		LeftExitBmp;		//向左的出口
CMultiBmp		UpExitBmp;			//向上的出口
CMultiBmp		CloudyBmp;			//用来播放云雾效果的图片
CBmp24	MazeWall[5];
void LoadAnimDate()
{

	BkBmp.LoadBmp("./pic/Candy_BG1.bmp");
	foregroundBmp.LoadBmp("./pic/BG.bmp",RGB(0,0,32));

	LeftRabbitBmp.LoadBmp("./pic/LeftWalk.bmp",6,1,RGB(0,0,32));
	DownRabbitBmp.LoadBmp("./pic/DownWalk.bmp",5,1,RGB(0,0,32));
	UpRabbitBmp.LoadBmp("./pic/UpWalk.bmp",5,1,RGB(0,0,32));

	LeftWaitBmp.LoadBmp("./pic/LeftWait.bmp",3,1,RGB(0,0,32));
	DownWaitBmp.LoadBmp("./pic/DownWait.bmp",3,1,RGB(0,0,32));
	UpWaitBmp.LoadBmp("./pic/UpWait.bmp",3,1,RGB(0,0,32));

	MazeWall[0].LoadBmp("./pic/Road.bmp");
	MazeWall[1].LoadBmp("./pic/Wall_00.bmp");
	MazeWall[2].LoadBmp("./pic/Wall_01.bmp");
	MazeWall[3].LoadBmp("./pic/Wall_10.bmp");
	MazeWall[4].LoadBmp("./pic/Wall_11.bmp");

	LeftExitBmp.LoadBmp("./pic/LeftExit.bmp",3,1,RGB(0,0,32));		//向左的出口
	UpExitBmp.LoadBmp("./pic/UpExit.bmp",3,1,RGB(0,0,32));			//向上的出口

	CloudyBmp.LoadBmp("./pic/Cloudy.bmp",4,1,RGB(0,0,32));
}
SAnimFrame		g_LeftExitFrm[]=
				{
					{0,0,16,5},
					{1,8,16,5},
					{2,16,16,5},
					{0xffff,0xffff,0xffff,0xffff}
				};
SAnimFrame		g_UpExitFrm[]=
				{
					{0,16,0,5},
					{1,16,8,5},
					{2,16,16,5},
					{0xffff,0xffff,0xffff,0xffff}
				};
SAnimFrame		g_CloudyFrm[]=
				{
					{0,288,230,1},
					{1,288,230,2},
					{2,288,230,4},
					{3,288,230,5},
					{0xffff,0xffff,0xffff,0xffff}
				};