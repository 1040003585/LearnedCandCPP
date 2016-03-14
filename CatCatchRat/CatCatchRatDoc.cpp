// CatCatchRatDoc.cpp : implementation of the CCatCatchRatDoc class
//

#include "stdafx.h"
#include "CatCatchRat.h"

#include "CatCatchRatDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCatCatchRatDoc

IMPLEMENT_DYNCREATE(CCatCatchRatDoc, CDocument)

BEGIN_MESSAGE_MAP(CCatCatchRatDoc, CDocument)
	//{{AFX_MSG_MAP(CCatCatchRatDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCatCatchRatDoc construction/destruction

CCatCatchRatDoc::CCatCatchRatDoc()
{
	// TODO: add one-time construction code here

}

CCatCatchRatDoc::~CCatCatchRatDoc()
{
}

BOOL CCatCatchRatDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCatCatchRatDoc serialization

void CCatCatchRatDoc::Serialize(CArchive& ar)
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
// CCatCatchRatDoc diagnostics

#ifdef _DEBUG
void CCatCatchRatDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCatCatchRatDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCatCatchRatDoc commands
