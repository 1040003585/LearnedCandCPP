// CatCatchRatDoc.h : interface of the CCatCatchRatDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CATCATCHRATDOC_H__840D654B_7A6E_4316_851A_E8A370BE0254__INCLUDED_)
#define AFX_CATCATCHRATDOC_H__840D654B_7A6E_4316_851A_E8A370BE0254__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCatCatchRatDoc : public CDocument
{
protected: // create from serialization only
	CCatCatchRatDoc();
	DECLARE_DYNCREATE(CCatCatchRatDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCatCatchRatDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCatCatchRatDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCatCatchRatDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CATCATCHRATDOC_H__840D654B_7A6E_4316_851A_E8A370BE0254__INCLUDED_)
