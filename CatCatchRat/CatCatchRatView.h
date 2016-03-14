// CatCatchRatView.h : interface of the CCatCatchRatView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CATCATCHRATVIEW_H__B4196808_4145_49DF_99D0_45F38E4512CB__INCLUDED_)
#define AFX_CATCATCHRATVIEW_H__B4196808_4145_49DF_99D0_45F38E4512CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SelectDlg.h"

#define RATMAX 5 //宏定义，老鼠的最大个数
class CCatCatchRatView : public CView
{
public:
	CBitmap    m_bmCat[4],m_bmRat[4];                   //猫和老鼠的位图
	int        StartFlag; //程序运行状态，－1:处世状态，0:游戏暂停，1:游戏开始，2:游戏结束
	bool       m_bRatLive[RATMAX];                      //老鼠存活标志
	int        m_nCatw,m_nCath;                         //猫位图的宽和高
	int        m_nCatx,m_nCaty;                         //猫位图的左上角坐标
	int        m_nRatDirection[RATMAX],m_nCatDirection; //猫和老鼠的运动方向
	int        m_nRatw,m_nRath;                         //老鼠位图的宽和高
	int        m_nRatx[RATMAX],m_nRaty[RATMAX];         //老鼠位图的左上角坐标
	CRect      m_rectClient;                            //场地矩形
	CRect      m_rectRat[RATMAX],m_rectCat;             //猫和老鼠位图的矩形
	int        m_nRat;                                  //待抓老鼠数
	int        m_nRatSpeed,m_nCatSpeed;                 //运动速度
	CTime      m_timeStart,m_timeEnd;                   //游戏开始和结束时间
	CTimeSpan  m_timeWork,m_timeSet;                    //游戏剩余时间和设定时间
	int        m_nDifficulty;                           //难度，0:低，1:中，2:高
	int        m_nWinFlag;                              //游戏获胜者，0:猫获胜，1:老鼠获胜

protected: // create from serialization only
	CCatCatchRatView();
	DECLARE_DYNCREATE(CCatCatchRatView)

// Attributes
public:
	CCatCatchRatDoc* GetDocument();

// Operations
public:

protected:
	/*
这是一个用来画透明位图的函数
CDC *pDC 需要画位图的CDC指针
UINT IDImage 位图资源ID
Crect &rect 指定位图在pDC中的位置
COLORREF rgbMask 位图的透明色

*/
void DrawTransparentBitmap(CDC *pDC,CBitmap &Image,CRect &rect, COLORREF rgbMask);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCatCatchRatView)
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
	virtual ~CCatCatchRatView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCatCatchRatView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRestart();
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnUpdateStop(CCmdUI* pCmdUI);
	afx_msg void OnSelect();
	afx_msg void OnUpdateStart(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CatCatchRatView.cpp
inline CCatCatchRatDoc* CCatCatchRatView::GetDocument()
   { return (CCatCatchRatDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CATCATCHRATVIEW_H__B4196808_4145_49DF_99D0_45F38E4512CB__INCLUDED_)
