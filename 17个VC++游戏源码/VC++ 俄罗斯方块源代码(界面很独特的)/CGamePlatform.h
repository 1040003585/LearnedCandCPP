//Download by http://www.NewXing.com
// CGamePlatform.h : interface of the CGamePlatform class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CGAMEPLATFORM_H__86C6234A_5DFA_4F57_A6BD_CCBC49E86D47__INCLUDED_)
#define AFX_CGAMEPLATFORM_H__86C6234A_5DFA_4F57_A6BD_CCBC49E86D47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<vector> 


#include "GameDiamond.h"
#include "SpecialButton.h"	// Added by ClassView

class CGamePlatform : public CFrameWnd
{
	
public:
	CGamePlatform();
protected: 
	DECLARE_DYNAMIC(CGamePlatform)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGamePlatform)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
 	//}}AFX_VIRTUAL

// Implementation
public:
	void BitmapToRegion();
	void OnRightKeyPressedDeal();
	void GameOnStartStateDeal();
	bool CollisionCheck(DIAMOND diamond,int nPosX,int nPosY);
 	virtual ~CGamePlatform();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
 
// Generated message map functions
protected:
	void SpecialEffort(int nLinenum);
	void DrawAchievement();
	void ReDrawTheCube(int nStartNum);
	void MoveOneLine(int LineNum);
	bool CheckFillUpOrNot(int nLineNum);
	void DealCollisionResult();
	void FillRectangle(int nCx,int nCy,int nWidth,int nHeight);
	bool m_bAccelerateFlag;
	void OnDownKeyPressedDeal();
	void OnUpKeyPressedDeal();
	void OnLeftKeyPressedDeal();
	void GameOnRunStateDeal();
	int m_nGameScore;
	int m_nGameLevel;
	CSpecialButton m_wndGameControl;
	CSpecialButton m_wndGameExit;
	CSpecialButton m_wndGameMinimize;
	void DrawCube(int nCx,int nCy,bool bFlag);
	void DrawDiamond(DIAMOND diamond,bool bFlag);
	void FillGameZone(DIAMOND curDiamond);

	CBitmap m_bitmapBgnd;
	CDC		m_dcMem;
  

    int m_nGameState;
	int m_nDiamondHeight;
	DIAMOND m_dmCurDiamond;
	DIAMOND m_dmNextDiamond;
	CGameDiamond DiamondControl;
	std::vector<std::vector<bool> > m_vtGameZone;

	void InitialGame();
 	//{{AFX_MSG(CGamePlatform)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnGameCtrlClick();
	afx_msg void OnPaint();
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg UINT OnNcHitTest(CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGAMEPLATFORM_H__86C6234A_5DFA_4F57_A6BD_CCBC49E86D47__INCLUDED_)
