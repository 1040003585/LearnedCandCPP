//Download by http://www.NewXing.com
// Hero.h: interface for the CHero class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HERO_H__8DB9C399_A278_4182_87E7_F59796065944__INCLUDED_)
#define AFX_HERO_H__8DB9C399_A278_4182_87E7_F59796065944__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CHero  
{
public:
	CPoint	   m_pointHero;	// Ӣ�۵�λ��
	CBitmap    m_bmpHero;	// Ӣ�۵�ͼ��
	bool        HeroFlag;    //Ӣ���Ƿ���ʾ
	bool        first;
	int         HeroLife;     //Ӣ������ֵ
	int	       m_nWidth;		// Ӣ�۵�ͼ���
	int	       m_nHeight;		// Ӣ�۵�ͼ���
public:
	CHero();
	void	ShowHero(CDC *pDC, CDC *pMemDC, CRect Client);
	CRect	GetHero(){return CRect(m_pointHero.x, m_pointHero.y,
		m_pointHero.x+m_nWidth, m_pointHero.y+m_nHeight);}
	void	ChangePos(int tag);
	void	ResetPos();
	
	virtual ~CHero();
	
	
};

#endif // !defined(AFX_HERO_H__8DB9C399_A278_4182_87E7_F59796065944__INCLUDED_)
