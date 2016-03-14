// CatCatchRat.h : main header file for the CATCATCHRAT application
//

#if !defined(AFX_CATCATCHRAT_H__F387CA9B_93E5_4CAE_B248_270C8AAB8A20__INCLUDED_)
#define AFX_CATCATCHRAT_H__F387CA9B_93E5_4CAE_B248_270C8AAB8A20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCatCatchRatApp:
// See CatCatchRat.cpp for the implementation of this class
//

class CCatCatchRatApp : public CWinApp
{
public:
	CCatCatchRatApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCatCatchRatApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCatCatchRatApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CATCATCHRAT_H__F387CA9B_93E5_4CAE_B248_270C8AAB8A20__INCLUDED_)
