//Download by http://www.NewXing.com
#ifndef _MAZEVIEW_H_
#define _MAZEVIEW_H_
#pragma once
//==========================================================================================
#include "./Include/AnimCtrl.h"
#include "./Include/AnimCtrlEx.h"
//======================================================================================
class CMazeView  :public CAnimCtrl
{
public:
	virtual	void	New(int w,int h);
	virtual	int		Play(void*);
	virtual	void	Draw(CBmp24*p);	
	int		m_MaxX;	//视野在迷宫地图上的最大水平坐标（像素）
	int		m_MaxY;	//视野在迷宫地图上的最垂直平坐标（像素）
	CMazeView();
	virtual ~CMazeView();
private:
	void MarkMap();	//标记地图，将最初产生的地图进行标记，以便显示地形
	int  GetMarkCode(int i,int j);//取得地图（i，j）处的标记码
private:
	CAnimCtrlEx		m_ExitCtrl;//用于显示出口动画
	POINT			m_Exit;		//出口坐标（数组位置）
};
//======================================================================================
//PM：屏幕，即迷宫显示区域
#define PM_I 				9		//屏幕水平的图片个数
#define PM_J 				7 		//屏幕垂直的图片个数
#define PM_X				63		//屏幕在显示器上的水平坐标
#define PM_Y				63		//屏幕在显示器上的垂直坐标
#define PM_CX				64*8	//迷宫显示区域水平长度
#define PM_CY				64*6	//迷宫显示区域垂直高度
//==================================================================================
#endif 