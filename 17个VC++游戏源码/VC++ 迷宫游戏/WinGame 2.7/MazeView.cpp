//Download by http://www.NewXing.com
#include "stdafx.h"
#include "MazeView.h"
#include "CreateMap.h"
#include "AnimDate.h"
//=================================================================================
void	CMazeView::New(int w,int h)
{
		//将迷宫显示区域置于大地图的右下方
	m_x			=	( w - PM_I+1) *64;	
	m_MaxX		=	( w - PM_I +1) *64;
	m_y			=	( h - PM_J +1) *64;
	m_MaxY		=	( h - PM_J +1) *64;
	CreateMap(w,h,&m_Exit);
	MarkMap();
	CAnimCtrl::New();
	if(m_Exit.x==0)
	{
		m_ExitCtrl.New(&LeftExitBmp,0,0,g_LeftExitFrm,FRAME_REPEAT);
	}
	else
	{
		m_ExitCtrl.New(&UpExitBmp,0,0,g_UpExitFrm,FRAME_REPEAT);
	}
}
int	CMazeView::Play(void*)
{
	m_ExitCtrl.Play(NULL);
	return 0;
}
void CMazeView::Draw(CBmp24*p)
{
	int I = m_x / 64;
	int J = m_y / 64;
	int vx = m_x % 64;
	int vy = m_y % 64;
	int x;
	int y;
	int i = 0;
	int j = 0;
	int t;
	for( i=0; i<PM_I; i++ )
	{
		for( j=0; j<PM_J; j++ )
		{
				x = PM_X+i*64-vx;
				y = PM_Y+j*64-vy;
				//if(x<0||y<0)
				//TRACE("x=%d,y=%d\n",x,y);
				//在此画图
				t=g_MazeMap[I+i][J+j];
				if(t>0)
				{
					MazeWall[0].DrawBmp(p,x,y,0,m_EffectFlag);	
				}
				else
				{
					MazeWall[-t].DrawBmp(p,x,y,0,m_EffectFlag);	
				}
		}
	}
	x= m_Exit.x*64 - m_x+PM_X ;
	y= m_Exit.y*64 - m_y+PM_Y ;
	m_ExitCtrl.SetXY(x,y);
}
void CMazeView::MarkMap()
{
	int i,j,r;
	for( i=0; i<g_MazeWidth; i++ )
	{
	  if( g_MazeMap[i][1]>0 )			g_MazeMap[i][0] = -1;
	  else								g_MazeMap[i][0] = -2;
	  if( g_MazeMap[i][g_MazeHeight-2]>0)	g_MazeMap[i][g_MazeHeight-1] = -1;
	  else									g_MazeMap[i][g_MazeHeight-1] = -3;
	}
	g_MazeMap[m_Exit.x][m_Exit.y]=1;
	for( i=0; i<g_MazeWidth; i++ )
	for( j=1; j<g_MazeHeight-1; j++ )
	{
		if(g_MazeMap[i][j]>0)
			continue;

		r=GetMarkCode(i,j);
		switch(r)
		{
			case 0:
			g_MazeMap[i][j] = -1;
			break;
			case 1:
			g_MazeMap[i][j] = -2;
			break;
			case 10:
			g_MazeMap[i][j] = -3;
			break;
			case 11: 
			g_MazeMap[i][j] = -4;
			break;
			default	:
			//g_MazeMap[i][j] = -1;
			break;
		}
	}
}
int  CMazeView::GetMarkCode(int i,int j)
{
	int r=0;
	r	+=	g_MazeMap[i][j-1]>0? 	0	:	1;	
	r	*=	10;
	r	+=	g_MazeMap[i][j+1]>0? 	0	:	1;
	return r;
}
CMazeView::CMazeView(){}
CMazeView::~CMazeView(){}