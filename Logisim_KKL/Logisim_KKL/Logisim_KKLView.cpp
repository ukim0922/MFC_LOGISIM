
// Logisim_KKLView.cpp : CLogisim_KKLView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Logisim_KKL.h"
#endif

#include "Logisim_KKLDoc.h"
#include "Logisim_KKLView.h"
#include "LogicEngine.h"    //���� �߰�
#include "FilpFlopEngine.h"    //���� �߰�

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLogisim_KKLView

IMPLEMENT_DYNCREATE(CLogisim_KKLView, CView)

BEGIN_MESSAGE_MAP(CLogisim_KKLView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
//	ON_WM_LBUTTONDBLCLK()
ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CLogisim_KKLView ����/�Ҹ�

CLogisim_KKLView::CLogisim_KKLView()
	: gatename(_T(""))
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CLogisim_KKLView::~CLogisim_KKLView()
{
}

BOOL CLogisim_KKLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CLogisim_KKLView �׸���

void CLogisim_KKLView::OnDraw(CDC* pDC)
{
	CLogisim_KKLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	//��ǥ ǥ��
	CRect rect;
	GetWindowRect(&rect);
	locPoint.SetSize(0);
	for (int i = 0; i < rect.Width(); i = i + 8) {
		for (int j = 0; j < rect.Height(); j = j + 8) {
			pDC->SetPixelV(i, j, RGB(143, 216, 230));
			locPoint.Add(CPoint(i, j));
		}
	}

	if (!pDoc)
		return;
	//TEST
	LogicEngine a, b, c;
	c.Gate(NOT);

	CString str;
	str.Format(_T("output : %d"),c.output[0].boolState);
	pDC->TextOut(200, 200, str);
	


	


	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CLogisim_KKLView ����

#ifdef _DEBUG
void CLogisim_KKLView::AssertValid() const
{
	CView::AssertValid();
}

void CLogisim_KKLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLogisim_KKLDoc* CLogisim_KKLView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLogisim_KKLDoc)));
	return (CLogisim_KKLDoc*)m_pDocument;
}
#endif //_DEBUG



void CLogisim_KKLView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	/*if (selected == true) {*/
		dc.TextOut(200, 250, gatename);
	
		if (selected) {
			dc.TextOutW(200, 300, _T("TRUE"));
		}
		else
			dc.TextOutW(200, 300, _T("FALSE"));
	/*	selected = false;
		Invalidate();
	}*/
	//Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CLogisim_KKLView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	{
		if (gatename == "AND") {
			ANDGATE and(point,IDB_BITMAP_AND);
			and.Paint(dc);
			gatename = "";
		}
		else if (gatename == "OR") {
			ORGATE or(point, IDB_BITMAP_OR);
			or.Paint(dc);
			gatename = "";
		}
		else if (gatename == "NOT") {
			NOTGATE not (point, IDB_BITMAP_NOT);
			not.Paint(dc);
			gatename = "";
		}
		else if (gatename == "NAND") {
			NANDGATE nand(point, IDB_BITMAP_NAND);
			nand.Paint(dc);
			gatename = "";
		}
		else if (gatename == "NOR") {
			NORGATE nor(point, IDB_BITMAP_NOR);
			nor.Paint(dc);
			gatename = "";
		}
		else if (gatename == "XOR") {
			XORGATE xor (point, IDB_BITMAP_XOR);
			xor.Paint(dc);
			gatename = "";
		}
		else if (gatename == "D-FF") {

		}
		else if (gatename == "JK-FF") {

		}
		else if (gatename == "T-FF") {
			TFF tff(point, IDB_BITMAP_TFF);
			tff.Paint(dc);
			gatename = "";
		}
		else if (gatename == "LAMP") {
			BITLAMP lamp(point, IDB_BITMAP_LON);
			lamp.PrintLabel(dc,gatename);
			lamp.Paint(dc);
			gatename = "";
		}

		CView::OnLButtonUp(nFlags, point);
	}
}




void CLogisim_KKLView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	if (gatename == "AND") {
		ANDGATE and (point, IDB_BITMAP_AND);
		and.Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "OR") {
		ORGATE or (point, IDB_BITMAP_OR);
		or.Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "NOT") {
		NOTGATE not (point, IDB_BITMAP_NOT);
		not.Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "NAND") {
		NANDGATE nand(point, IDB_BITMAP_NAND);
		nand.Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "NOR") {
		NORGATE nor(point, IDB_BITMAP_NOR);
		nor.Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "XOR") {
		XORGATE xor (point, IDB_BITMAP_XOR);
		xor.Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "D-FF") {

	}
	else if (gatename == "JK-FF") {

	}
	else if (gatename == "T-FF") {
		TFF tff(point, IDB_BITMAP_TFF);
		tff.Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "LAMP") {
		BITLAMP lamp(point, IDB_BITMAP_LON);
		lamp.Rotate(dc, 90);
		gatename = "";
	}
	CView::OnRButtonUp(nFlags, point);
}
