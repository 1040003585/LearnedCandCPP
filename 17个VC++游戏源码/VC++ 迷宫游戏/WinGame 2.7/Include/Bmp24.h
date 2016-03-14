//Download by http://www.NewXing.com
#ifndef _BMP24_H_ 
#define _BMP24_H_ 
#pragma once
//===============================================================================================================
//										24位真彩图像处理类的说明
//		24位真彩图像，每个像素有3个字节，颜色值顺序为(b,g,r),而COLORREF型数据中的颜色值顺序为(r,g,b).
//另外值得注意的是，图像的数据存储为按行从下往上存的，当你计算的一个图像坐标位置为(x,y),需要转成(x,H-y-1),
//图像缓存冲区中对应的位置为[(H-y-1)*W+x]*3,其中，W为图片宽度，H为图片高度。
//		该类只处理24位真彩图像，直接进行像素操作，能地对图像进行快速高效地翻转，透明显示等,在最后往窗体上绘图时，
//可以进行缩放。
//		CBmp24类是针对单张图片进行处理的，CMultiBmp继承了CBmp24，但是CMultiBmp是针对一组图片中有编号Idx指定的子图处理的,
//子图是按照划分，从左到右，从上到下的顺序，自动编号的，其中，左上角的编号为0。
//		该程序中使用了TRACE，在win32下需要添加#include <afx.h>，且放在#include <windows.h>上面，
//然后，project->settings->use MFC in a shared DLL.
//		最后，提醒下，这是个可重用类，嘿嘿
//																						--作者：袁堂夫
//																						--QQ：276081463
//																						--日期：2008.9.29																			
//================================================================================================================
class CBmp24 
{
public:
					//加载位图，不进行透明显示
	virtual bool	LoadBmp(char *fileName);
					//加载位图，指定透明色，需要进行透明显示
	virtual bool	LoadBmp(char *fileName,COLORREF cTransparentColor);
					//将该图完全画到另一幅图上，p指向另一幅图，(tx,ty)为在另一幅图开始画起的坐标，Idx，在此处无意义，只为保持统一的接口，effectFlag图片的效果标志，如翻转等
	virtual void	DrawBmp(CBmp24*p,int tx,int ty,int Idx,int effectFlag);
					//创建一个空的图片
	void			CreateBmp(long w,long h);
					/*将全图到指定设备描述符hdc的窗口，(x,y，w,h)为目标窗口上的矩形
					该函数不能进行透明显示，当大小不一致是，将被缩放*/
	void			DrawDC(HDC hdc,int x,int y,int w,int h);
	long			GetWidth(){return m_BmpInf.bmiHeader.biWidth; }//取得图片宽图
	long			GetHeight(){return m_BmpInf.bmiHeader.biHeight;}//取得图片长度
	unsigned char*	GetDateBits(){return (unsigned char*)m_pBits;}//取得图片的像素数据缓冲区指针
	void			MemsetBits(int i);
protected:			//源图片像素位置的翻转计算公式,求(x,y,w,h)矩形的翻转时对应的像素位置，(i，j)为该小图中的当前像素位置
	int				FlipCount(int type,int x,int y,int w,int h,int j,int i);
					//画图的具体实现，(tx,ty)目标图的起始坐标，(sx,sy,w,h)源图的举行，effectFlag画图的效果，如翻转等
	void			DrawBmpEx(CBmp24*p,int tx,int ty,int sx,int sy,int w,int h,int effectFlag);
					//画图的具体实现，(tx,ty)目标图的起始坐标，(sx,sy,w,h)源图的举行，effectFlag画图的效果，如翻转等，cTransparentColor指名透明色，即不被画到目标图的像素
	void			DrawBmpEx(CBmp24*p,int tx,int ty,int sx,int sy,int w,int h,int effectFlag,COLORREF cTransparentColor);

protected:
	bool			m_bTrasparented;		//是否需要透明显示
	COLORREF		m_TransparentColor;		//透明色
	BITMAPINFO		m_BmpInf;				//图片的位图信息
	unsigned char*	m_pBits;				//图片的像素数据
public:
CBmp24();
virtual ~CBmp24();
};
class CMultiBmp: public CBmp24
{
public:				//加载位图，不进行透明显示,图片将被分成c*r个小图处理
	bool			LoadBmp(char *fileName,int c,int r);
					//加载位图，图片将被分成c*r个小图处理，需要透明显示，cTransparentColor指名透明色
	bool			LoadBmp(char *fileName,int c,int r,COLORREF cTransparentColor);
					/*将编号Idx的小图画到p指定的另一幅图上，(tx,ty)为在另一幅图开始画起的坐标，effectFlag图片的效果标志，如翻转等
					编号是按照从左到右，从上到下的顺序自动编号的，左上角的编号为0*/
  virtual void		DrawBmp(CBmp24*p,int tx,int ty,int Idx,int effectFlag);
  					/*将编号Idx的小图画到hdc指定的窗体上，(x,y，w,h)为目标窗口上的矩形
					该函数不能进行透明显示，当大小不一致是，将被缩放*/
  void				DrawDC(HDC hdc,int x,int y,int w,int h,int Idx);
private:
	long			m_SubWidth;		//被划成小图后，每个小图片的宽度	
	long			m_SubHeight;	//被划成小图后，每个小图片的高度
	int				m_Colum;		//有多少列小图
	int				m_Row;			//有多少行小图
public:
CMultiBmp();
virtual ~CMultiBmp();
};
//========================================================================================
#endif