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
	CPoint	   m_pointPall ;	// 小鱼的位置
	CBitmap    m_bmpPall;	// 小鱼的图象
	bool        PallFlag;    //小鱼是否显示
	int         PallLife;     //小鱼生命值
	int	       m_nWidth;		// 小鱼的图象宽
	int	       m_nHeight;		// 小鱼的图象高
	int num;
public:
	CPall();
	void	ShowPall(CDC *pDC, CDC *pMemDC, CRect Client);//显示小鱼
	CRect	GetPall()
	{//获取小鱼的当前位置
		return CRect(m_pointPall.x, m_pointPall.y,
			m_pointPall.x+m_nWidth, m_pointPall.y+m_nHeight);
	}
	void	ChangePos(int num);//小鱼位置改变
	void	ResetPos();//小鱼位置复位
	
	virtual ~CPall();
	
	
};

#endif // !defined(AFX_PALL_H__8B5A52EE_B53F_4EFC_B076_C54AA53FF8D5__INCLUDED_)
