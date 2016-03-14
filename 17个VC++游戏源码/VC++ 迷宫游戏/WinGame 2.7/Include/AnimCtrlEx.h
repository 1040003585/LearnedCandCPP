//Download by http://www.NewXing.com
#ifndef _ANIMCTRLEX_H_ 
#define _ANIMCTRLEX_H_ 
#pragma once
//========================================================================================
#include "AnimCtrl.h"
//================================================================================================
//							基于动画帧的动画控制类
//首先，将动画所用的图片序列按照编号，位置，显示延迟等，排成一个动画帧数组。
//该控制类将根据动画帧数组和指定的动画播放类型，进行动画控制。
//=================================================================================================
enum FRAME_TYPE//动画帧的播放类型				
{												
	FRAME_STATIC,		//静止动画				
	FRAME_PLAY_ONCE,	//一次性动画									//动画帧定义的示例：
	FRAME_REPEAT,		//重复性动画									//SAnimFrame DemoFrm[]={//一个向右偏移的动画帧
	FRAME_GO_BACK		//来回循环动画									//			{0,5,0,2},
};																		//			{2,5,0,2},
struct	SAnimFrame		//动画帧的结构定义								//			{3,5,0,2},
{																		//			{4,5,0,2},
	int idx;			//小图片编号									//			{5,5,0,2},
	int x;				//水平偏移，显示时将被加到动画原有水平坐标上	//			{0xffff,0xffff,0xffff,0xffff}//动画帧结束标志
	int y;				//垂直偏移，显示时将被加到动画原有垂直坐标上	//			};
	int t;				//延迟
};
class CAnimCtrlEx: public CAnimCtrl
{
public:	
	virtual	void	New(CBmp24*pBmp,int x,int y,SAnimFrame *pFrame,int FrameType);	//定义新的初始函数
	virtual	void	Draw(CBmp24*p);	//自定义动画显示，把由帧指定的小图片，显示到由原动画坐标和帧中坐标叠加的位置												
	virtual	int		Play(void*);	//自定义播放动画，只是用来切换动画帧
	int				GetCurentFrame(){return m_CurrentFrame;}//当前动画帧
	bool			bEndFrame(){return (m_pFrame[m_CurrentFrame].t==0xffff); }//是否是动画结束帧
	void			SetHide(bool bHide)			{	m_bHide=bHide;	}	//可以隐藏动画，
	CAnimCtrlEx();
	virtual ~CAnimCtrlEx();
protected:
	int			m_FrameType;	//动画帧的类型
	int			m_Count;		//用来计数，来完成动画帧中的延迟
	int			m_CurrentFrame;	//当前动画帧
	int			m_AddFrame;		//动画帧移动时的偏移，一般为1，在来回播放类型的动画帧中，回来时，为负1
	bool		m_bHide;		//可以隐藏，隐藏之后，不会显示，也不会被做播放处理。
	SAnimFrame*	m_pFrame;
};
//============================================================================================
#endif