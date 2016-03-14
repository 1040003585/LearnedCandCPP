// CGamePlatform.cpp : implementation of the CGamePlatform class
// Download by http://www.NewXing.com

#include "stdafx.h"
#include "Diamond.h"

#include "CGamePlatform.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define CUBEWIDTH 20
#define BOUNDARY_WIDTH  6
#define BOUNDARY_HEIGHT 60
/////////////////////////////////////////////////////////////////////////////
// CGamePlatform

IMPLEMENT_DYNAMIC(CGamePlatform, CFrameWnd)

BEGIN_MESSAGE_MAP(CGamePlatform, CFrameWnd)
	//{{AFX_MSG_MAP(CGamePlatform)
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
    ON_WM_PAINT()
	ON_WM_KEYUP()
	ON_WM_CREATE()
	ON_WM_NCHITTEST()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_GAMECONTROL, OnGameCtrlClick)
    ON_BN_CLICKED(IDC_GAMEMINIMIZE, CFrameWnd::CloseWindow)
    ON_BN_CLICKED(IDC_GAMEEXIT, CFrameWnd::OnClose)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGamePlatform construction/destruction

CGamePlatform::CGamePlatform()
{
	Create(NULL,_T("Diamond"),WS_OVERLAPPEDWINDOW,CRect(400,80,855,679));
	m_bitmapBgnd.LoadBitmap(IDB_BACKGROUND);
	m_dcMem.CreateCompatibleDC(GetDC());
	m_dcMem.SelectObject(&m_bitmapBgnd);
	int Cx = BOUNDARY_WIDTH  + CUBEWIDTH * GAME_ZONE_WIDTH;
	int Cy = BOUNDARY_HEIGHT + CUBEWIDTH * GAME_ZONE_HEIGHT;
	CRect ControlRect( Cx + CUBEWIDTH * 2 - 10,Cy - 20, Cx  + CUBEWIDTH * 4 + 19,Cy + 10);					     
	m_wndGameControl.Create("Start",BS_OWNERDRAW|WS_TABSTOP|WS_VISIBLE,ControlRect,this,IDC_GAMECONTROL);
 	m_wndGameControl.m_strCaption = "Start";
	m_wndGameControl.SetBitmap(IDB_BTCONTROL);
	m_wndGameControl.SetBKDC(&m_dcMem);
   	CRect MinimizeRect(275,20, 295 , 40);
 	CRect ExitRect(310 ,25, 335,35);
	m_wndGameExit.Create("",BS_OWNERDRAW|WS_TABSTOP|WS_VISIBLE,ExitRect,this,IDC_GAMEEXIT);
    m_wndGameExit.SetBitmap(IDB_BTCLOASE);
	m_wndGameExit.SetBKDC(&m_dcMem);
	m_wndGameMinimize.SetBitmap(IDB_BTMIN);
 	m_wndGameMinimize.SetBKDC(&m_dcMem);
	m_wndGameMinimize.Create("",BS_OWNERDRAW|WS_TABSTOP|WS_VISIBLE,MinimizeRect,this,IDC_GAMEMINIMIZE);
      SetIcon(::LoadIcon(AfxGetApp()->m_hInstance,(LPCSTR)(IDI_MAINFRAME)),TRUE);
	InitialGame();
	m_vtGameZone.resize(GAME_ZONE_HEIGHT);
	for(int i = 0; i < GAME_ZONE_HEIGHT;i++)
		m_vtGameZone[i].resize(GAME_ZONE_WIDTH,false);
}

CGamePlatform::~CGamePlatform()
{
}

BOOL CGamePlatform::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CGamePlatform diagnostics

#ifdef _DEBUG
void CGamePlatform::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CGamePlatform::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG
 

BOOL CGamePlatform::OnEraseBkgnd(CDC* pDC) 
{
    CRect rtClient;
	GetClientRect(&rtClient);
	pDC->BitBlt(0,0,rtClient.Width(),rtClient.Height(),&m_dcMem,0,0,SRCCOPY);
	return TRUE;
}
 
bool CGamePlatform::CollisionCheck(DIAMOND diamond, int nPosX, int nPosY)
{
	for(int i = 0; i < diamond.Pos.size(); i ++)
	{
		CPoint pt = DiamondControl.CalcIndex(diamond.Pos[i]);
    	if(pt.x + nPosX <  0 || pt.x + nPosX >= GAME_ZONE_WIDTH ||
		   pt.y + nPosY <  0 || pt.y + nPosY >= GAME_ZONE_HEIGHT)
		    return true;
	    if(m_vtGameZone[pt.y + nPosY][pt.x + nPosX]) 
		   return true;
	}
	return false;
}

void CGamePlatform::FillGameZone(DIAMOND curDiamond)
{
	for(int i = 0; i < curDiamond.Pos.size(); i ++)
	{
		CPoint pt = DiamondControl.CalcIndex(curDiamond.Pos[i]);
		m_vtGameZone[pt.y + curDiamond.nPosY][pt.x +  curDiamond.nPosX] = 1; 
				if(pt.y +  curDiamond.nPosY < m_nDiamondHeight)
					m_nDiamondHeight = pt.y + curDiamond.nPosY;
	}
}
void CGamePlatform::InitialGame()
{
	m_nGameState = GAME_END;
	m_nGameLevel = 0;
	m_nGameScore = 0;
	m_bAccelerateFlag = false;
  	m_vtGameZone.assign(GAME_ZONE_HEIGHT,std::vector<bool>(GAME_ZONE_HEIGHT,false));
	m_nDiamondHeight = GAME_ZONE_HEIGHT;
}
 

void CGamePlatform::OnTimer(UINT nIDEvent) 
{
	switch(m_nGameState) {
		case GAME_START:   GameOnStartStateDeal(); break;
		case GAME_RUN:     GameOnRunStateDeal();   break;
	}
}

void CGamePlatform::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if(m_nGameState == GAME_RUN)
	{
		switch(nChar){
			case VK_LEFT:	OnLeftKeyPressedDeal();	 break;
			case VK_RIGHT:	OnRightKeyPressedDeal(); break;
			case VK_UP:		OnUpKeyPressedDeal();	 break;
			case VK_DOWN:	OnDownKeyPressedDeal();	 break;
			default: break;
		}
	}
}

void CGamePlatform::DrawDiamond(DIAMOND diamond,bool bFlag)
{
	for(int i = 0; i < diamond.Pos.size(); i ++)
	{
		CPoint pt = DiamondControl.CalcIndex(diamond.Pos[i]);
		DrawCube(pt.x + diamond.nPosX ,pt.y + diamond.nPosY,bFlag);
	}

}

void CGamePlatform::DrawCube(int nCx, int nCy, bool bFlag)
{
	     
	  CRect rtCube(BOUNDARY_WIDTH + nCx * CUBEWIDTH,BOUNDARY_HEIGHT + nCy * CUBEWIDTH,
			  	   BOUNDARY_WIDTH + (nCx + 1) * CUBEWIDTH, BOUNDARY_HEIGHT + (nCy + 1) * CUBEWIDTH);
	  CDC *pDC = GetDC( );
	  switch(bFlag) {
	  case true: {
					pDC->Draw3dRect(&rtCube,RGB(255,232,233),RGB(128,128,128));
					rtCube.DeflateRect(1,1,1,1);
	  				pDC->Draw3dRect(&rtCube,RGB(255,232,233),RGB(128,128,128));
			 	    CFont font;
	                CPen Pen(PS_DASHDOT,1,RGB(255,255,255));
	                font.CreatePointFont (80, _T ("Webdings"));
					CPen *pOldPen =  pDC->SelectObject(&Pen);
	                CFont *pOldFont = pDC->SelectObject(&font);
  	                pDC->SetBkMode(TRANSPARENT);
	                pDC->SetTextColor(RGB(255,255,255));
                 	CString Str;
					Str.Format("%c",'0' + rand()%56);
					pDC->DrawText(Str,&rtCube,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
					pDC->SelectObject(pOldPen);
					pDC->SelectObject(pOldFont);
				 }
		  break;
	  case false:
		  pDC->BitBlt(rtCube.left,rtCube.top,rtCube.Width(),rtCube.Height(),
			  &m_dcMem,rtCube.left,rtCube.top,SRCCOPY);
		 break;
	  }
	  ReleaseDC(pDC);
}
void CGamePlatform::OnGameCtrlClick()
{
	if(m_nGameState == GAME_END)
	{
		InitialGame();
		m_nGameState = GAME_START;
		SetTimer(IDT_GAMETIMER,500 - m_nGameLevel* 50,NULL);
	 	m_wndGameControl.SetCaption("Pause");
  		OnPaint();
	}
	else if(m_nGameState == GAME_RUN)
	{
		m_nGameState = GAME_PAUSE;
		m_wndGameControl.SetCaption("Run");
	}
	else if(m_nGameState == GAME_PAUSE)
	{
		m_nGameState = GAME_RUN;
		m_wndGameControl.SetCaption("Pause");
 	}
	SetFocus();
}

void CGamePlatform::GameOnRunStateDeal()
{
	if(m_nDiamondHeight < 3) {
		m_nGameState = GAME_IDLE;
 	    m_wndGameControl.SetCaption("Start");
	 	m_wndGameControl.SendMessage(WM_LBUTTONDOWN,0,0);
        m_wndGameControl.SendMessage(WM_LBUTTONUP,0,0);
		m_nGameState = GAME_END;

	}
	else {
			int nPosX = DiamondControl.GetCurDiamond().nPosX;
	    	int nPosY = DiamondControl.GetCurDiamond().nPosY;
            if(!CollisionCheck(DiamondControl.GetCurDiamond(),nPosX,nPosY + 1)){
				    DrawDiamond(DiamondControl.GetCurDiamond(),false);
			 	    DiamondControl.SetCurrentDiamondPos(nPosX,nPosY + 1);
					DrawDiamond(DiamondControl.GetCurDiamond(),true);
			}
			else {
				    FillGameZone(DiamondControl.GetCurDiamond());
					DealCollisionResult();
					DrawAchievement();
					CDC *pDC = GetDC();
 					DiamondControl.CreateDiamond();
					DIAMOND nextdiamond = DiamondControl.GetNextDiamond();
					nextdiamond.nPosX = GAME_ZONE_WIDTH + 1;
					nextdiamond.nPosY = GAME_ZONE_HEIGHT/2 - 2;
					FillRectangle(GAME_ZONE_WIDTH + 1,GAME_ZONE_HEIGHT/2 - 2,4,4);
					DrawDiamond(nextdiamond,1);
				}
	}
}

void CGamePlatform::GameOnStartStateDeal()
{
    DiamondControl.CreateDiamond();
	m_nGameState = GAME_RUN;
	FillRectangle(0,0,GAME_ZONE_WIDTH,GAME_ZONE_HEIGHT);
	DrawDiamond(DiamondControl.GetCurDiamond(),1);
	DIAMOND nextdiamond = DiamondControl.GetNextDiamond();
    nextdiamond.nPosX = GAME_ZONE_WIDTH + 1;
	nextdiamond.nPosY = GAME_ZONE_HEIGHT/2 - 2;
	FillRectangle(GAME_ZONE_WIDTH + 1,GAME_ZONE_HEIGHT/2 - 2,4,4);
	DrawDiamond(nextdiamond,1);
}

void CGamePlatform::OnLeftKeyPressedDeal()
{
	int nPosX = DiamondControl.GetCurDiamond().nPosX;
	int nPosY = DiamondControl.GetCurDiamond().nPosY;
	if(!CollisionCheck(DiamondControl.GetCurDiamond(),nPosX - 1,nPosY)){
	    DrawDiamond(DiamondControl.GetCurDiamond(),false);
 	    DiamondControl.SetCurrentDiamondPos(nPosX - 1,nPosY);
		DrawDiamond(DiamondControl.GetCurDiamond(),true);
	}
}

void CGamePlatform::OnRightKeyPressedDeal()
{
	int nPosX = DiamondControl.GetCurDiamond().nPosX;
	int nPosY = DiamondControl.GetCurDiamond().nPosY;
 	if(!CollisionCheck(DiamondControl.GetCurDiamond(),nPosX + 1,nPosY)){
	    DrawDiamond(DiamondControl.GetCurDiamond(),false);
 	    DiamondControl.SetCurrentDiamondPos(nPosX + 1,nPosY);
		DrawDiamond(DiamondControl.GetCurDiamond(),true);
	}
}

void CGamePlatform::OnUpKeyPressedDeal()
{
	DIAMOND tempDiamond = DiamondControl.ChangePos(DiamondControl.GetCurDiamond());
	if(!CollisionCheck(tempDiamond,tempDiamond.nPosX,tempDiamond.nPosY))
	{
		this->DrawDiamond(DiamondControl.GetCurDiamond(),0);
		DiamondControl.SetCurDiamond(tempDiamond);
		this->DrawDiamond(DiamondControl.GetCurDiamond(),1);
	}
}

void CGamePlatform::OnDownKeyPressedDeal()
{
	if(!m_bAccelerateFlag) {
		SetTimer(IDT_GAMETIMER,50,NULL);
		m_bAccelerateFlag = true;
	}
}

void CGamePlatform::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
  
 	CRect GameZoneRect(BOUNDARY_WIDTH,BOUNDARY_HEIGHT,
		BOUNDARY_WIDTH + CUBEWIDTH * GAME_ZONE_WIDTH,
		BOUNDARY_HEIGHT + CUBEWIDTH * GAME_ZONE_HEIGHT);
	GameZoneRect.DeflateRect(-5,-5,-5,-5);
	dc.Draw3dRect(&GameZoneRect,RGB(255,232,233),RGB(128,128,128));
    GameZoneRect.DeflateRect(1,1,1,1);
	dc.Draw3dRect(&GameZoneRect,RGB(255,232,233),RGB(128,128,128));

	CRect rt;
	GetClientRect(&rt);
	CRect NextDiamondRect(BOUNDARY_WIDTH + CUBEWIDTH * GAME_ZONE_WIDTH + 5, BOUNDARY_HEIGHT - 5,
		 rt.right-1,rt.bottom -1);
	GameZoneRect.DeflateRect(-5,-5,-5,-5);
	dc.Draw3dRect(&NextDiamondRect,RGB(255,232,233),RGB(128,128,128));
    NextDiamondRect.DeflateRect(1,1,1,1);
	dc.Draw3dRect(&NextDiamondRect,RGB(255,232,233),RGB(128,128,128));

 	DrawAchievement();
	ReDrawTheCube(GAME_ZONE_HEIGHT - 1);

   
	//Redraw the NextDiamond;
	DIAMOND nextdiamond = DiamondControl.GetNextDiamond();
	nextdiamond.nPosX = GAME_ZONE_WIDTH + 1;
	nextdiamond.nPosY = GAME_ZONE_HEIGHT/2 - 2;
	FillRectangle(GAME_ZONE_WIDTH + 1,GAME_ZONE_HEIGHT/2 - 2,4,4);
	DrawDiamond(nextdiamond,1);
// Do not call CFrameWnd::OnPaint() for painting messages
	if(m_nGameState == GAME_PAUSE) {
		DrawDiamond(DiamondControl.GetCurDiamond(),1);
	}
}

void CGamePlatform::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	SetTimer(IDT_GAMETIMER,500 - m_nGameLevel*50,NULL);
	m_bAccelerateFlag = false;
}

void CGamePlatform::FillRectangle(int nCx, int nCy, int nWidth, int nHeight)
{
	CRect rtFillArea(BOUNDARY_WIDTH + nCx * CUBEWIDTH,BOUNDARY_HEIGHT + nCy * CUBEWIDTH,
		BOUNDARY_WIDTH + (nCx + nWidth)* CUBEWIDTH,BOUNDARY_HEIGHT+(nCy + nHeight) * CUBEWIDTH);
	CDC * pDC =GetDC();
	pDC->BitBlt(rtFillArea.left,rtFillArea.top,rtFillArea.Width(),rtFillArea.Height(),&m_dcMem,rtFillArea.left,rtFillArea.top,SRCCOPY);
}

void CGamePlatform::DealCollisionResult()
{
	int nPosY = DiamondControl.GetCurDiamond().nPosY;
	int nLineNum = 0;
	for(int i = nPosY; i < nPosY + 4; i ++){
 		if(CheckFillUpOrNot(i))	{
			SpecialEffort(i);
	        FillRectangle(0,m_nDiamondHeight,GAME_ZONE_WIDTH,i - m_nDiamondHeight + 1);
			MoveOneLine(i);
			ReDrawTheCube(i);
			nLineNum++;
		}
	}
	m_nGameScore += (nLineNum * 100);
	m_nGameLevel = m_nGameScore / 5000;
}

bool CGamePlatform::CheckFillUpOrNot(int nLineNum)
{
	if(nLineNum < 0 || nLineNum >= GAME_ZONE_HEIGHT)
		return false;
	for(int i = 0; i < GAME_ZONE_WIDTH; i ++){
		if(!m_vtGameZone[nLineNum][i])		
			return false;
		}
 	return true;
}

void CGamePlatform::MoveOneLine(int nLineNum)
{
	if(nLineNum >= 0 && nLineNum < GAME_ZONE_HEIGHT){
		for(int i = nLineNum - 1; i >= m_nDiamondHeight; i --)
			m_vtGameZone[i + 1] = m_vtGameZone[i];
		for(int j = 0; j < GAME_ZONE_WIDTH; j ++)
			m_vtGameZone[m_nDiamondHeight][j] = false;
		m_nDiamondHeight ++;
	}
}

void CGamePlatform::ReDrawTheCube(int nStartNum)
{
	for(int i = nStartNum; i >= m_nDiamondHeight; i--){
		for(int j = 0; j < GAME_ZONE_WIDTH; j ++)
			if(m_vtGameZone[i][j])
			DrawCube(j,i,1);
	}
}

void CGamePlatform::DrawAchievement()
{
	CRect AchievementRect(2, BOUNDARY_HEIGHT + CUBEWIDTH * (GAME_ZONE_HEIGHT) + 6,
							BOUNDARY_WIDTH  +  CUBEWIDTH * GAME_ZONE_WIDTH + 2,
							BOUNDARY_HEIGHT +  CUBEWIDTH * (GAME_ZONE_HEIGHT + 4));

	CDC * pDC = GetDC();
 	pDC->SetTextColor(RGB(255,232,233));
	CString string;
	string.Format("Score: %d   Level:%d",m_nGameScore,m_nGameLevel);
	CFont TextFont;
	TextFont.CreatePointFont (280, _T ("Birch Std"));
	pDC->SelectObject(&TextFont);
	pDC->SetBkMode(TRANSPARENT);
	pDC->BitBlt(AchievementRect.left,AchievementRect.top,AchievementRect.Width(),
		AchievementRect.Height(),&m_dcMem,AchievementRect.left,AchievementRect.top,SRCCOPY);
	pDC->DrawText(string,&AchievementRect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
	ReleaseDC(pDC);
}

void CGamePlatform::SpecialEffort(int nLineNum)
{
 	 CDC * pDC  = GetDC();
	 CPen Pen(PS_DASHDOT,2,RGB(240,240,255));
     CPen *pOldPen = pDC->SelectObject(&Pen);

	for(int i = 0; i < GAME_ZONE_WIDTH; i ++) 
	{
		CRect CubeRect(BOUNDARY_WIDTH + i * CUBEWIDTH,BOUNDARY_HEIGHT + nLineNum * CUBEWIDTH,
			BOUNDARY_WIDTH + (i + 1 )* CUBEWIDTH,BOUNDARY_HEIGHT + (nLineNum +1) * CUBEWIDTH);
		CubeRect.DeflateRect(2,2,2,2);
		for(int j = 0; j < 10; j ++ )
		{
	 		int ncxS = rand()% (CubeRect.Width());
			int ncyS = rand()% (CubeRect.Height());
			int ncxE = rand()% (CubeRect.Width());
			int ncyE = rand()% (CubeRect.Height());
			pDC->MoveTo(CubeRect.left + ncxS,CubeRect.top + ncyS);
			pDC->LineTo(CubeRect.left + ncxE,CubeRect.top + ncyE);
	 	}
		Sleep(10);
	}
   	   pDC->SelectObject(pOldPen);
	   ReleaseDC(pDC);
}

int CGamePlatform::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	ModifyStyle(WS_CAPTION,0);
 	SetWindowPos(NULL,400,80,380,505,0);
 	return 0;
}

UINT CGamePlatform::OnNcHitTest(CPoint point) 
{
	   UINT nHitTest = CFrameWnd::OnNcHitTest (point);
       nHitTest = HTCAPTION;

	return nHitTest;
}

void CGamePlatform::BitmapToRegion()
{
	CDC *pDC = GetDC();
	BITMAP  bmInfo;
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BACKGROUND);
	bitmap.GetObject(sizeof(bmInfo),&bmInfo);
	CRect RectRgn(0,0,bmInfo.bmWidth,bmInfo.bmHeight);
 	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);
	dcMem.SelectObject(&bitmap);
	
	CRgn bmpRGN;
 	bmpRGN.CreateRectRgn(0,0,RectRgn.Width(),RectRgn.Height());
 	CRgn tempRgn;
	for(int i = 0; i < bmInfo.bmWidth; i ++)
		for(int j = 0; j < bmInfo.bmHeight; j++)
		{
			if(dcMem.GetPixel(i,j) == RGB(0,0,0))
			{
				tempRgn.CreateRectRgn(i,j,i+1,j+1);
				bmpRGN.CombineRgn(&bmpRGN,&tempRgn,RGN_XOR);
				tempRgn.DeleteObject();
			}
		}
    SetWindowRgn(bmpRGN,true);
 	ReleaseDC(pDC);
}
