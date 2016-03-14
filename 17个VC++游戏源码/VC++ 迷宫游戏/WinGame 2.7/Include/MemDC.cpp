//Download by http://www.NewXing.com
// MemDC.cpp: implementation of the CMemDC class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MemDC.h"
CMemDC::CMemDC()
{

}

CMemDC::~CMemDC()
{

}
	
void	CMemDC::Init(HWND hWnd)
{	
	HDC hdc;
	m_hWnd=hWnd;
	hdc=::GetDC(hWnd);
	m_hMemDC=CreateCompatibleDC(hdc);
	m_hBitmap=CreateCompatibleBitmap(hdc,640,480);
	m_hBrush=CreateSolidBrush(RGB(0,0,0));
	m_hOldBitmap =(HBITMAP)SelectObject(m_hMemDC,m_hBitmap);
	m_ScreenBmp.CreateBmp(640,480);
	m_TempBmp.CreateBmp(640,480);
	m_bFade=0;
}
HDC		CMemDC::GetDC()
{
	return m_hMemDC;
}
CBmp24*	CMemDC::GetBmp()
{
	return &m_ScreenBmp;
}
void	CMemDC::Draw()
{
		if(!m_bFade)//不需要淡入淡出
		{
			UpdateDC(&m_ScreenBmp);
		}
		else if(m_bFade==1)//需要淡出
		{
			FadeOutEx();
		}
		else if(m_bFade==2)//需要淡入
		{
			FadeInEx();
		}
}
void	CMemDC::UpdateDC(CBmp24* p)
{
		HDC hMemDC;

		Wait();
		hMemDC=Reset();
		p->DrawDC(hMemDC,0,0,640,480);
		Release();
		PostMessage(m_hWnd,WM_PAINT,123,0);	
		Sleep(30);
}
void	CMemDC::FadeOut()
{
	m_bFade=1;
}
void	CMemDC::FadeIn()
{
	m_bFade=2;
}
void	CMemDC::FadeInEx()//淡入
{
	int i,j,t,s;
	int w=m_ScreenBmp.GetWidth();
	int	h=m_ScreenBmp.GetHeight();
	unsigned char*	pBits=m_ScreenBmp.GetDateBits();
	unsigned char*	pTempBits=m_TempBmp.GetDateBits();
	m_TempBmp.MemsetBits(0);

	for(t=0;t<=25;t++)
	{
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
			{	
				s=(i*w+j)*3;
				pTempBits[s]=pBits[s]*(25-t)/25;
				pTempBits[s+1]=pBits[s+1]*(25-t)/25;
				pTempBits[s+2]=pBits[s+2]*(25-t)/25;
			}
		UpdateDC(&m_TempBmp);
	}
		m_bFade=0;
}
void	CMemDC::FadeOutEx()//淡出
{
	int i,j,t,s;
	int w=m_ScreenBmp.GetWidth();
	int	h=m_ScreenBmp.GetHeight();
	unsigned char*	pBits=m_ScreenBmp.GetDateBits();
	unsigned char*	pTempBits=m_TempBmp.GetDateBits();
	m_TempBmp.MemsetBits(0);

	for(t=0;t<=25;t++)
	{
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
			{	
				s=(i*w+j)*3;
				pTempBits[s]=pBits[s]*t/25;
				pTempBits[s+1]=pBits[s+1]*t/25;
				pTempBits[s+2]=pBits[s+2]*t/25;
			}
		UpdateDC(&m_TempBmp);
	}
		m_bFade=0;

}
HDC		CMemDC::Reset()
{
	
	RECT	rt;
	GetClientRect(m_hWnd,&rt);
	FillRect(m_hMemDC,&rt,m_hBrush);
	return m_hMemDC;
}
void	CMemDC::Wait()
{
	m_Lock.Lock();
}
void	CMemDC::Release()
{
	m_Lock.UnLock();
}
void	CMemDC::Destroy()
{
	DeleteObject(m_hBrush);
	SelectObject(m_hMemDC,m_hOldBitmap);
	DeleteObject(m_hBitmap);
	DeleteDC(m_hMemDC);
}
