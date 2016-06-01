
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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


struct ANDGATE {
	CPoint point;
	ANDGATE(CPoint &point) {
		this->point = point;
	}
	void Paint(CClientDC &dc) {
		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_BITMAP2);
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;

		dcmem.CreateCompatibleDC(&dc);
		dcmem.SelectObject(&bitmap);
		dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	}
	void Rotate(CClientDC &dc, CPoint &point, int angle) {
		Bitmap *pBitmap;
		pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_BITMAP2));
		Bitmap tempbmp(pBitmap->GetWidth(), pBitmap->GetHeight(), PixelFormat24bppRGB);
		int ix, iy;
		ix = int(pBitmap->GetWidth() / (-2.0));
		iy = int(pBitmap->GetHeight() / (-2.0));

		Graphics graphics(dc);
		graphics.SetSmoothingMode(SmoothingModeHighQuality);
		Graphics tempgx(&tempbmp);
		tempgx.RotateTransform(angle);
		tempgx.TranslateTransform(REAL(-ix), REAL(-iy), MatrixOrderAppend);
		Point dest[3] = { Point(ix, iy), Point(ix + pBitmap->GetWidth() + 1, iy), Point(ix, iy + pBitmap->GetHeight() + 1) };
		tempgx.DrawImage(pBitmap, dest, 3, 0, 0, pBitmap->GetWidth(), pBitmap->GetHeight(), UnitPixel);
		graphics.DrawImage(&tempbmp, point.x, point.y);

	}
};

struct ORGATE {
	CPoint point;
	ORGATE(CPoint &point) {
		this->point = point;
	}
	void Paint(CClientDC &dc) {
		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_BITMAP1);
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;

		dcmem.CreateCompatibleDC(&dc);
		dcmem.SelectObject(&bitmap);
		dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	}
	void Rotate(CClientDC &dc, CPoint &point, int angle) {
		Bitmap *pBitmap;
		pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_BITMAP1));
		Bitmap tempbmp(pBitmap->GetWidth(), pBitmap->GetHeight(), PixelFormat24bppRGB);
		int ix, iy;
		ix = int(pBitmap->GetWidth() / (-2.0));
		iy = int(pBitmap->GetHeight() / (-2.0));

		Graphics graphics(dc);
		graphics.SetSmoothingMode(SmoothingModeHighQuality);
		Graphics tempgx(&tempbmp);
		tempgx.RotateTransform(angle);
		tempgx.TranslateTransform(REAL(-ix), REAL(-iy), MatrixOrderAppend);
		Point dest[3] = { Point(ix, iy), Point(ix + pBitmap->GetWidth() + 1, iy), Point(ix, iy + pBitmap->GetHeight() + 1) };
		tempgx.DrawImage(pBitmap, dest, 3, 0, 0, pBitmap->GetWidth(), pBitmap->GetHeight(), UnitPixel);
		graphics.DrawImage(&tempbmp, point.x, point.y);

	}
};

struct XORGATE {
	CPoint point;
	XORGATE(CPoint &point) {
		this->point = point;
	}
	void Paint(CClientDC &dc) {
		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_BITMAP1);
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CDC dcmem;

		dcmem.CreateCompatibleDC(&dc);
		dcmem.SelectObject(&bitmap);
		dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	}
	void Rotate(CClientDC &dc, CPoint &point, int angle) {
		Bitmap *pBitmap;
		pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_BITMAP1));
		Bitmap tempbmp(pBitmap->GetWidth(), pBitmap->GetHeight(), PixelFormat24bppRGB);
		int ix, iy;
		ix = int(pBitmap->GetWidth() / (-2.0));
		iy = int(pBitmap->GetHeight() / (-2.0));

		Graphics graphics(dc);
		graphics.SetSmoothingMode(SmoothingModeHighQuality);
		Graphics tempgx(&tempbmp);
		tempgx.RotateTransform(angle);
		tempgx.TranslateTransform(REAL(-ix), REAL(-iy), MatrixOrderAppend);
		Point dest[3] = { Point(ix, iy), Point(ix + pBitmap->GetWidth() + 1, iy), Point(ix, iy + pBitmap->GetHeight() + 1) };
		tempgx.DrawImage(pBitmap, dest, 3, 0, 0, pBitmap->GetWidth(), pBitmap->GetHeight(), UnitPixel);
		graphics.DrawImage(&tempbmp, point.x, point.y);

	}
};
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
	for (int i = 0; i < rect.Width(); i = i + 15) {
		for (int j = 0; j < rect.Height(); j = j + 15) {
			pDC->SetPixelV(i, j, RGB(143, 216, 230));
			locPoint.Add(CPoint(i, j));
		}
	}

	if (!pDoc)
		return;
	//TEST
	LogicEngine a, b, c;
	bool input1 = FALSE;
	bool input2 = TRUE;
	//a.Gate(AND, input1);
	//b.Gate(OR, a.Output, a.Output);
	c.Gate(NOT, input1);


	CString str;
	str.Format(_T("output : %d"),c.Output);
	pDC->TextOut(200, 200, str);
	
	pDC->TextOutW(200, 250, gatename);

	


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
	CView::OnLButtonDown(nFlags, point);
}


void CLogisim_KKLView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);

	ANDGATE and(point);
	and.Paint(dc);

	CView::OnLButtonUp(nFlags, point);
}




void CLogisim_KKLView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	//Rotate(dc, point);
	CView::OnRButtonUp(nFlags, point);
}
