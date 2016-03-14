// CatCatchRatView.cpp : implementation of the CCatCatchRatView class
//

#include "stdafx.h"
#include "CatCatchRat.h"

#include "CatCatchRatDoc.h"
#include "CatCatchRatView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCatCatchRatView

IMPLEMENT_DYNCREATE(CCatCatchRatView, CView)

BEGIN_MESSAGE_MAP(CCatCatchRatView, CView)
	//{{AFX_MSG_MAP(CCatCatchRatView)
	ON_WM_TIMER()
	ON_COMMAND(ID_Restart, OnRestart)
	ON_COMMAND(ID_Start, OnStart)
	ON_COMMAND(ID_Stop, OnStop)
	ON_WM_KEYDOWN()
	ON_UPDATE_COMMAND_UI(ID_Stop, OnUpdateStop)
	ON_COMMAND(ID_SELECT, OnSelect)
	ON_UPDATE_COMMAND_UI(ID_Start, OnUpdateStart)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCatCatchRatView construction/destruction

CCatCatchRatView::CCatCatchRatView()
{
	// TODO: add construction code here
	//载入猫和老鼠的位图资源
	m_bmCat[0].LoadBitmap(IDB_CatUp);
	m_bmCat[1].LoadBitmap(IDB_CatDown);
	m_bmCat[2].LoadBitmap(IDB_CatLeft);
	m_bmCat[3].LoadBitmap(IDB_CatRight);
	m_bmRat[0].LoadBitmap(IDB_RatUp);
	m_bmRat[1].LoadBitmap(IDB_RatDown);
	m_bmRat[2].LoadBitmap(IDB_RatLeft);
	m_bmRat[3].LoadBitmap(IDB_RatRight);
	//计算猫和老鼠位图的搞和宽
	BITMAP bmCat;
	m_bmCat[2].GetBitmap(&bmCat);
	m_nCatw=bmCat.bmWidth;
	m_nCath=bmCat.bmHeight;
	BITMAP bmRat[4];
	m_bmRat[0].GetBitmap(&bmRat[0]);
	m_bmRat[1].GetBitmap(&bmRat[1]);
	m_bmRat[2].GetBitmap(&bmRat[2]);
	m_bmRat[3].GetBitmap(&bmRat[3]);
	m_nRatw=bmRat[0].bmWidth;
	m_nRath=bmRat[0].bmHeight;
	//场地矩形和老鼠数目设置
	m_rectClient=CRect(20,20,380,380);
	m_nRat=RATMAX;
	StartFlag=-1;
	//计算猫和老鼠位图的初时位置和运动方向
	m_nCatx=m_rectClient.left+m_rectClient.Width()/2;
	m_nCaty=m_rectClient.top+m_rectClient.Height()/2;
	m_rectCat=CRect(m_nCatx,m_nCaty,m_nCatx+m_nCatw,m_nCaty+m_nCath);
	m_nCatDirection=2;
	srand((unsigned)time(NULL));
	for(int i=0;i<RATMAX;i++)
	{
		m_nRatx[i]=m_rectClient.left+rand()%(m_rectClient.Width()-m_nRatw);
		m_nRaty[i]=m_rectClient.top+rand()%(m_rectClient.Height()-m_nRath);
		m_rectRat[i]=CRect(m_nRatx[i],m_nRaty[i],m_nRatx[i]+m_nRatw,m_nRaty[i]+m_nRath);
		m_nRatDirection[i]=rand()%4;
		m_bRatLive[i]=TRUE;
	}/*FOR*/
	//初始难度设为中
	m_nDifficulty=1;
	m_timeWork=m_timeSet=20;//游戏时间20秒
	m_nCatSpeed=5;
	m_nRatSpeed=3;
	m_nWinFlag=-1;

}

CCatCatchRatView::~CCatCatchRatView()
{
}

BOOL CCatCatchRatView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCatCatchRatView drawing

void CCatCatchRatView::OnDraw(CDC* pDC)
{
	CCatCatchRatDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->Rectangle(CRect(19,19,381,381));
	//显示游戏状态
	CString strTime;
	CString strRat;
	strTime.Format("剩余时间: %2d:%2d:%2d",m_timeWork.GetHours(),m_timeWork.GetMinutes(),m_timeWork.GetSeconds());
	strRat.Format("待抓老鼠:%3d",m_nRat);
	pDC->TextOut(410,100,strTime);
	pDC->TextOut(410,140,strRat);
	//显示猫和老鼠
	CDC memDC[RATMAX];
	CDC memCatDC;
	CBitmap *pOldDC;
	memCatDC.CreateCompatibleDC(NULL);
	pOldDC=memCatDC.SelectObject(&m_bmCat[m_nCatDirection]);
	pDC->BitBlt(m_nCatx,m_nCaty,m_nCatw,m_nCath,&memCatDC,0,0,SRCAND);
	memCatDC.SelectObject(pOldDC);
	
	//CRect r;
	//r.left=m_nCatx;r.top=m_nCaty;r.right=r.left+m_nCatw;r.bottom=r.top+m_nCath;
	//DrawTransparentBitmap(pDC,m_bmCat[m_nCatDirection],r,RGB(255,255,255));

	for(int i=0;i<RATMAX;i++)
	{
		if(m_bRatLive[i])
		{
			memDC[i].CreateCompatibleDC(NULL);
			pOldDC=memDC[i].SelectObject(&m_bmRat[m_nRatDirection[i]]);
			pDC->BitBlt(m_nRatx[i],m_nRaty[i],m_nRatw,m_nRath,&memDC[i],0,0,SRCAND);
			memDC[i].SelectObject(pOldDC);
		}/*if*/
	}/*for*/
	//游戏结束
	if(StartFlag==2)
	{
		pDC->TextOut(50,50,"Game Over!");
		if(m_nWinFlag==0)
		{
			pDC->TextOut(50,100,"猫获胜!");
		}/*if*/
		if(m_nWinFlag==1)
		{
			pDC->TextOut(50,100,"老鼠获胜!");
		}/*if*/
		m_nWinFlag=-1;
	}/*if*/
	
}
	
/////////////////////////////////////////////////////////////////////////////
// CCatCatchRatView drawing funtions
void CCatCatchRatView::DrawTransparentBitmap(CDC *pDC,CBitmap &Image,
											 CRect &rect, COLORREF rgbMask)
{
	CDC ImageDC,MaskDC;
	CBitmap *pOldImage;
	CBitmap maskBitmap,*pOldMaskDCBitmap ;
	
	//Image.LoadBitmap(IDImage);
	ImageDC.CreateCompatibleDC(pDC);
	pOldImage=ImageDC.SelectObject(&Image);
	MaskDC.CreateCompatibleDC(pDC);
	maskBitmap.CreateBitmap( rect.Width(), rect.Height(), 1, 1, NULL );
	pOldMaskDCBitmap = MaskDC.SelectObject( &maskBitmap );
	ImageDC.SetBkColor(rgbMask);
	MaskDC.BitBlt(0,0, rect.Width(), rect.Height(), &ImageDC, 0, 0, SRCCOPY );

	ImageDC.SetBkColor(RGB(255,255,255));
	ImageDC.SetTextColor(RGB(0,0,0));
	ImageDC.BitBlt(0,0, rect.Width(), rect.Height(), &MaskDC, 0, 0, SRCAND);
	pDC->BitBlt(rect.left,rect.top,rect.Width(), rect.Height(), &MaskDC, 0, 0, SRCAND);
	pDC->BitBlt(rect.left,rect.top,rect.Width(), rect.Height(), &ImageDC, 0, 0,SRCPAINT);
	MaskDC.SelectObject(pOldMaskDCBitmap);
	ImageDC.SelectObject(pOldImage);

}
/////////////////////////////////////////////////////////////////////////////
// CCatCatchRatView printing

BOOL CCatCatchRatView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCatCatchRatView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCatCatchRatView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCatCatchRatView diagnostics

#ifdef _DEBUG
void CCatCatchRatView::AssertValid() const
{
	CView::AssertValid();
}

void CCatCatchRatView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCatCatchRatDoc* CCatCatchRatView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCatCatchRatDoc)));
	return (CCatCatchRatDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCatCatchRatView message handlers

void CCatCatchRatView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	if(m_nRat>0)
	{
		//有老鼠未被抓住
		srand((unsigned)time(NULL));
		for(int i=0;i<RATMAX;i++)
		{
			if(m_bRatLive[i])
			{
				//对未被抓住的老鼠进行处理
				switch(nIDEvent)
				{
					case 2://该变老鼠运动方向
						m_nRatDirection[i]=rand()%4;
						break;
					case 1: //改变老鼠位置
						InvalidateRect(m_rectRat[i]);
						int nRatMoveStep=m_nRatSpeed+rand()%5;//老鼠移动的距离
						if((abs(m_nRatx[i]-m_nCatx)<3*m_nRatw) 
									&& (abs(m_nRaty[i]-m_nCaty)<3*m_nRath))
						{	//如果老鼠靠近了猫就改变方向
							m_nRatDirection[i]=rand()%4;
						}/*if*/
						switch(m_nRatDirection[i])
						{
							case 0:  //向上移动
								if(m_rectRat[i].top-nRatMoveStep>m_rectClient.top)
								{
									m_rectRat[i].top-=nRatMoveStep;
									m_rectRat[i].bottom-=nRatMoveStep;
									m_nRaty[i]-=nRatMoveStep;
								}/*if*/
								else
								{//运动到边界侧改变方向
									m_nRatDirection[i]=rand()%4;
								}/*else*/ 
								break;

							case 1:  //向下移动
								if(m_rectRat[i].bottom+nRatMoveStep<m_rectClient.bottom)
								{
									m_rectRat[i].top+=nRatMoveStep;
									m_rectRat[i].bottom+=nRatMoveStep;
									m_nRaty[i]+=nRatMoveStep;
								}/*if*/
								else
								{//运动到边界侧改变方向
									m_nRatDirection[i]=rand()%4;
								}/*else*/ 
								break;
							case 2:  //向左移动
								if(m_rectRat[i].left-nRatMoveStep>m_rectClient.left)
								{
									m_rectRat[i].left-=nRatMoveStep;
									m_rectRat[i].right-=nRatMoveStep;
									m_nRatx[i]-=nRatMoveStep;
								}/*if*/
								else
								{//运动到边界侧改变方向
									m_nRatDirection[i]=rand()%4;
								}/*else*/ 
								break;
							case 3:  //向右移动
								if(m_rectRat[i].right+nRatMoveStep<m_rectClient.right)
								{
									m_rectRat[i].left+=nRatMoveStep;
									m_rectRat[i].right+=nRatMoveStep;
									m_nRatx[i]+=nRatMoveStep;
								}/*if*/
								else
								{//运动到边界侧改变方向
									m_nRatDirection[i]=rand()%4;
								}/*else*/ 
								break;
						}/*swicth*/
				}/*switch*/
				//判断运动后是否被猫抓住
				if((abs(m_nRatx[i]-m_nCatx)<m_nRatw) && (abs(m_nRaty[i]-m_nCaty)<m_nRath))
				{
					m_nRat--;
					m_bRatLive[i]=false;
				}/*if*/
				InvalidateRect(m_rectRat[i]);
			}/*if*/
		}/*for*/
	
		//计算游戏剩余时间
		m_timeEnd=m_timeEnd.GetCurrentTime();
		m_timeWork=m_timeSet-(m_timeEnd-m_timeStart);
		InvalidateRect(CRect(410,100,560,160));
		if(!(m_timeWork.GetTotalSeconds()))
		{
			KillTimer(1);
			KillTimer(2);
			StartFlag=2;
			if(m_nRat>0)
			{
				//游戏时间以到，老鼠还没抓完，失败
				m_nWinFlag=1;
				//MessageBox("猫高一尺，鼠高一丈!");
			}/*if*/
			else
			{
				//游戏时间未到，老鼠已经抓完，成功
				m_nWinFlag=0;
				//MessageBox("鼠高一尺，猫高一丈!");
			}/*else*/
			Invalidate();
		}/*if*/
	}/*if*/
	else if(m_timeWork.GetTotalSeconds())
	{
		KillTimer(1);
		KillTimer(2);
		StartFlag=2;
		Invalidate();
		m_nWinFlag=0;
		//MessageBox("鼠高一尺，猫高一丈!");
	}/*else if*/
	
	CView::OnTimer(nIDEvent);
}

void CCatCatchRatView::OnRestart() 
{
	// TODO: Add your command handler code here
	//重新开始游戏的初始化工作，设置初始参数
	StartFlag=-1;
	m_nRat=RATMAX;
	m_timeWork=m_timeSet;
	m_nCatDirection=2;
	
	//计算猫和老鼠位图的初时位置和运动方向
	m_nCatx=m_rectClient.left+m_rectClient.Width()/2;
	m_nCaty=m_rectClient.top+m_rectClient.Height()/2;
	m_rectCat=CRect(m_nCatx,m_nCaty,m_nCatx+m_nCatw,m_nCaty+m_nCath);
	srand((unsigned)time(NULL));
	for(int i=0;i<RATMAX;i++)
	{
		m_nRatx[i]=m_rectClient.left+rand()%(m_rectClient.Width()-m_nRatw);
		m_nRaty[i]=m_rectClient.top+rand()%(m_rectClient.Height()-m_nRath);
		m_rectRat[i]=CRect(m_nRatx[i],m_nRaty[i],m_nRatx[i]+m_nRatw,m_nRaty[i]+m_nRath);
		m_nRatDirection[i]=rand()%4;
		m_bRatLive[i]=TRUE;
	}/*FOR*/
	Invalidate();

}

void CCatCatchRatView::OnStart() 
{
	// TODO: Add your command handler code here
	if(StartFlag)
	{
		m_timeStart=m_timeStart.GetCurrentTime();
	}/*if*/
	SetTimer(1,100,NULL);
	SetTimer(2,8000,NULL);
	StartFlag=1;

}

void CCatCatchRatView::OnStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	KillTimer(2);
	StartFlag=0;
}

void CCatCatchRatView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(StartFlag==1)
	{
		//游戏开始时猫才可以移动
		InvalidateRect(m_rectCat,TRUE);
		switch(nChar)
		{
			case VK_UP:   //向上移动
				if(m_rectCat.top-m_nCatSpeed>m_rectClient.top)
				{
					m_rectCat.top-=m_nCatSpeed;
					m_rectCat.bottom-=m_nCatSpeed;
					m_nCaty-=m_nCatSpeed;
					m_nCatDirection=0;
				}/*if*/
				break;
			case VK_DOWN:   //向下移动
				if(m_rectCat.bottom-m_nCatSpeed<m_rectClient.bottom)
				{
					m_rectCat.top+=m_nCatSpeed;
					m_rectCat.bottom+=m_nCatSpeed;
					m_nCaty+=m_nCatSpeed;
					m_nCatDirection=1;
				}/*if*/
				break;
			case VK_LEFT:   //向左移动
				if(m_rectCat.left-m_nCatSpeed>m_rectClient.left)
				{
					m_rectCat.left-=m_nCatSpeed;
					m_rectCat.right-=m_nCatSpeed;
					m_nCatx-=m_nCatSpeed;
					m_nCatDirection=2;
				}/*if*/
				break;
			case VK_RIGHT:   //向右移动
				if(m_rectCat.right+m_nCatSpeed<m_rectClient.right)
				{
					m_rectCat.left+=m_nCatSpeed;
					m_rectCat.right+=m_nCatSpeed;
					m_nCatx+=m_nCatSpeed;
					m_nCatDirection=3;
				}/*if*/
				break;
		}/*switch*/
		InvalidateRect(m_rectCat,FALSE);
		//判断猫的移动后是否抓住老鼠
		for(int i=0; i<RATMAX; i++)
		{
			if(m_bRatLive[i] && (abs(m_nRatx[i]-m_nCatx)<m_nRatw) && (abs(m_nRaty[i]-m_nCaty)<m_nRath))
			{
				m_bRatLive[i]=FALSE;
				m_nRat--;
				InvalidateRect(m_rectRat[i]);
				InvalidateRect(CRect(410,100,560,160));
			}/*if*/
		}/*for*/
	}/*if*/

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CCatCatchRatView::OnUpdateStop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//游戏过程中可以选停止菜单
	pCmdUI->Enable(StartFlag==1);
}

void CCatCatchRatView::OnSelect() 
{
	// TODO: Add your command handler code here
	CSelectDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_nDifficulty=dlg.m_nDifficulty;
		switch(m_nDifficulty)
		{
			case 2:
				m_nCatSpeed=8;
				m_nRatSpeed=2;
				m_timeSet=40;
				break;
			case 1:
				m_nCatSpeed=5;
				m_nRatSpeed=3;
				m_timeSet=20;
				break;
			case 0:
				m_nCatSpeed=6;
				m_nRatSpeed=8;
				m_timeSet=10;
				break;
			default:
				AfxMessageBox("Difficulty select error!");
		}/*switch*/

	}/*if*/
}

void CCatCatchRatView::OnUpdateStart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(StartFlag<1);
}
