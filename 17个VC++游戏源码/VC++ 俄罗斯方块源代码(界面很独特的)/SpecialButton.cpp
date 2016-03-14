// SpecialButton.cpp : implementation file
// Download by http://www.NewXing.com

#include "stdafx.h"
#include "Diamond.h"
#include "SpecialButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpecialButton

CSpecialButton::CSpecialButton( )
{	
	int m_nlocX = 0;
	int m_nlocY = 0;
}

CSpecialButton::~CSpecialButton()
{
}


BEGIN_MESSAGE_MAP(CSpecialButton, CButton)
	//{{AFX_MSG_MAP(CSpecialButton)
  	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpecialButton message handlers
void CSpecialButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDC dc;
    dc.Attach(lpDrawItemStruct->hDC);
 
	CRect ClientRect;
	GetClientRect(&ClientRect);
	dc.SetTextColor(RGB(255,255,255));
	CDC dcMem;
 	dcMem.CreateCompatibleDC(&dc);
	dcMem.SelectObject(&m_btBgnd);
	dc.BitBlt(0,0,ClientRect.Width(),ClientRect.Height(),m_pbkDC,0,0,SRCCOPY);
	dc.SetBkMode(TRANSPARENT);
 
	if(lpDrawItemStruct->itemState & ODS_SELECTED)
	{
       dc.BitBlt(2,2,ClientRect.Width(),ClientRect.Height(),&dcMem,0,0,SRCCOPY);
 	   dc.DrawText(m_strCaption,&ClientRect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
	}
	else
	{
   	   dc.BitBlt(0,0,ClientRect.Width(),ClientRect.Height(),&dcMem,0,0,SRCCOPY);
	   dc.DrawText(m_strCaption,&ClientRect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);

	}
	dc.Detach();	
}

void CSpecialButton::SetCaption(CString Caption)
{
    m_strCaption = Caption;
}
 

void CSpecialButton::SetBitmap(int nIDB)
{
	m_btBgnd.LoadBitmap(nIDB);
}

void CSpecialButton::SetBKDC(CDC *pDC)
{
	m_pbkDC = pDC;
}
