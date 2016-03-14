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
	m_pointHero	= CPoint(100, 300);//���긳��ֵ
	HeroFlag=false;
	first=true;
	HeroLife=10;//����ֵ��ʼ��Ϊ100
	m_bmpHero.LoadBitmap(IDB_HERO);
	BITMAP BM;
	m_bmpHero.GetBitmap(&BM);//ͨ���˺������ͼ��ĳ����
	m_nWidth	= BM.bmWidth/2;
	m_nHeight	= BM.bmHeight;
}
// ��ʾӢ��
void CHero::ShowHero(CDC *pDC, CDC *pMemDC, CRect Client)
{	
	pMemDC->SelectObject(&m_bmpHero);
	pDC->BitBlt(m_pointHero.x,m_pointHero.y,m_nWidth,m_nHeight,
		pMemDC,m_nWidth,0,SRCPAINT);//������
	pDC->BitBlt(m_pointHero.x,m_pointHero.y,m_nWidth,m_nHeight,
		pMemDC,0,0,SRCAND);//������
}
// ����tag�ı�Ӣ��λ��
void CHero::ChangePos(int tag)
{	
    if(tag == 0 && m_pointHero.x+m_nWidth < 986)//�߽�
		m_pointHero.x	+= 20;//����
	else if(tag == 1 && m_pointHero.x > 0)//�߽�
		m_pointHero.x	-= 20;//����
	else if(tag == 2 && m_pointHero.y+m_nHeight < 600)//�߽�
		m_pointHero.y	+= 20;//����
	else if(tag == 3 && m_pointHero.y+m_nWidth >60)//�߽�
		m_pointHero.y	-= 20;//����
}
//��λӢ��λ��
void CHero::ResetPos()
{
	m_pointHero	= CPoint(100, 300);//���긳��ֵ
	HeroFlag=false;
	HeroLife=10;//����ֵ��ʼ��Ϊ10
	m_bmpHero.LoadBitmap(IDB_HERO1);
	BITMAP BM;
	m_bmpHero.GetBitmap(&BM);//ͨ���˺������ͼ��ĳ����
	m_nWidth	= BM.bmWidth/2;
	m_nHeight	= BM.bmHeight;
}

CHero::~CHero()
{
	
}
