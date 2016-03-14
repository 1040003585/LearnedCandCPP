// Enemy.cpp: implementation of the CEnemy class.
// Download by http://www.NewXing.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Game.h"
#include "Enemy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEnemy::CEnemy()
{
	num=rand()%20;
	m_pointEnemy	= CPoint(926, 10);//初始位置坐标
	EnemyFlag=false;
	EnemyLife=10;//生命值设为10
	if (num<5)//显示不同的鱼的图片
	{
		m_bmpEnemy.LoadBitmap(IDB_ENEMY);
	}
	else if (num>10)
	{
		m_bmpEnemy.LoadBitmap(IDB_ENEMY2);
	}
	else
	{
		m_bmpEnemy.LoadBitmap(IDB_ENEMY3);

	}
	BITMAP BM;
	m_bmpEnemy.GetBitmap(&BM);
	m_nWidth	= BM.bmWidth/2;
	m_nHeight	= BM.bmHeight;
}
// 显示小鱼
void CEnemy::ShowEnemy(CDC *pDC, CDC *pMemDC, CRect Client)
{	
	pMemDC->SelectObject(&m_bmpEnemy);
	pDC->BitBlt(m_pointEnemy.x,m_pointEnemy.y,m_nWidth,m_nHeight,
		pMemDC,m_nWidth,0,SRCPAINT);//或运算
	pDC->BitBlt(m_pointEnemy.x,m_pointEnemy.y,m_nWidth,m_nHeight,
		pMemDC,0,0,SRCAND);//与运算
}
// 改变小鱼位置  在屏幕上方来回平移
void CEnemy::ChangePos(int num)
{	
	if(m_pointEnemy.x<0||m_pointEnemy.y>500)
	{//边界是926
		m_pointEnemy.x  = rand()%926;
		m_pointEnemy.y = rand()%600;
	}
	else
	{
		m_pointEnemy.x -= num;
		m_pointEnemy.y+=rand()%12;
	}
}
void CEnemy::ResetPos()
{//复位鱼的位置

	m_pointEnemy=(0,0);
}
CEnemy::~CEnemy()
{
	
}
