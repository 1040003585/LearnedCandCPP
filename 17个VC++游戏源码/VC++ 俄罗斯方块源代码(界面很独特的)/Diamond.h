//Download by http://www.NewXing.com
// Diamond.h : main header file for the DIAMOND application
//

#if !defined(AFX_DIAMOND_H__7CC7C64E_3000_4E51_B288_CE0BB7585181__INCLUDED_)
#define AFX_DIAMOND_H__7CC7C64E_3000_4E51_B288_CE0BB7585181__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDiamondApp:
// See Diamond.cpp for the implementation of this class
//
#define GAME_START 0
#define GAME_RUN   1
#define GAME_PAUSE 2
#define GAME_END   3 
#define GAME_IDLE   4 
#define GAME_ZONE_WIDTH 12
#define GAME_ZONE_HEIGHT 18


class CDiamondApp : public CWinApp
{
public:
	CDiamondApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiamondApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CDiamondApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIAMOND_H__7CC7C64E_3000_4E51_B288_CE0BB7585181__INCLUDED_)
