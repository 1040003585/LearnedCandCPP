//Download by http://www.NewXing.com
// Pall.h: interface for the CPall class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PALL_H__8B5A52EE_B53F_4EFC_B076_C54AA53FF8D5__INCLUDED_)
#define AFX_PALL_H__8B5A52EE_B53F_4EFC_B076_C54AA53FF8D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPall  
{
public:
	CPoint	   m_pointPall ;	// С���λ��
	CBitmap    m_bmpPall;	// С���ͼ��
	bool        PallFlag;    //С���Ƿ���ʾ
	int         PallLife;     //С������ֵ
	int	       m_nWidth;		// С���ͼ���
	int	       m_nHeight;		// С���ͼ���
	int num;
public:
	CPall();
	void	ShowPall(CDC *pDC, CDC *pMemDC, CRect Client);//��ʾС��
	CRect	GetPall()
	{//��ȡС��ĵ�ǰλ��
		return CRect(m_pointPall.x, m_pointPall.y,
			m_pointPall.x+m_nWidth, m_pointPall.y+m_nHeight);
	}
	void	ChangePos(int num);//С��λ�øı�
	void	ResetPos();//С��λ�ø�λ
	
	virtual ~CPall();
	
	
};

#endif // !defined(AFX_PALL_H__8B5A52EE_B53F_4EFC_B076_C54AA53FF8D5__INCLUDED_)
