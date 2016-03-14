//Download by http://www.NewXing.com
// Key.cpp: implementation of the Key class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Key.h"
#include "Lock.h"
CLock g_KeyLock;
//向左，向下，向上，向右，确认键
int	KEY_LEFT,KEY_DOWN,KEY_UP,KEY_RIGHT,KEY_RETURN;
int Key_Left,Key_Down,Key_Up,Key_Right,Key_Return;

void	ClearAllKey()
{
		g_KeyLock.Lock();
		KEY_LEFT=0;
		KEY_DOWN=0;
		KEY_UP=0;
		KEY_RIGHT=0;
		KEY_RETURN=0;

		Key_Left=0;
		Key_Down=0;
		Key_Up=0;
		Key_Right=0;
		Key_Return=0;
		g_KeyLock.UnLock();
}
bool	IsMultiKey()
{
	int i=Key_Left+Key_Down+Key_Up+Key_Right;
	return i>1;
}
void	ReadKey()
{
		g_KeyLock.Lock();
		Key_Left=KEY_LEFT;
		Key_Down=KEY_DOWN;
		Key_Up=KEY_UP;
		Key_Right=KEY_RIGHT;
		Key_Return=KEY_RETURN;

		//KEY_LEFT=0;
		//KEY_DOWN=0;
		//KEY_UP=0;
		//KEY_RIGHT=0;
		//KEY_RETURN=0;
		g_KeyLock.UnLock();
}
void	OnKeyDown(unsigned int k)
{
		g_KeyLock.Lock();
		switch(k)
		{
		case VK_RETURN:
			KEY_RETURN=1;
			break;

		case VK_LEFT:
			KEY_LEFT=1;
			break;

		case VK_RIGHT:
			KEY_RIGHT=1;
			break;

		case VK_DOWN:
			KEY_DOWN=1;
			break;

		case VK_UP:
			KEY_UP=1;
			break;
		//如果不够用的，请继续添加
		}
		g_KeyLock.UnLock();
}
void	OnKeyUp(unsigned int k)
{
		g_KeyLock.Lock();
		switch(k)
		{
		case VK_RETURN:
			KEY_RETURN=0;
			break;

		case VK_LEFT:
			KEY_LEFT=0;
			break;

		case VK_RIGHT:
			KEY_RIGHT=0;
			break;

		case VK_DOWN:
			KEY_DOWN=0;
			break;

		case VK_UP:
			KEY_UP=0;
			break;
		//如果不够用的，请继续添加
		}
		g_KeyLock.UnLock();
}