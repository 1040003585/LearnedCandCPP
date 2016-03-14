//Download by http://www.NewXing.com
#ifndef _CREATEMAP_H_
#define	_CREATEMAP_H_
#pragma once
//===============================================================================
#include   <windows.h>
//===============================================================================
void CreateMap(int w,int h,POINT* pExit);		//创建大小为w*h的迷宫地图，pExit返回出口
//==================================================================================
extern int	g_MazeWidth;						//迷宫地图宽度
extern int	g_MazeHeight;						//迷宫地图高度
#define		MAX_MAZE_WIDTH		100				//迷宫的最大宽度
#define		MAX_MAZE_HEIGHT		100				//迷宫的最大高度
extern int	g_MazeMap[][MAX_MAZE_HEIGHT+1];		//描述迷宫地图数组
//===================================================================================
#endif

