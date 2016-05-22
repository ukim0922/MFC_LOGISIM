
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
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
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
	CBitmap andGate;
	andGate.LoadBitmap(IDB_BITMAP_AND);
	BITMAP andGateinfo;
	andGate.GetBitmap(&andGateinfo);

	//if (/*����Ʈ �߰��Ǹ�*/1)
	//{
	//	gate_result[gate_num - 1] = 'F';  //����Ʈ ������ȣ == ��¹�ȣ �ϰ������ string�� �־Ƚ�����
	//}

	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// ���� : ���⿡ ����Ʈ�� ���콺 ���� �� �ʷϵ��׶�� �ߵ��� �ϱ�
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);

	CWnd::OnLButtonDown(nFlags, point);
}


// not �� ����Ʈ
int CChildView::GateNOT(CPaintDC& dc, int & InPut)
{
	switch (InPut)
	{
	case 0:
		InPut = 1;
	case 1:
		InPut = 0;
	default:
		ERROR;
	}

	return InPut;
}

int CChildView::GateAND(CPaintDC& dc, int Input1, int Input2, int Output) {
	if (Input1&&Input2) {
		Output = 1;
	}
	else {
		Output = 0;
	}
	return Output;
}
void CChildView::rotate(CClientDC dc, CDC dcmem, BITMAP bmpinfo) { // ���� ȸ��
	dc.StretchBlt(10 + bmpinfo.bmWidth - 1, 10 + bmpinfo.bmHeight - 1,
		-bmpinfo.bmWidth, -bmpinfo.bmHeight,
		&dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
}
