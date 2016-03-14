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
	CPoint	   m_pointEnemy;	// С���λ��
	CBitmap    m_bmpEnemy;	// С���ͼ��
	bool        EnemyFlag;    //С���Ƿ���ʾ
	int         EnemyLife;     //С������ֵ
	int	       m_nWidth;		// С���ͼ���
	int	       m_nHeight;		// С���ͼ���
	int num;
public:
	CEnemy();
	void	ShowEnemy(CDC *pDC, CDC *pMemDC, CRect Client);//��ʾС��
	CRect	GetEnemy()
	{//��ȡС��ĵ�ǰλ��
		return CRect(m_pointEnemy.x, m_pointEnemy.y,
			m_pointEnemy.x+m_nWidth, m_pointEnemy.y+m_nHeight);
	}
	void	ChangePos(int num);//С��λ�øı�
	void	ResetPos();//С��λ�ø�λ
	
	virtual ~CEnemy();
	
	
};

#endif // !defined(AFX_ENEMY_H__751FED98_7096_48A0_83B9_E5A4E3AA6FE0__INCLUDED_)
