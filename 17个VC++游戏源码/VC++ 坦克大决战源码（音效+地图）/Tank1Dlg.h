//Download by http://www.NewXing.com
// Tank1Dlg.h : header file
//

#if !defined(AFX_TANK1DLG_H__B0637D65_4FF2_4BD9_AC6D_E0C4A5B789AE__INCLUDED_)
#define AFX_TANK1DLG_H__B0637D65_4FF2_4BD9_AC6D_E0C4A5B789AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTank1Dlg dialog
#include "game.h"

class CTank1Dlg : public CDialog
{
// Construction
public:
	CTank1Dlg(CWnd* pParent = NULL);	// standard constructor



//	AfxMessageBox("hi");
	//***********************************************************************/
//////////////我的游戏类在次声明//////////
	game mygame;
	BLENDFUNCTION rBlend;			//半透明
	//***********************************************************************/



// Dialog Data
	//{{AFX_DATA(CTank1Dlg)
	enum { IDD = IDD_TANK1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTank1Dlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTank1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANK1DLG_H__B0637D65_4FF2_4BD9_AC6D_E0C4A5B789AE__INCLUDED_)
