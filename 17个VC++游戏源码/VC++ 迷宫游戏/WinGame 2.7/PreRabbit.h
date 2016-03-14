//Download by http://www.NewXing.com
#ifndef _PRERABBIT_H_
#define _PRERABBIT_H_
#pragma once
//=================================================================================
#include "INCLUDE\AnimCtrl.h"
//=================================================================================
class CPreRabbit : public CAnimCtrl  
{
public:
	virtual	void	New(CBmp24*p,int x,int y);
	virtual	int		Play(void*);
	CPreRabbit();
	virtual ~CPreRabbit();
private:
	int			m_Direct;//兔子的当前方向
	int			m_Wait;	//用于判断兔子需不需要等待的计数器
	int			m_v;	//兔子每次移动多少像素
};
//================================================================================
#endif 