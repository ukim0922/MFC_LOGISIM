
// Logisim_KKL.h : Logisim_KKL ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CLogisim_KKLApp:
// �� Ŭ������ ������ ���ؼ��� Logisim_KKL.cpp�� �����Ͻʽÿ�.
//

class CLogisim_KKLApp : public CWinApp
{
public:
	CLogisim_KKLApp();


// �������Դϴ�.
public:
	ULONG_PTR gdiplusToken;
	virtual BOOL InitInstance();
// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CLogisim_KKLApp theApp;
