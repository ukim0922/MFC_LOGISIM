
// KKL_LOGISIM.h : KKL_LOGISIM ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CKKL_LOGISIMApp:
// �� Ŭ������ ������ ���ؼ��� KKL_LOGISIM.cpp�� �����Ͻʽÿ�.
//

class CKKL_LOGISIMApp : public CWinApp
{
public:
	CKKL_LOGISIMApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
protected:
	HMENU  m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
};

extern CKKL_LOGISIMApp theApp;
