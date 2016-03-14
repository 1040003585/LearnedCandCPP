//Download by http://www.NewXing.com
// Boss.h: interface for the CBoss class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOSS_H__7BB32798_F40B_436E_89EF_D1AA891391FB__INCLUDED_)
#define AFX_BOSS_H__7BB32798_F40B_436E_89EF_D1AA891391FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBoss 
{
public:
	CPoint	   m_pointBoss;	// 敌机的位置
	CBitmap    m_bmpBoss;	// 敌机的图象
	bool        BossFlag;    //敌机是否显示
	int         BossLife;     //敌机生命值
	int	       m_nWidth;		// 敌机的图象宽
	int	       m_nHeight;		// 敌机的图象高
	bool first;
public:
	CBoss();
	void	ShowBoss(CDC *pDC, CDC *pMemDC, CRect Client);//显示敌机
	CRect	GetBoss()
	{//获取敌机的当前位置
		return CRect(m_pointBoss.x, m_pointBoss.y,
			m_pointBoss.x+m_nWidth, m_pointBoss.y+m_nHeight);
	}
	void	ChangePos(int num);//敌机位置改变
	void	ResetPos();//敌机位置复位
	
	virtual ~CBoss();
	
	
};

#endif // !defined(AFX_BOSS_H__7BB32798_F40B_436E_89EF_D1AA891391FB__INCLUDED_)
