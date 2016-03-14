// GameView.cpp : implementation of the CGameView class
// Download by http://www.NewXing.com

#include "stdafx.h"
#include "Game.h"
#include "GameDoc.h"
#include "GameView.h"
#include "Leval.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGameView

IMPLEMENT_DYNCREATE(CGameView, CView)

BEGIN_MESSAGE_MAP(CGameView, CView)
	//{{AFX_MSG_MAP(CGameView)
	ON_COMMAND(IDM_GAMESTART, OnGamestart)
	ON_COMMAND(IDM_GAMESTOP, OnGamestop)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_LEVAL, OnLeval)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDC_MUSIC, OnMusic)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGameView construction/destruction
/************************************************************************/
/* �����������ʵ�� ���� ���� ����
/************************************************************************/
CGameView::CGameView()
{
	// TODO: add construction code here
	Score=10;//��ʼ������ֵ
	temp=0;//��ʼ��ʱ���0��ʼ
	//��ʼ�����ݵ�λ��
	pall[0].m_pointPall=CPoint(0,600);
	pall[1].m_pointPall=CPoint(200,600);
	pall[2].m_pointPall=CPoint(600,600);
	pall[3].m_pointPall=CPoint(960,600);
	//��ʼ�������λ��
	boss[0].m_pointBoss=CPoint(200,10);
	boss[1].m_pointBoss=CPoint(20,10);
	boss[2].m_pointBoss=CPoint(20,100);
	boss[3].m_pointBoss=CPoint(600,500);
	//��ʼ��С���λ��
	enemy[0].m_pointEnemy=CPoint(100,20);
	enemy[1].m_pointEnemy=CPoint(400,230);
	enemy[2].m_pointEnemy=CPoint(200,210);
	enemy[3].m_pointEnemy=CPoint(40,50);
	enemy[4].m_pointEnemy=CPoint(16,2);
	enemy[5].m_pointEnemy=CPoint(130,68);
	enemy[6].m_pointEnemy=CPoint(45,40);
	enemy[7].m_pointEnemy=CPoint(10,80);
	enemy[8].m_pointEnemy=CPoint(110,80);
	enemy[9].m_pointEnemy=CPoint(10,800);
	enemy[10].m_pointEnemy=CPoint(10,800);
	enemy[11].m_pointEnemy=CPoint(102,800);
	enemy[12].m_pointEnemy=CPoint(130,800);
	enemy[13].m_pointEnemy=CPoint(10,1800);
	enemy[14].m_pointEnemy=CPoint(10,800);
	enemy[14].m_pointEnemy=CPoint(46,800);
	enemy[15].m_pointEnemy=CPoint(10,800);
	enemy[16].m_pointEnemy=CPoint(10,0);
	enemy[17].m_pointEnemy=CPoint(0,800);
	enemy[18].m_pointEnemy=CPoint(10,800);
	enemy[19].m_pointEnemy=CPoint(10,800);
	enemy[20].m_pointEnemy=CPoint(10,800);
}

CGameView::~CGameView()
{
}

BOOL CGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGameView drawing
//������
void CGameView::DrawGround(CDC *pDC, CRect Client)
{
	CBitmap bitmap;
	CDC dcMemory;
	bitmap.LoadBitmap(IDB_GROUND);
    dcMemory.CreateCompatibleDC(pDC);
	dcMemory.SelectObject(&bitmap);
	pDC->BitBlt(0,0,Client.right-Client.left,Client.bottom-Client.top,&dcMemory,0,0,SRCCOPY);
}

void CGameView::OnDraw(CDC* pDC)
{
	CGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//��ȷ��
	CDC BufferDC; //���ȶ���һ����ʾ�豸���� 
	CDC MemDC; //���ȶ���һ����ʾ�豸���� 
	MemDC.CreateCompatibleDC(pDC);
    CBitmap MemBitmap;//����һ��λͼ���� 
	CRect rect;
	GetClientRect(&rect);
	int ClientWidth;
	int ClientHeight;
	ClientWidth =rect.right-rect.left;
	ClientHeight = rect.bottom-rect.top;
	//���������Ļ��ʾ���ݵ�λͼ�ڴ���ʾ�豸 
    //MemDC.CreateCompatibleDC(pDC);
	//���������Ļ��ʾ���ݵĻ�����ʾ�豸
	BufferDC.CreateCompatibleDC(pDC); 
    //���潨��һ������Ļ��ʾ���ݵ�λͼ��λͼ�Ĵ�С�����ô��ڵĴ�С 
    MemBitmap.CreateCompatibleBitmap(pDC,ClientWidth,ClientHeight);  
    //��λͼѡ�뵽�ڴ���ʾ�豸�� 
    //ֻ��ѡ����λͼ���ڴ���ʾ�豸���еط���ͼ������ָ����λͼ�� 
    BufferDC.SelectObject(&MemBitmap); 
	DrawGround(&BufferDC,rect)	;		    // ������
	hero.ShowHero(&BufferDC,&MemDC,rect);
	//�����ʾΪΪtrue,����ʾ
	if (pall[0].PallFlag)
	{
		pall[0].ShowPall(&BufferDC,&MemDC,rect);
	}
	if (pall[1].PallFlag)
	{
		pall[1].ShowPall(&BufferDC,&MemDC,rect);
	}
	if (pall[2].PallFlag)
	{
		pall[2].ShowPall(&BufferDC,&MemDC,rect);
	}
	if (pall[3].PallFlag)
	{
		pall[3].ShowPall(&BufferDC,&MemDC,rect);
	}
	//�����ʾΪΪtrue,����ʾ
	if (boss[0].BossFlag)
	{
		boss[0].ShowBoss(&BufferDC,&MemDC,rect);
	}
	if (boss[1].BossFlag)
	{
		boss[1].ShowBoss(&BufferDC,&MemDC,rect);
	}
	if (boss[2].BossFlag)
	{
		boss[2].ShowBoss(&BufferDC,&MemDC,rect);
	}
	if (boss[3].BossFlag)
	{
		boss[3].ShowBoss(&BufferDC,&MemDC,rect);
	}
	//�����ʾΪΪtrue,����ʾ
	for (int i=0;i<=20;i++)
	{
		if (enemy[i].EnemyFlag)
		{
			enemy[i].ShowEnemy(&BufferDC,&MemDC,rect);
		}
	}
	//����Ļ�����������Ҳ������ֵ
	CString num,str;
	num.Format("%d",Score);
	str.Format("%d",temp);
	BufferDC.TextOut(0,10,"Score:"+num+"ʱ�䣺"+str);
	pDC->BitBlt(0,0,ClientWidth,ClientHeight,&BufferDC,0,0,SRCCOPY); 
    //��ͼ��ɺ������     
    MemBitmap.DeleteObject();
    BufferDC.DeleteDC(); 
    MemDC.DeleteDC(); 
}

/////////////////////////////////////////////////////////////////////////////
// CGameView printing

BOOL CGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGameView diagnostics

#ifdef _DEBUG
void CGameView::AssertValid() const
{
	CView::AssertValid();
}

void CGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGameDoc* CGameView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGameDoc)));
	return (CGameDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGameView message handlers

void CGameView::OnGamestart() 
{
	// TODO: Add your command handler code here
	//��Ϸ��ʼ��������ʱ����
	SetTimer(1,220,NULL);
	SetTimer(2,1000,NULL);
	Score=10;
}

void CGameView::OnGamestop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	KillTimer(2);
}
//��ײ���
BOOL CGameView::ShotOn(CRect &body1, CRect &body2)
{ 
    //��body2������������Ͻ���body1���������У��򷵻�true
    return body1.PtInRect(body2.TopLeft());
}
void CGameView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case 1:
		//��С���Ӣ�۵���ײ��
		int m;
		for ( m=0;m<=20;m++)
		{
			if(ShotOn(enemy[m].GetEnemy(),hero.GetHero())||ShotOn(hero.GetHero(),enemy[m].GetEnemy()))
			{
				//������ӵ��ͼ�ʮ��
				//��������ʾλΪfalse
				enemy[m].EnemyFlag=false;
				hero.HeroLife+=10;
				enemy[m].ResetPos();
			}
	}
		//Сˮ�ݸı�λ��
		pall[0].ChangePos(-15);
		pall[1].ChangePos(-10);
		pall[2].ChangePos(9);
		pall[3].ChangePos(3);//�Լ�����ı�λ��
		boss[0].ChangePos(20);//
		boss[1].ChangePos(-30);//
 		/*boss[2].ChangePos(50);*/// ʼ�ո���Ӣ��
		//���firstΪtrue������ı�λ�ã�������Ӣ����
		if (boss[3].first)
		{
			boss[3].ChangePos(-50);
		}
		//���firstΪfalse������ı�λ�ã�����Ӣ����
		if (!boss[3].first)
		{
			if (boss[3].BossFlag)
			{
				if (boss[3].m_pointBoss.x<hero.m_pointHero.x)
				{
					boss[3].m_pointBoss.x+=10;
				}
				if (boss[3].m_pointBoss.x>hero.m_pointHero.x)
				{
					boss[3].m_pointBoss.x-=10;
				}
				if (boss[3].m_pointBoss.y>hero.m_pointHero.y)
				{
					boss[3].m_pointBoss.y-=10;
				}
				if (boss[3].m_pointBoss.y<hero.m_pointHero.y)
				{
					boss[3].m_pointBoss.y+=10;
				}
			}

		}
		//�ı��С���λ�ã�����0�����Σ���������
		enemy[0].ChangePos(10);
		enemy[1].ChangePos(-20);
		enemy[2].ChangePos(15);
		enemy[3].ChangePos(-25);
		enemy[4].ChangePos(10);
		enemy[5].ChangePos(-8);
		enemy[6].ChangePos(20);
		enemy[7].ChangePos(-28);
		enemy[8].ChangePos(32);
		enemy[9].ChangePos(-32);
		enemy[10].ChangePos(42);
		enemy[11].ChangePos(-62);
		enemy[12].ChangePos(83);
		enemy[13].ChangePos(-83);
		enemy[14].ChangePos(101);
		enemy[15].ChangePos(-103);
		enemy[16].ChangePos(156);
		enemy[17].ChangePos(-159);
		enemy[18].ChangePos(-200);
		enemy[19].ChangePos(200);
		enemy[20].ChangePos(-250);
		//����ı�λ�ã�����Ӣ����
		if (boss[2].BossFlag)
		{
			if (boss[2].m_pointBoss.x<hero.m_pointHero.x)
			{
				boss[2].m_pointBoss.x+=20;
			}
			if (boss[2].m_pointBoss.x>hero.m_pointHero.x)
			{
				boss[2].m_pointBoss.x-=20;
			}
			if (boss[2].m_pointBoss.y>hero.m_pointHero.y)
			{
				boss[2].m_pointBoss.y-=20;
			}
			if (boss[2].m_pointBoss.y<hero.m_pointHero.y)
			{
				boss[2].m_pointBoss.y+=20;
			}
		}
		break;
	case 2:
		//��ʱ�ı���
		temp++;
		//��ʱ�����ʾ��С�㣬��������Խ��Խ��
		if(temp%1==0)
		{
			pall[3].PallFlag=true;
			pall[2].PallFlag=true;
			pall[1].PallFlag=true;
			pall[0].PallFlag=true;
			boss[0].BossFlag=true;
			enemy[0].EnemyFlag=true;
			enemy[1].EnemyFlag=true;
		}
		if(temp%10==0)
		{
			enemy[2].EnemyFlag=true;
			enemy[3].EnemyFlag=true;
		}
		if(temp%15==0)
		{
			enemy[5].EnemyFlag=true;
			enemy[4].EnemyFlag=true;
		}
		if(temp%20==0)
		{
			
			enemy[6].EnemyFlag=true;
			enemy[7].EnemyFlag=true;
		}
		if(temp%25==0)
		{
			enemy[8].EnemyFlag=true;
			enemy[9].EnemyFlag=true;
		}
		if(temp%30==0)
		{
			for (int i=10;i<=20;i++)
			{
				enemy[i].EnemyFlag=true;
			}	
		}
		break;
	}
	Invalidate(false);
	CView::OnTimer(nIDEvent);
}

void CGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
	case VK_UP:
		hero.ChangePos(3);//����
		break;
	case VK_DOWN:
		hero.ChangePos(2);//����
		break;
	case VK_LEFT:
		hero.ChangePos(1);//����
		break;
	case VK_RIGHT:
		hero.ChangePos(0);//����
		break;
	}
	
	for (int j=0;j<=3;j++)
	{//���boss��firstΪfalse����ʾӢ�ۿ��ԳԴ�����
		if (!boss[j].first)
		{
			if(ShotOn(boss[j].GetBoss(),hero.GetHero())||ShotOn(hero.GetHero(),boss[j].GetBoss()))
			{
				//������ӵ���ȥ20��
				//��������ʾλΪfalse
				hero.HeroLife+=60;
				boss[j].BossFlag=false;
				boss[j].ResetPos();
			}
		}
		//���boss��first��Ϊfalse����ʾӢ�۲����ԳԴ�����
		if (boss[j].first)
		{
			if(ShotOn(boss[j].GetBoss(),hero.GetHero())||ShotOn(hero.GetHero(),boss[j].GetBoss()))
			{
				//������ӵ���ȥ20��
				//��������ʾλΪfalse
				hero.HeroLife-=60;	
			}
		} 
	}
	//�ȼ�������
	if (leval==2)
	{
		boss[3].first=false;//�ȼ�Ϊ2��ʱ��ͼ�����һ����ĸ���
	}
	Score=hero.HeroLife;
	if (Score<=0)
	{
		AfxMessageBox("��������ˣ�");
	}
	else if (Score>=200&&temp<=30)//����ڰ����֮�ڵ�200�֣�����ͨ��
	{
		
		
		//MessageBox("����200�֣����ԳԴ�����Ŷ!");
		
		boss[3].first=false;
		boss[2].first=false;
		boss[1].first=false;
		boss[0].first=false;
	}
	else if (temp>=100)//100��֮������ 
	{
		CString str;
		str.Format("%d",Score);
		if (Score<60)
		{
			MessageBox("����Ŷ");
		}
		if (Score>60&&Score<120)
		{
			MessageBox("����Ŭ��Ŷ");
		}
		if (Score>=120)
		{
			MessageBox("������Ŷ");
		}
		MessageBox("�÷֣�"+str);
	}
	Invalidate(false);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CGameView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar)
	{
		case '1'://����
			hero.m_pointHero.x-=10;
			hero.m_pointHero.y+=10;
			break;
		case '2'://����
				hero.m_pointHero.x+=10;
				hero.m_pointHero.y+=10;
				break;
		case '3'://����
					hero.m_pointHero.x+=10;
					hero.m_pointHero.y-=10;
					break;
		case '4'://����
			hero.m_pointHero.x-=10;
			hero.m_pointHero.y-=10;
			break;

	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}
//�����Ҽ��˵�
void CGameView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu menu;					
	menu.LoadMenu(IDR_MAINFRAME);
	CMenu *popmenu=menu.GetSubMenu(0);//��ȡ������˵���
	popmenu->TrackPopupMenu(
        TPM_LEFTALIGN,
        point.x,point.y,this);    
}
//�ı��Ѷȵĺ���
void CGameView::OnLeval() 
{
	// TODO: Add your command handler code here
	if (IDOK==Dlg.DoModal())
	{
		leval=Dlg.m_leval;
	}
	CString str;
	str.Format("%d",leval);
	AfxMessageBox("��"+str+"������Ҫ׷�ų���Ŷ");
}
//���ı�Ӣ��λ��
void CGameView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	hero.m_pointHero=point;
	Invalidate(false);
	CView::OnLButtonDown(nFlags, point);
}

void CGameView::OnMusic() 
{
	// TODO: Add your command handler code here

}
