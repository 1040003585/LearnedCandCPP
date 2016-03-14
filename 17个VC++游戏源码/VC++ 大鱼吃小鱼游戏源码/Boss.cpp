// Boss.cpp: implementation of the CBoss class.
// Download by http://www.NewXing.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Game.h"
#include "Boss.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBoss::CBoss()
{
	m_pointBoss	= CPoint(926, 10);//初始boss位置坐标
	BossFlag=true;//初始显示,true显示
	first=true;   //用于是否跟踪，跟踪为false
	BossLife=100;//生命值设为100
	m_bmpBoss.LoadBitmap(IDB_BOSS);
	BITMAP BM;
	m_bmpBoss.GetBitmap(&BM);//获得当前图片的长和宽
	m_nWidth	= BM.bmWidth/2;
	m_nHeight	= BM.bmHeight;
}
// 显示boss
void CBoss::ShowBoss(CDC *pDC, CDC *pMemDC, CRect Client)
{	
	pMemDC->SelectObject(&m_bmpBoss);
	pDC->BitBlt(m_pointBoss.x,m_pointBoss.y,m_nWidth,m_nHeight,
		pMemDC,m_nWidth,0,SRCPAINT);//或运算
	pDC->BitBlt(m_pointBoss.x,m_pointBoss.y,m_nWidth,m_nHeight,
		pMemDC,0,0,SRCAND);//与运算
}
// 改变boss位置  在屏幕上方来回平移
void CBoss::ChangePos(int num)
{	
	if(m_pointBoss.x<0||m_pointBoss.y>500)
	{//边界是926
		m_pointBoss.x  = rand()%926;
		m_pointBoss.y = rand()%600;
	}
	else
	{
		m_pointBoss.x -= num;
		m_pointBoss.y+=rand()%12;
	}
}
void CBoss::ResetPos()//复位
{
	m_pointBoss=(0,0);
}
CBoss::~CBoss()
{
	
}
