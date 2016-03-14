// PreRabbit.cpp: implementation of the CPreRabbit class.
// Download by http://www.NewXing.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PreRabbit.h"
#include "CreateMap.h"
#include "./include/Key.h"
#include "AnimDate.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
extern unsigned int g_I;						//全局计数器
CPreRabbit::CPreRabbit()
{

}

CPreRabbit::~CPreRabbit()
{

}
void	CPreRabbit::New(CBmp24*p,int x,int y)
{
	m_v=5;
	m_Direct=0;
	m_Wait=4;
	CAnimCtrl::New(p,x,y);

}
int		CPreRabbit::Play(void*)
{
		if(m_bHide) return 0;
		if(Key_Down)
		{
				m_pBmp=&DownWaitBmp;
				SetFlip(0);
				m_Direct=0;
		}
		if(Key_Up)
		{
				m_pBmp=&UpWaitBmp;
				SetFlip(0);
				m_Direct=1;
		}
		if(Key_Left) 
		{
			m_pBmp=&LeftRabbitBmp;
			AddXY(-m_v,0);
			SetIdx(g_I);
			SetFlip(0);
			m_Wait=0;
			m_Direct=3;

		}
		if(Key_Right)
		{
			m_pBmp=&LeftRabbitBmp;
			AddXY(m_v,0);
			SetIdx(g_I);
			SetFlip(1);
			m_Wait=0;
			m_Direct=2;

		}

		if(m_Wait>10)
		{
			switch(m_Direct)
			{
				case 0://向下
				m_pBmp=&DownWaitBmp;
				SetFlip(0);
				break;
			case 1://向下
				m_pBmp=&UpWaitBmp;
				SetFlip(0);
				break;
			case 2://向右
				m_pBmp=&LeftWaitBmp;
				SetFlip(1);
				break;
			case 3://向左
				m_pBmp=&LeftWaitBmp;
				SetFlip(0);
				break;
			}
			if(g_I%10==0)	SetIdx((g_I/10));
		}
		m_Wait++;
		if(m_x<15) 
		{
			g_MazeWidth=16;
			g_MazeHeight=14;
			return 1;
		}
		if(m_x>625-64) 
		{
			g_MazeWidth=80;
			g_MazeHeight=70;
			return 1;
		}
	return 0;
}