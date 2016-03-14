//Download by http://www.NewXing.com
// Bmp24.cpp: implementation of the CBmp24 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Bmp24.h"
#include <stdio.h>
#include <wingdi.h>
#include<malloc.h>
//===================================================================================================================
void CBmp24::CreateBmp(long w,long h)
{
	//是不是已经用过了，先把原先的内存释放了
	if(m_pBits!=NULL)		{free(m_pBits);			m_pBits=NULL;}
	m_BmpInf.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_BmpInf.bmiHeader.biWidth = w;
	m_BmpInf.bmiHeader.biHeight = h;
	m_BmpInf.bmiHeader.biPlanes = 1;
	m_BmpInf.bmiHeader.biBitCount = 24;
	m_BmpInf.bmiHeader.biCompression = BI_RGB;
	m_BmpInf.bmiHeader.biSizeImage = w*h*3;
	m_BmpInf.bmiHeader.biXPelsPerMeter = 0;
	m_BmpInf.bmiHeader.biYPelsPerMeter = 0;
	m_BmpInf.bmiHeader.biClrUsed = 0;
	m_BmpInf.bmiHeader.biClrImportant = 0;
	m_pBits=(unsigned char*)malloc(w*h*3);
	memset(m_pBits,0,w*h*3);//新创建的图片完全抹黑
}
//===================================================================================================================
bool CBmp24::LoadBmp(char *fileName)
{
	FILE *fp;
	BITMAPFILEHEADER bmpFileHeader;
	unsigned long count=0;
	//是不是已经用过了，先把原先的内存释放了
	if(m_pBits!=NULL)		{free(m_pBits);			m_pBits=NULL;}
	//打开图像文件
	if( (fp = fopen( fileName, "rb")) == NULL ) 
	{
		TRACE("无法打开文件: %s\n", fileName );
		return false;
	}
	//读取图像文件头
 	if ((count=fread(&bmpFileHeader, 1, sizeof(bmpFileHeader), fp)) != sizeof(bmpFileHeader))
	{
		TRACE( "ERR004 读取 BMP 文件头失败: count=%d\n", count);
				return false;
	}
	//如果不是图像文件，下面也就没戏了
	if(bmpFileHeader.bfType!='MB')
	{
		TRACE("不是BMP文件\n");
		return false;
	}
	//读取图像信息头,是m_BmpInf.bmiHeader，而不是m_BmpInf，操！
 	if ((count=fread(&m_BmpInf.bmiHeader, 1, sizeof(BITMAPINFOHEADER), fp)) != sizeof(BITMAPINFOHEADER))
	{
		TRACE( "ERR004 读取 BMP 信息失败: count=%d\n", count);
				return false;
	}
	//如果不是24真彩位图，下面还是没戏
	if(m_BmpInf.bmiHeader.biBitCount!=24)
	{
		TRACE("不是24位BMP文件\n");
		return false;
	}
	//为了安全起见，重新计算图像数据长度，因为有的图的biSizeImage为零
	m_BmpInf.bmiHeader.biSizeImage=m_BmpInf.bmiHeader.biWidth*m_BmpInf.bmiHeader.biHeight*3;


	m_pBits=(unsigned char*)malloc(m_BmpInf.bmiHeader.biSizeImage);
	if(!m_pBits)//居然没申请到内存，我无语了，呜呜！
	{
		TRACE("ERROR CBmp24::LoadBmp malloc\n");
		return false;
	}
	
	//读取图像的像素数据
 	if ((count=fread(m_pBits, 1, m_BmpInf.bmiHeader.biSizeImage, fp)) != m_BmpInf.bmiHeader.biSizeImage)
	{
		TRACE( "ERR004 读取 BMP 文件数据失败: count=%d\n", count);
		return false;
	}
	fclose(fp);//读完了，请关上文件，谢谢！
	return true;//终于成功了，操！
}
//===================================================================================================================
bool	CBmp24::LoadBmp(char *fileName,COLORREF cTransparentColor)
{
	m_bTrasparented=1;		//是否需要透明显示
	m_TransparentColor=cTransparentColor;		//透明色
	return LoadBmp(fileName);
}
//===================================================================================================================
//将全图在hdc指向的窗口显示，(x,y,w,h)为窗口上的矩形
void CBmp24::DrawDC(HDC hdc,int x,int y,int w,int h)
{
	StretchDIBits(hdc,x,y,w,h,0,0,m_BmpInf.bmiHeader.biWidth,m_BmpInf.bmiHeader.biHeight,m_pBits,&m_BmpInf,DIB_RGB_COLORS,SRCCOPY);
}
//===================================================================================================================
void CBmp24::DrawBmp(CBmp24*p,int tx,int ty,int Idx,int effectFlag)
{
	if(!m_bTrasparented)	DrawBmpEx(p,tx,ty,0,0,m_BmpInf.bmiHeader.biWidth,m_BmpInf.bmiHeader.biHeight,effectFlag);
	else	DrawBmpEx(p,tx,ty,0,0,m_BmpInf.bmiHeader.biWidth,m_BmpInf.bmiHeader.biHeight,effectFlag,m_TransparentColor);	
}
//==============================================================================================
//参数:	CBmp24* p		指向目标图
//		int tx			在目标图上开始画图的水平坐标
//		int ty			在目标图上开始画图的垂直坐标
//		int	sx			本图上需画图的水平起始坐标
//		int sy			本图上需画图的垂直起始坐标
//		int w			本图上需画图的水平长度
//		int h			本图上需画图的垂直高度
//		int	flipType	画图的翻转标志,0不翻转，1水平翻转，2垂直翻转，3完全翻转
//===============================================================================================
//功能：将本图上的(sx,sy,w,h)矩形，画到p指向的目标图上，在目标图上以坐标(tx,ty)开始花起
//		同时，flipType指定了画图时的翻转操作。
//===============================================================================================
void	CBmp24::DrawBmpEx(CBmp24*p,int tx,int ty,int sx,int sy,int w,int h,int flipType)
{
	int i,j,t,s,cx=w,cy=h;
	long w1=p->GetWidth();
	long h1=p->GetHeight();
	long w0=m_BmpInf.bmiHeader.biWidth;
	long h0=m_BmpInf.bmiHeader.biHeight;
	unsigned char* pBits1=p->GetDateBits();
	unsigned char* pBits0=this->GetDateBits();
	if(tx+cx>=w1)	cx=w1-tx;//先检查下是否超界
	if(ty+cy>=h1)	cy=h1-ty;
	if(tx<0)	{sx-=tx;cx=cx+tx;tx=0;}
	if(ty<0)	{sy-=ty;cy=cy+ty;ty=0;}
	for(j=0;j<cy;j++)
		for(i=0;i<cx;i++)
		{	
			t=((h1-ty-j-1)*w1+tx+i)*3;
			s=FlipCount(flipType,sx,sy,cx,cy,j,i);
			pBits1[t+0]=pBits0[s+0];
			pBits1[t+1]=pBits0[s+1];
			pBits1[t+2]=pBits0[s+2];
		}
}
//==============================================================================================
//与上面的函数唯一的区别，就是cTransparentColor指定的透明色不会被画
void	CBmp24::DrawBmpEx(CBmp24*p,int tx,int ty,int sx,int sy,int w,int h,int flipType,COLORREF cTransparentColor)
{
	int i,j,t,s,cx=w,cy=h;
	long w1=p->GetWidth();
	long h1=p->GetHeight();
	long w0=m_BmpInf.bmiHeader.biWidth;
	long h0=m_BmpInf.bmiHeader.biHeight;
	unsigned char* pBits1=p->GetDateBits();
	unsigned char* pBits0=this->GetDateBits();
	unsigned char *pTrasparentColor=(unsigned char *)&cTransparentColor;
	if(tx+cx>=w1)	cx=w1-tx;
	if(ty+cy>=h1)	cy=h1-ty;
	if(tx<0)	{sx-=tx;cx=cx+tx;tx=0;}
	if(ty<0)	{sy-=ty;cy=cy+ty;ty=0;}
	for(j=0;j<cy;j++)
		for(i=0;i<cx;i++)
		{
			t=((h1-ty-j-1)*w1+tx+i)*3;
			s=FlipCount(flipType,sx,sy,cx,cy,j,i);
			if(pTrasparentColor[2]!=pBits0[s+0]|| pTrasparentColor[1]!=pBits0[s+1]|| pTrasparentColor[0]!=pBits0[s+2])
			{
				pBits1[t+0]=pBits0[s+0];
				pBits1[t+1]=pBits0[s+1];
				pBits1[t+2]=pBits0[s+2];
			}
		}
}
//==============================================================================================
//参数:	type			画图的翻转标志,0不翻转，1水平翻转，2垂直翻转，3完全翻转
//		x				本图上需画图的水平起始坐标
//		y				本图上需画图的垂直起始坐标
//		w				本图上需画图的水平长度
//		h				本图上需画图的垂直高度
//		i				在本图上需画图的矩形区域中的水平坐标（相对小矩形的）
//		j				在本图上需画图的矩形区域中的垂直坐标（相对小矩形的）
//==============================================================================================
//功能：指定矩形（x,y,w,h）中的坐标（i,j），及所需要翻转的标志，算出该点在本图像素缓冲区中的位置。
//===============================================================================================
int		CBmp24::FlipCount(int type,int x,int y,int w,int h,int j,int i)
{
	int W=m_BmpInf.bmiHeader.biWidth;
	int H=m_BmpInf.bmiHeader.biHeight;
	if(type==0)//不翻转
	{
		y=y+j;
		x=x+i;
	}
	else if(type==1)//水平翻转
	{
		y=y+j;
		x=x+w-i-1;
	}
	else if(type==2)//垂直翻转
	{
		y=y+h-j-1;
		x=x+i;
	}
	else if(type==3) //完全翻转
	{
		y=y+h-j-1;
		x=x+w-i-1;
	}
	return ((H-y-1)*W+x)*3;
}
//===================================================================================================================
void	CBmp24::MemsetBits(int i)
{
	memset(m_pBits,i,m_BmpInf.bmiHeader.biSizeImage);
}
//===================================================================================================================
CBmp24::CBmp24()
{
	memset(&m_BmpInf,0,sizeof(m_BmpInf));
	m_pBits=NULL;
}
//===================================================================================================================
CBmp24::~CBmp24()
{
	if(m_pBits!=NULL)
	{
		free(m_pBits);
		m_pBits=NULL;
	}
}
//=====================组图处理的具体实现=====================================================
bool	CMultiBmp::LoadBmp(char *fileName,int colum,int row)
{
	bool r;
	m_Colum=colum;				//有多少列小图
	m_Row=row;					//有多少行小图
	m_bTrasparented=0;
	r=CBmp24::LoadBmp(fileName);
	m_SubWidth	=	m_BmpInf.bmiHeader.biWidth/m_Colum;
	m_SubHeight	=	m_BmpInf.bmiHeader.biHeight/m_Row;
	return r; 
}
//===================================================================================================================
bool	CMultiBmp::LoadBmp(char *fileName,int colum,int row,COLORREF cTransparentColor)
{
	bool r;
	m_Colum=colum;				//有多少列小图
	m_Row=row;					//有多少行小图
	m_bTrasparented=1;
	m_TransparentColor=cTransparentColor;
	r=CBmp24::LoadBmp(fileName);
	m_SubWidth	=	m_BmpInf.bmiHeader.biWidth/m_Colum;
	m_SubHeight	=	m_BmpInf.bmiHeader.biHeight/m_Row;
	return r; 
}
//===================================================================================================================
void	CMultiBmp::DrawBmp(CBmp24*p,int tx,int ty,int Idx,int effectFlag)
{
	Idx=Idx%(m_Row*m_Colum);
	int c=Idx%m_Colum;
	int r=Idx/m_Colum;
	int w=m_SubWidth;
	int h=m_SubHeight;
	if(!m_pBits) return;
	if(!m_bTrasparented)	DrawBmpEx(p,tx,ty,c*w,r*h,w,h,effectFlag);
	else	DrawBmpEx(p,tx,ty,c*w,r*h,w,h,effectFlag,m_TransparentColor);
}
//===================================================================================================================
 void	CMultiBmp::DrawDC(HDC hdc,int x,int y,int w,int h,int Idx)
 {
	int c=Idx%m_Colum;
	int r=m_Row-Idx/m_Colum-1;//bmp图像是按照从下往上放的
	StretchDIBits(hdc,x,y,w,h,c*m_SubWidth,r*m_SubHeight,m_SubWidth,m_SubHeight,m_pBits,&m_BmpInf,DIB_RGB_COLORS,SRCCOPY);
 }
//===================================================================================================================
CMultiBmp::CMultiBmp()
{
	memset(&m_BmpInf,0,sizeof(m_BmpInf));
	m_pBits=NULL;
}
//===================================================================================================================
CMultiBmp::~CMultiBmp()
{
	if(m_pBits!=NULL)
	{
		free(m_pBits);
		m_pBits=NULL;
	}
}
//===================================================================================================================
