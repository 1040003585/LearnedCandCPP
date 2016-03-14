// Tank1Dlg.cpp : implementation file
// Download by http://www.NewXing.com

#include "stdafx.h"
#include "Tank1.h"
#include "Tank1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
// CAboutDlg dialog used for App About
CString cc;//临时数据
short int m_show=0;//画面显示


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTank1Dlg dialog

CTank1Dlg::CTank1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTank1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTank1Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTank1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTank1Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTank1Dlg, CDialog)
	//{{AFX_MSG_MAP(CTank1Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTank1Dlg message handlers

BOOL CTank1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
//	this->ShowWindow(false);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	


	//////////////进入游戏///////////////
	/***********************************/
	rBlend.BlendOp = AC_SRC_OVER;	//
	rBlend.BlendFlags = 0;			//
	rBlend.AlphaFormat = 0;			//
	rBlend.SourceConstantAlpha=255;//半透明
	mygame.door=0;//第0关
	CRect rect;
	GetWindowRect(rect);
	MoveWindow(rect.left,rect.top,WIDTH,HEIGHT);

	mygame.over=1;//未开始游戏
	mygame.pause=1;
	//sndPlaySound("sound/loading.wav",SND_ASYNC);
	m_show=0;
	SetTimer(2,Timer,NULL);

	if (mygame.initDX()==FALSE)
		AfxMessageBox("DirectX初始化失败！");
	mygame.init("map1.txt");//装载地图

	//读入图片缓存

	mygame.bmpnum=0;
	FILE *f;
	int total=0;
	char f1[256],f2[256];
	CString ff;
	cc="pic/config.dat";
	f=fopen(cc,"r");
	if(f == NULL)
	{
		AfxMessageBox("没有资源数据文件!!!");
		SetCurrentDirectory(mygame.appdir);
		return FALSE;
	}
	fscanf(f,"%d",&total);
	for (int i=0;i<total;i++)
	{
		fscanf(f,"%s %s",f1,f2);
		ff.Format("%s",f1);
		cc.Format("%s",f2);
		mygame.loadbmp2(ff,cc);
	}
	SetCurrentDirectory(mygame.appdir);
	return TRUE;  // return TRUE  unless you set the focus to a control
	
}

void CTank1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTank1Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTank1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTank1Dlg::OnCancel() 
{
	KillTimer(1);
	// TODO: Add extra cleanup here
	if( ::MessageBox(GetSafeHwnd(), "退出程序吗?","请您确定!",
					MB_YESNO|MB_ICONQUESTION|MB_DEFBUTTON2  ) == IDYES )
	{
	mygame.exit();	//退出类
//		for(int i=0;i<8;i++)
//		DeleteDC(mygame.bmp[i]);
	 CDialog::OnCancel();

	}
	SetTimer(1,Timer,NULL);
	
}


void CTank1Dlg::OnTimer(UINT nIDEvent) 
{	CClientDC d(this);
	//HDC dc=CreateDC("DISPLAY",NULL,NULL,NULL);///屏幕设备
	HDC dc=d.m_hDC ;


	if (nIDEvent == 1)//游戏显示
	{
//	 if(MCIWndGetPosition(mygame.hMCI) >=MCIWndGetLength(mygame.hMCI)) MCIWndPlay(mygame.hMCI);//循环背景音乐
		// TODO: Add your message handler code here and/or call default
		BitBlt(mygame.MainDC,0,0,WIDTH,HEIGHT,mygame.Back,0,0,SRCCOPY);//背景,刷新地图
		//BitBlt(dc.m_hDC,10,10,100,100,mygame.MemDC,0,0,SRCCOPY);
		//BitBlt(dc.m_hDC,0,0,mygame.w,mygame.h,MDC,0,0,SRCCOPY);
		
		for (int i=0;i<mygame.num;i++)
			if(mygame.man[i].over==1&&mygame.man[i].p==mygame.man[i].m1)
			{	mygame.Delete(i);
				i--;
			}
			mygame.gtime++;//游戏时间
			if(mygame.gtime==80)
			for(int ii=0;ii<mygame.num;ii++)
				if(mygame.man[ii].lb==1)
					mygame.man[ii].z=0;

		mygame.sort();//排序
		for ( i=0;i<mygame.num;i++)
			mygame.setobj(i);
		cc.Format("游戏时间：%d秒 物体总数:%d",mygame.gtime/10,mygame.num);
		TextOut(mygame.MainDC,0,580,cc,lstrlen(cc));
		//mygame.DXSPrimary->GetDC(&mygame.MainDC);
		BitBlt(dc,0,0,WIDTH,HEIGHT,mygame.MainDC,0,0,SRCCOPY);//拷贝主场景
		//mygame.DXSPrimary->ReleaseDC(mygame.MainDC);
		SetWindowText(mygame.mapname );
	SetBkMode(dc,TRANSPARENT);
	SetTextColor(dc,RGB(255,0,0));
	//**********************判断游戏是否结束
	for(int j=0;j<mygame.num;j++)
	{
		if(mygame.man[j].lb==1&& (mygame.man[j].jixu==mygame.player[0]||mygame.man[j].jixu==mygame.player[1]) )goto on;
	}
	//玩家灭亡
	KillTimer(1);
	mygame.getpic("pic/gameover.bmp");
	StretchBlt(dc,0,0,800,600,mygame.MemDC,0,0,640,480,SRCCOPY);
	cc="按回车键继续...";
	mygame.door=0;

	TextOut(dc,350,330,cc,lstrlen(cc));
			mygame.init("map1.txt");
			mygame.over=1;
			mygame.pause =1;
on:
		for(j=0;j<mygame.num;j++)
		{
			if(mygame.man[j].lb==1&&mygame.man[j].jixu!=mygame.player[0]&&mygame.man[j].jixu!=mygame.player[1])goto on2;
		}//胜利
		cc="过关。。。";
		TextOut(dc,350,330,cc,lstrlen(cc));
		if(mygame.nextmap=="end")
		{	
			cc="Game End!";
			TextOut(dc,350,350,cc,lstrlen(cc));
			KillTimer(1);
			mygame.over=1;
			SetTimer(2,Timer,NULL);
			mygame.init("map1.txt");
			mygame.pause =1;
			mygame.door=0;
		}else
			SetTimer(2,Timer,NULL);
			mygame.init(mygame.nextmap);
			KillTimer(1);
			mygame.over=1;
			mygame.pause =1;
			//mygame.Sound("loading.wav");
		}


	//进入界面
	if(nIDEvent==2)
	{	
		cc="pic/start.bmp";
		mygame.MemDC=CreateCompatibleDC(0);
		HDC hdc;
		hdc=CreateCompatibleDC(0);
		HBITMAP bit = CreateCompatibleBitmap(dc,WIDTH,HEIGHT);
		SelectObject(hdc,bit);
		mygame.getpic(cc);
		::BitBlt(hdc ,0,0,800,600,mygame.MemDC,0,0,SRCCOPY);

		cc="pic/black.bmp";
		mygame.getpic(cc);

		AlphaBlend(hdc ,0,0,800,600,mygame.MemDC,0,0,640,480,rBlend);//半透明处理
		cc.Format("第 %d 关",mygame.door);
		SetTextColor(hdc,RGB(255,0,0));
		SetBkMode(hdc,TRANSPARENT);
		TextOut(hdc,350,330,cc,lstrlen(cc));
		BitBlt(dc,0,0,800,600,hdc,0,0,SRCCOPY);

		if (m_show==0&&rBlend.SourceConstantAlpha>50 )
		{
			rBlend.SourceConstantAlpha-=50;goto on2;

		}else if(m_show==0)
		{
			m_show=1;goto on2;
		}

		if(m_show==1&&rBlend.SourceConstantAlpha<240)
		{
			rBlend.SourceConstantAlpha+=50;goto on2;
		}else if(m_show==1)
		{
			m_show=2;goto on2;
		}
		if (m_show==2)
		{	KillTimer(2);
			mygame.over=0;
			SetTimer(1,Timer,NULL);//设计游戏时钟
			mygame.pause=0;//开始游戏
			m_show=0;
			MCIWndStop(mygame.hMCI);
			mygame.Music("begin.wav");
		}
	}
on2:
	CDialog::OnTimer(nIDEvent);
	

}


BOOL CTank1Dlg::PreTranslateMessage(MSG* lpmsg) //对方向键进行响应.
{
	// TODO: Add your specialized code here and/or call the base class
BOOL bHandleNow = FALSE;
	switch (lpmsg->message)
	{
	case WM_KEYDOWN:
		switch (lpmsg->wParam)
		{
		case VK_UP:
		case VK_DOWN:
		case VK_LEFT:
		case VK_RIGHT:
		bHandleNow = TRUE;
		break;
		} 
		if (bHandleNow) 
			OnKeyDown(lpmsg->wParam, LOWORD(lpmsg ->lParam), HIWORD(lpmsg->lParam)); 
		break; 
	} 
	return bHandleNow; 

}
//************************************************************
//						响应键盘事件:

//************************************************************
void CTank1Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// 响应键盘事件:
	//	游戏控制
	//
	
	switch(nChar)
	{

	case 87:
		mygame.keyup=1;
		break;
	case 83:
		mygame.keydown=1;
		break;
	case 65:
		mygame.keyleft=1;
		break;
	case 68:
		mygame.keyright=1;
		break;
	case 96://0
		mygame.keyspace2=1;
		break;
	case VK_UP:
		mygame.keyup2=1;

		break;
	case VK_DOWN:

		mygame.keydown2=1;

		break;
	case VK_LEFT:
		mygame.keyleft2=1;
		break;

	case VK_RIGHT:
		mygame.keyright2=1;

		break;
	case 74:
		mygame.keyspace=1;
		break;
	case 27:
		OnCancel();
	case 13:
		if(mygame.over==1&&mygame.pause==1)
		{	
			SetTimer(2,Timer,NULL);
		}
		return;
	}

	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

//************************************************************
//						响应键盘事件2:

//************************************************************
void CTank1Dlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// 结束按键
	//按键情况
	switch(nChar)
	{
	case 87:
		mygame.keyup=0;
		break;
	case 83:
		mygame.keydown=0;
		break;
	case 65:
		mygame.keyleft=0;
		break;
	case 68:
		mygame.keyright=0;
		break;
	case 96://0
		mygame.keyspace2=0;
		break;
	case VK_UP:
		mygame.keyup2=0;

		break;
	case VK_DOWN:

		mygame.keydown2=0;

		break;
	case VK_LEFT:
		mygame.keyleft2=0;
		break;

	case VK_RIGHT:
		mygame.keyright2=0;

		break;
	case 74:
		mygame.keyspace=0;
		break;
	}
	
	CDialog::OnKeyUp(nChar, nRepCnt, nFlags);
}
