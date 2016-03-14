//Download by http://www.NewXing.com
#include "stdafx.h"
#include "Lock.h"
//====================================================================
CLock::CLock(BOOL b){	m_hMutex = CreateMutex(NULL, b, NULL);		}
CLock::CLock()		{	m_hMutex = CreateMutex(NULL, FALSE, NULL);	}
CLock::~CLock()		{	CloseHandle(m_hMutex);						}
void CLock::Lock()	{	WaitForSingleObject(m_hMutex, INFINITE);	}
void CLock::UnLock(){	ReleaseMutex(m_hMutex);						}
//====================================================================
