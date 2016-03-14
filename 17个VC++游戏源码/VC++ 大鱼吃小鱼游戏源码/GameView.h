//Download by http://www.NewXing.com
// GameView.h : interface of the CGameView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMEVIEW_H__D64858F7_F815_45C4_85CE_2BB1B0ECC913__INCLUDED_)
#define AFX_GAMEVIEW_H__D64858F7_F815_45C4_85CE_2BB1B0ECC913__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Enemy.h"
#include "Hero.h"
#include "Boss.h"
#include "Pall.h"
#include "Leval.h"
class CGameView : public CView
{
protected: // create from serialization only
	CGameView();
	DECLARE_DYNCREATE(CGameView)

// Attributes
public:
	CGameDoc* GetDocument();
	void DrawGround(CDC *pDC, CRect Client);
	BOOL ShotOn(CRect &body1, CRect &body2);
// Operations
public:
	CPall pall[4];
	CBoss boss[4];
	CHero hero;
	CEnemy enemy[21];
	CLeval Dlg;
	int leval;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	int Score;
	int temp;
	virtual ~CGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGameView)
	afx_msg void OnGamestart();
	afx_msg void OnGamestop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnLeval();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMusic();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GameView.cpp
inline CGameDoc* CGameView::GetDocument()
   { return (CGameDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMEVIEW_H__D64858F7_F815_45C4_85CE_2BB1B0ECC913__INCLUDED_)
