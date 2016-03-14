//Download by http://www.NewXing.com
// Enemy.h: interface for the CEnemy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENEMY_H__751FED98_7096_48A0_83B9_E5A4E3AA6FE0__INCLUDED_)
#define AFX_ENEMY_H__751FED98_7096_48A0_83B9_E5A4E3AA6FE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEnemy  
{
public:
	CPoint	   m_pointEnemy;	// 小鱼的位置
	CBitmap    m_bmpEnemy;	// 小鱼的图象
	bool        EnemyFlag;    //小鱼是否显示
	int         EnemyLife;     //小鱼生命值
	int	       m_nWidth;		// 小鱼的图象宽
	int	       m_nHeight;		// 小鱼的图象高
	int num;
public:
	CEnemy();
	void	ShowEnemy(CDC *pDC, CDC *pMemDC, CRect Client);//显示小鱼
	CRect	GetEnemy()
	{//获取小鱼的当前位置
		return CRect(m_pointEnemy.x, m_pointEnemy.y,
			m_pointEnemy.x+m_nWidth, m_pointEnemy.y+m_nHeight);
	}
	void	ChangePos(int num);//小鱼位置改变
	void	ResetPos();//小鱼位置复位
	
	virtual ~CEnemy();
	
	
};

#endif // !defined(AFX_ENEMY_H__751FED98_7096_48A0_83B9_E5A4E3AA6FE0__INCLUDED_)
