
// CleanProject.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCleanProjectApp:
// �йش����ʵ�֣������ CleanProject.cpp
//

class CCleanProjectApp : public CWinApp
{
public:
	CCleanProjectApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCleanProjectApp theApp;