//Download by http://www.NewXing.com
// Hero.cpp: implementation of the CHero class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Game.h"
#include "Hero.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHero::CHero()
{	
	m_pointHero	= CPoint(100, 300);//坐标赋初值
	HeroFlag=false;
	first=true;
	HeroLife=10;//生命值初始设为100
	m_bmpHero.LoadBitmap(IDB_HERO);
	BITMAP BM;
	m_bmpHero.GetBitmap(&BM);//通过此函数获得图像的长与宽
	m_nWidth	= BM.bmWidth/2;
	m_nHeight	= BM.bmHeight;
}
// 显示英雄
void CHero::ShowHero(CDC *pDC, CDC *pMemDC, CRect Client)
{	
	pMemDC->SelectObject(&m_bmpHero);
	pDC->BitBlt(m_pointHero.x,m_pointHero.y,m_nWidth,m_nHeight,
		pMemDC,m_nWidth,0,SRCPAINT);//或运算
	pDC->BitBlt(m_pointHero.x,m_pointHero.y,m_nWidth,m_nHeight,
		pMemDC,0,0,SRCAND);//与运算
}
// 根据tag改变英雄位置
void CHero::ChangePos(int tag)
{	
    if(tag == 0 && m_pointHero.x+m_nWidth < 986)//边界
		m_pointHero.x	+= 20;//右移
	else if(tag == 1 && m_pointHero.x > 0)//边界
		m_pointHero.x	-= 20;//左移
	else if(tag == 2 && m_pointHero.y+m_nHeight < 600)//边界
		m_pointHero.y	+= 20;//下移
	else if(tag == 3 && m_pointHero.y+m_nWidth >60)//边界
		m_pointHero.y	-= 20;//上移
}
//复位英雄位置
void CHero::ResetPos()
{
	m_pointHero	= CPoint(100, 300);//坐标赋初值
	HeroFlag=false;
	HeroLife=10;//生命值初始设为10
	m_bmpHero.LoadBitmap(IDB_HERO1);
	BITMAP BM;
	m_bmpHero.GetBitmap(&BM);//通过此函数获得图像的长与宽
	m_nWidth	= BM.bmWidth/2;
	m_nHeight	= BM.bmHeight;
}

CHero::~CHero()
{
	
}
