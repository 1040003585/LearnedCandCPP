//Download by http://www.NewXing.com
#ifndef _THREAD_H_ 
#define _THREAD_H_
#pragma once
//=====================================================================================
#include "Lock.h"
//=====================================================================================
//							一个线程模型类
//首先，定义一个DWORD pWorkFun(void*pParam,CThread*pThread)类型的函数作为线程的运行函数，
//函数中调用pThread->IsStop()来判定是否要退出该函数，警告：不要用pThread调用其他函数和变量
//其次，在主程序中，调用Create创建后台线程，主程序退出时，调用Destroy来关闭后台线程。
//最后，构造这样的一个类，是为了代码的重用。居然能重用？太好了，因为我很懒，哈哈
//=====================================================================================
class CThread  
{
public:
	void	Create(	DWORD (*pWorkFun)(void*pParam,CThread*),void* lpParam);			//由主程序调用，创建后台线程
	void	Destroy();			//由主程序调用，关闭后台线程，释放资源
	CThread();
	virtual ~CThread();
	friend DWORD WINAPI ThreadFun(void* lpParam);	//后台工作线程函数
	bool	IsStop();		//是否停止工作
private:
	void*		m_Param;
	DWORD		(*m_pWorkFun)(void*pParam,CThread*);
	bool		m_Stop;		//是否停止线程
	CLock		m_Lock;		//用于对m_Stop访问的互斥控制
	HANDLE		m_hThread;	//线程的句柄
};
//======================================================================================
#endif