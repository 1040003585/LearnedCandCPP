// WorkThread.cpp: implementation of the CWorkThread class.
// Download by http://www.NewXing.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WorkThread.h"
#include "WinGame.h"
#include "./include/Key.h"
#include "Rabbit.h"
#include "./Include/AnimCtrl.h"
#include "AnimDate.h"
#include "PreRabbit.h"
#include "CreateMap.h"
#include "./Include/Thread.h"
//======================================================================================
CAnimCtrl		BkAnim1,BkAnim2;			//背景图片控制
CAnimCtrl		foregroundAnim;				//前景图片控制
CAnimCtrlEx		LeftExit,RightExit;			//游戏前奏上的左右出口标志		
CAnimCtrlEx		Cloudy;		//播放云雾效果
CPreRabbit		PreRabbit;	//游戏前奏中的兔子
CRabbit			MyRabbit;		//兔子控制
CMazeView		MazeView;		//迷宫视野控制
unsigned int	g_I=0;			//全局计数器
//==================================================================================

DWORD	WorkFun(void*,CThread*p)
{
	CBmp24* pBmp;
	int	m_State=PRE_GAME_INIT;
	LoadAnimDate();
	Sleep(30);
	ClearAllKey();
	while(!p->IsStop())
	{

		ReadKey();
		switch(m_State)
		{
			case PRE_GAME_INIT://游戏前奏初始画
				g_AnimList.ClearAllAnim();
				PreRabbit.New(&DownWaitBmp,288,230);
				PreRabbit.SetHide(1);
				PreRabbit.SetDepth(1);//设置图片的显示的深度
				BkAnim1.New(&BkBmp,0,100);
				BkAnim2.New(&BkBmp,320,100);
				BkAnim2.SetFlip(1);
				LeftExit.New(&LeftExitBmp,-5,240,g_LeftExitFrm,FRAME_REPEAT);
				RightExit.New(&LeftExitBmp,590,240,g_LeftExitFrm,FRAME_REPEAT);
				Cloudy.New(&CloudyBmp,0,0,g_CloudyFrm,FRAME_PLAY_ONCE);
				Cloudy.SetHide(1);
				RightExit.SetFlip(1);

				g_MemDC.FadeOut();
				m_State=CLOUDY_PLAY_INIT;
			break;
			case CLOUDY_PLAY_INIT://雨雾效果初始化
				Cloudy.SetHide(0);
				m_State=CLOUDY_PLAY;
				break;
			case CLOUDY_PLAY://播放云雾效果之后，显示兔子
				if(Cloudy.Play(0))
				{
					Cloudy.Delete();
					PreRabbit.SetHide(0);
					m_State=PRE_GAME_PLAY;
				}

				break;
			case PRE_GAME_PLAY://游戏前奏
				LeftExit.Play(0);
				RightExit.Play(0);
				if(PreRabbit.Play(0))
				{
					m_State=MAZE_GAME_INIT;
					g_MemDC.FadeIn();
				}
			break;
			case MAZE_GAME_INIT://迷宫游戏初始化
				g_AnimList.ClearAllAnim();
				MazeView.New(g_MazeWidth,g_MazeHeight);//视野类里创建了迷宫，和迷宫出口等
				MyRabbit.New(&DownWaitBmp,g_MazeWidth,g_MazeHeight,&MazeView);//自己控制的兔子
				foregroundAnim.New(&foregroundBmp,0,0);//罩在地图上的框图
				g_MemDC.FadeOut();
				m_State=MAZE_GAME_PLAY;
			break;
			case MAZE_GAME_PLAY://控制兔子走迷宫
				MazeView.Play(0);//其实，视野在播放迷宫出口的动画
				if(MyRabbit.Play(0))//控制兔子走迷宫
				{
					m_State=PRE_GAME_INIT;
					g_MemDC.FadeIn();
				}
			break;
		}
		//===========刷新画面====================================================
		pBmp=g_MemDC.GetBmp();
		g_AnimList.ShowAllAnim(pBmp);//将所有的动画图片都先画到g_MemDC的m_ScreenBmp
		g_MemDC.Draw();//画到m_hMemDC
		//=============全局计数器==================================================
		g_I++;
		if(g_I>0xfffe) g_I=0;
	}
	return 0;
}