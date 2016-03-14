//Download by http://www.NewXing.com
//===========================================================
#ifndef _SHOWLIST_H_ 
#define _SHOWLIST_H_ 
#pragma once
//=========================================================
#include <list>
class	CAnimCtrl;
class	CBmp24;
class CShowList  
{
public:
	void	Add(CAnimCtrl*);
	void	Remove(CAnimCtrl*);
	void	ShowAllAnim(CBmp24*p);
	void	ClearAllAnim();
	CShowList();
	virtual ~CShowList();
private:
	 std::list<CAnimCtrl*> m_List[10];
};

#endif 