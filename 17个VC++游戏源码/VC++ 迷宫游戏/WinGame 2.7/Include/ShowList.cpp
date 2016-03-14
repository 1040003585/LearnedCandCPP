//Download by http://www.NewXing.com
// ShowList.cpp: implementation of the CShowList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ShowList.h"
#include "AnimCtrl.h"
//=======================================================================
CShowList::CShowList(){}
CShowList::~CShowList(){}
//====================================================================
void	CShowList::Add(CAnimCtrl* p)
{
	int d=p->GetDepth();
	if(d<0) d=0;
	if(d>9)	d=9;
	m_List[d].push_back(p);
}
void	CShowList::Remove(CAnimCtrl*p)
{
	int d=p->GetDepth();
	if(d<0) d=0;
	if(d>9)	d=9;
	m_List[d].remove(p);
}
void	CShowList::ShowAllAnim(CBmp24*p)
{
	p->MemsetBits(0);
	std::list<CAnimCtrl*>::const_iterator cp;
	for(int i=0;i<10;i++)
	for(cp=m_List[i].begin();cp!=m_List[i].end();cp++)
	{
		(*cp)->Draw(p);//动画控制类的那个显示函数
	}

}
void	CShowList::ClearAllAnim()
{
	for(int i=0;i<10;i++)
	m_List[i].clear();
}