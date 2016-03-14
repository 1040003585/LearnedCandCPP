// Pall.cpp: implementation of the CPall class.
// Download by http://www.NewXing.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Game.h"
#include "Pall.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPall::CPall()
{
	num=rand()%20;
	m_pointPall	= CPoint(26, 600);//��ʼλ������
	PallFlag=false;
	PallLife=10;//����ֵ��Ϊ10
	
		m_bmpPall.LoadBitmap(IDB_BITMAP4);
	
	
	BITMAP BM;
	m_bmpPall.GetBitmap(&BM);
	m_nWidth	= BM.bmWidth/2;
	m_nHeight	= BM.bmHeight;
}
// ��ʾpall
void CPall::ShowPall(CDC *pDC, CDC *pMemDC, CRect Client)
{	
	pMemDC->SelectObject(&m_bmpPall);
	pDC->BitBlt(m_pointPall.x,m_pointPall.y,m_nWidth,m_nHeight,
		pMemDC,m_nWidth,0,SRCPAINT);//������
	pDC->BitBlt(m_pointPall.x,m_pointPall.y,m_nWidth,m_nHeight,
		pMemDC,0,0,SRCAND);//������
}
// �ı�pall�����ƶ�
void CPall::ChangePos(int num)
{	
	if(m_pointPall.y>0)
	{//�߽���926
		
		m_pointPall.y -= rand()%60;
	}
	else
	{
		
		m_pointPall.y=rand()%1024;
	}
}
void CPall::ResetPos()
{
	
	m_pointPall=(0,0);
}
CPall::~CPall()
{
	
}
