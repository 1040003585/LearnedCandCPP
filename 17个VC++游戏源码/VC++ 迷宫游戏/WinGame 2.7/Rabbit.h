//Download by http://www.NewXing.com
#ifndef _RABBIT_H_
#define _RABBIT_H_
#pragma once
//==============================================================================
#include "./Include/AnimCtrl.h"
#include "MazeView.h"
//===============================================================================
class CRabbit  :public CAnimCtrl
{
public:
	virtual	void	New(CBmp24*p,int w,int h,CMazeView*pView);
	virtual	int		Play(void*);
	virtual	void	Draw(CBmp24*p);
private:
	int  bHitLeft();			//是否撞到左边
	int  bHitRight();			//是否撞到右边
	int  bHitTop();				//是否撞到上边
	int  bHitBottom();			//是否撞到下边
	int  bSucceed();			//是否已经胜利
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
private:
	int			m_Direct;//兔子的当前方向
	int			m_Wait;	//用于判断兔子需不需要等待的计数器
	int			m_v;	//兔子每次移动多少像素
	CMazeView*	m_pMazeView;//兔子移动的同时，需要控制视野
public:
	CRabbit();
	virtual ~CRabbit();

};
//=================================================================================
#define RABBIT_VX 			19		//老鼠图片往左偏移量
#define RABBIT_VY 			35 		//老鼠图片往上偏移量
#define RABBIT_CX			24		//老鼠图片的水平长度
#define RABBIT_CY			18		//老鼠图片的水平宽度
//========================================================================================
#endif