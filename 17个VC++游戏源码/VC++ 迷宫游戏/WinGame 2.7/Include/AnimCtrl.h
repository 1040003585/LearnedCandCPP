//Download by http://www.NewXing.com
#ifndef		_ANIMCTRL_H_ 
#define		_ANIMCTRL_H_ 
#pragma once
//========================================================================================================
#include"Bmp24.h"
#include"ShowList.h"
//=====================================================================================

extern CShowList g_AnimList;
//======================================================================================================
//		最基本的动画控制类说明
//所有的动画都必须重载CAnimCtrl，所有的CAnimCtrl及子类的对象都被添加的g_AnimList中，最后统一显示
//通过重载CAnimCtrl中的虚函数，既统一接口，来完成动画控制的自定义功能。
//======================================================================================================
class CAnimCtrl  
{
public:				
	virtual	void	New()						{	g_AnimList.Add(this);		}//所有子类新定义的New函数都必须，调用该函数来将自己添加到g_AnimList
	virtual	void	New(CBmp24*p,int x,int y);
	virtual	void	New(CBmp24*p,int x,int y,int depth);
	virtual	int		Play(void*)					{	return 0;						}//子类可以重载该函数，实现具体的动画控制功能，返回1时，表示动画播放结束，0没结束
	virtual	void	Delete()					{	g_AnimList.Remove(this);		}//将自身从g_AnimList中清除
	virtual	void	Draw(CBmp24*p)				{	if(!m_bHide) m_pBmp->DrawBmp(p,m_x,m_y,m_Idx,m_EffectFlag);}//可以重载该函数，自定义往屏幕上绘画的内容，g_AnimList最后将调用该函数
			void	SetIdx(int idx)				{	m_Idx=idx;						}//组图中，当前小图片的编号。在单图中该变量无意义。
			void	SetXY(int x,int y)			{	m_x=x;	m_y=y;					}//动画的位置坐标
			void	SetX(int x)					{	m_x=x;							}//设置动画的水平坐标
			void	SetY(int y)					{	m_y=y;							}//设置动画的垂直坐标
			int		GetX()						{	return	m_x;					}
			int		GetY()						{	return	m_y;					}
			void	AddXY(int x,int y)			{	m_x+=x;	m_y+=y;					}//移动动画的位置
			void	SetFlip(int flipType)		{	m_EffectFlag=flipType;			}//0原图 1水平 2垂直 3完全，暂时只是实现了图片的翻转效果
			void	SetHide(bool bHide)			{	m_bHide=bHide;	}	//可以隐藏动画，
			int		GetDepth()					{	return m_Depth;}
			void	SetDepth(int depth);	//设置图片显示的深度，范围：0-9,0为最下面，9为最上面
protected:
			int		m_x,m_y;		//动画的坐标
			int		m_Idx;			//组图中，当前小图片的编号。在单图中该变量无意义。
			int		m_EffectFlag;	//图片显示的效果，暂时只有翻转效果，可取值为：0原图 1水平 2垂直 3完全翻转
			bool	m_bHide;		//可以隐藏，隐藏之后，不会显示，也不会被做播放处理。
			int		m_Depth;
			CBmp24*	m_pBmp;			//动画所用到的图片
public:
	CAnimCtrl();
	virtual ~CAnimCtrl();
};
//============================================================================================
#endif