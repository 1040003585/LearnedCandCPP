//Download by http://www.NewXing.com
#if !defined(AFX_LEVAL_H__5591A4B0_1A79_40D8_9C07_D32ACD6E5BD2__INCLUDED_)
#define AFX_LEVAL_H__5591A4B0_1A79_40D8_9C07_D32ACD6E5BD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Leval.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeval dialog

class CLeval : public CDialog
{
// Construction
public:
	CLeval(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLeval)
	enum { IDD = IDD_DIALOG1 };
	int		m_leval;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeval)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLeval)
	afx_msg void OnChangeLeval();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEVAL_H__5591A4B0_1A79_40D8_9C07_D32ACD6E5BD2__INCLUDED_)
