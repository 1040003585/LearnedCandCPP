//Download by http://www.NewXing.com
#ifndef _KEY_H_ 
#define _KEY_H_ 
#pragma once
//================================================================================
extern  int Key_Left,Key_Down,Key_Up,Key_Right,Key_Return;
void	ClearAllKey();
void	ReadKey();
void	OnKeyDown(unsigned int k);
void	OnKeyUp(unsigned int k);
bool	IsMultiKey();
//===================================================================================
#endif 
