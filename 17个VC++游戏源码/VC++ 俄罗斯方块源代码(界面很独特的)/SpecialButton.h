//Download by http://www.NewXing.com
#if !defined(AFX_SPECIALBUTTON_H__896BFE80_C6BC_484D_A8BF_8732695C8330__INCLUDED_)
#define AFX_SPECIALBUTTON_H__896BFE80_C6BC_484D_A8BF_8732695C8330__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpecialButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpecialButton window

class CSpecialButton : public CButton
{
// Construction
public:
	CSpecialButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpecialButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetBKDC(CDC * pDC);
	void SetBitmap(int nIDB);
	void SetCaption(CString Caption);
 	CString m_strCaption;
	virtual ~CSpecialButton();

	// Generated message map functions
protected:
	CDC *m_pbkDC;
	CBitmap m_btBgnd;
	CDC m_dcMem;

	//{{AFX_MSG(CSpecialButton)
 	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPECIALBUTTON_H__896BFE80_C6BC_484D_A8BF_8732695C8330__INCLUDED_)
