// Leval.cpp : implementation file
// Download by http://www.NewXing.com

#include "stdafx.h"
#include "Game.h"
#include "Leval.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeval dialog


CLeval::CLeval(CWnd* pParent /*=NULL*/)
	: CDialog(CLeval::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLeval)
	m_leval = 0;
	//}}AFX_DATA_INIT
}


void CLeval::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeval)
	DDX_Text(pDX, IDC_LEVAL, m_leval);
	DDV_MinMaxInt(pDX, m_leval, 1, 2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeval, CDialog)
	//{{AFX_MSG_MAP(CLeval)
	ON_EN_CHANGE(IDC_LEVAL, OnChangeLeval)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeval message handlers

void CLeval::OnChangeLeval() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(true);
}
