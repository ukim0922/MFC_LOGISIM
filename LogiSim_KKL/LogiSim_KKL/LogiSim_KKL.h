
// LogiSim_KKL.h : LogiSim_KKL ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CLogiSim_KKLApp:
// �� Ŭ������ ������ ���ؼ��� LogiSim_KKL.cpp�� �����Ͻʽÿ�.
//

class CLogiSim_KKLApp : public CWinApp
{
public:
	CLogiSim_KKLApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLogiSim_KKLApp theApp;
