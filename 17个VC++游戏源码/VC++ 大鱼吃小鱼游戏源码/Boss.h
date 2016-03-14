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
	CPoint	   m_pointBoss;	// �л���λ��
	CBitmap    m_bmpBoss;	// �л���ͼ��
	bool        BossFlag;    //�л��Ƿ���ʾ
	int         BossLife;     //�л�����ֵ
	int	       m_nWidth;		// �л���ͼ���
	int	       m_nHeight;		// �л���ͼ���
	bool first;
public:
	CBoss();
	void	ShowBoss(CDC *pDC, CDC *pMemDC, CRect Client);//��ʾ�л�
	CRect	GetBoss()
	{//��ȡ�л��ĵ�ǰλ��
		return CRect(m_pointBoss.x, m_pointBoss.y,
			m_pointBoss.x+m_nWidth, m_pointBoss.y+m_nHeight);
	}
	void	ChangePos(int num);//�л�λ�øı�
	void	ResetPos();//�л�λ�ø�λ
	
	virtual ~CBoss();
	
	
};

#endif // !defined(AFX_BOSS_H__7BB32798_F40B_436E_89EF_D1AA891391FB__INCLUDED_)
