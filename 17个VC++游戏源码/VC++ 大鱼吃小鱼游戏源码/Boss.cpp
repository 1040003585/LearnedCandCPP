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
	m_pointBoss	= CPoint(926, 10);//��ʼbossλ������
	BossFlag=true;//��ʼ��ʾ,true��ʾ
	first=true;   //�����Ƿ���٣�����Ϊfalse
	BossLife=100;//����ֵ��Ϊ100
	m_bmpBoss.LoadBitmap(IDB_BOSS);
	BITMAP BM;
	m_bmpBoss.GetBitmap(&BM);//��õ�ǰͼƬ�ĳ��Ϳ�
	m_nWidth	= BM.bmWidth/2;
	m_nHeight	= BM.bmHeight;
}
// ��ʾboss
void CBoss::ShowBoss(CDC *pDC, CDC *pMemDC, CRect Client)
{	
	pMemDC->SelectObject(&m_bmpBoss);
	pDC->BitBlt(m_pointBoss.x,m_pointBoss.y,m_nWidth,m_nHeight,
		pMemDC,m_nWidth,0,SRCPAINT);//������
	pDC->BitBlt(m_pointBoss.x,m_pointBoss.y,m_nWidth,m_nHeight,
		pMemDC,0,0,SRCAND);//������
}
// �ı�bossλ��  ����Ļ�Ϸ�����ƽ��
void CBoss::ChangePos(int num)
{	
	if(m_pointBoss.x<0||m_pointBoss.y>500)
	{//�߽���926
		m_pointBoss.x  = rand()%926;
		m_pointBoss.y = rand()%600;
	}
	else
	{
		m_pointBoss.x -= num;
		m_pointBoss.y+=rand()%12;
	}
}
void CBoss::ResetPos()//��λ
{
	m_pointBoss=(0,0);
}
CBoss::~CBoss()
{
	
}
