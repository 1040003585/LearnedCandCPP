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
	CPoint	   m_pointHero;	// 英雄的位置
	CBitmap    m_bmpHero;	// 英雄的图象
	bool        HeroFlag;    //英雄是否显示
	bool        first;
	int         HeroLife;     //英雄生命值
	int	       m_nWidth;		// 英雄的图象宽
	int	       m_nHeight;		// 英雄的图象高
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
