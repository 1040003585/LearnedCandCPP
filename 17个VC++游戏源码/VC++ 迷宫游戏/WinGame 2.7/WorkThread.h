//Download by http://www.NewXing.com
#ifndef _WORKTHREAD_H_
#define _WORKTHREAD_H_
#pragma once
//====================================================
#include "./Include/Thread.h"
//====================================================================
enum GAME_STATE//游戏状态						
{												
	PRE_GAME_INIT,			//游戏前奏初始化
	CLOUDY_PLAY_INIT,		//云雾效果初始化
	CLOUDY_PLAY,			//播放云雾效果
	PRE_GAME_PLAY,			//游戏前奏						
	MAZE_GAME_INIT,			//迷宫游戏初始化										
	MAZE_GAME_PLAY			//迷宫游戏				
};
//==================================================================
DWORD	WorkFun(void*,CThread*);
//===================================================================
#endif 
