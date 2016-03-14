// 第一个MFCDoc.cpp : implementation of the CMFCDoc class
//

#include "stdafx.h"
#include "第一个MFC.h"

#include "第一个MFCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCDoc

IMPLEMENT_DYNCREATE(CMFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCDoc construction/destruction

CMFCDoc::CMFCDoc()
{
	// TODO: add one-time construction code here

}

CMFCDoc::~CMFCDoc()
{
}

BOOL CMFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCDoc serialization

void CMFCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMFCDoc diagnostics

#ifdef _DEBUG
void CMFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCDoc commands
