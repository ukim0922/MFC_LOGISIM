
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "KKL_LOGISIM.h"
#include "ChildView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int gate_num = 0; //����Ʈ ��
char gate_result[50]; //����Ʈ �ִ� 50��


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView �޽��� ó����

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	if (����Ʈ �߰��Ǹ�)
	{
		gate_result[gate_num - 1] = 'F';  //����Ʈ ������ȣ == ��¹�ȣ �ϰ������ string�� �־Ƚ�����
	}

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	dc.TextOutW(100, 100, _T("����"));
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}

