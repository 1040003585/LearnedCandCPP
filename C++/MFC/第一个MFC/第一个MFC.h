// 第一个MFC.h : main header file for the 第一个MFC application
//

#if !defined(AFX_MFC_H__69C08BEF_A1F9_43E4_8BBF_1858428B5547__INCLUDED_)
#define AFX_MFC_H__69C08BEF_A1F9_43E4_8BBF_1858428B5547__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCApp:
// See 第一个MFC.cpp for the implementation of this class
//

class CMFCApp : public CWinApp
{
public:
	CMFCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_H__69C08BEF_A1F9_43E4_8BBF_1858428B5547__INCLUDED_)
