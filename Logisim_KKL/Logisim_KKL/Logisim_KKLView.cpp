
// Logisim_KKLView.cpp : CLogisim_KKLView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Logisim_KKL.h"
#endif

#include "Logisim_KKLDoc.h"
#include "Logisim_KKLView.h"
#include "LogicEngine.h"    //엔진 추가

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

// CLogisim_KKLView 생성/소멸

CLogisim_KKLView::CLogisim_KKLView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CLogisim_KKLView::~CLogisim_KKLView()
{
}

BOOL CLogisim_KKLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CLogisim_KKLView 그리기

void CLogisim_KKLView::OnDraw(CDC* pDC)
{
	CLogisim_KKLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	//좌표 표현
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


	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CLogisim_KKLView 진단

#ifdef _DEBUG
void CLogisim_KKLView::AssertValid() const
{
	CView::AssertValid();
}

void CLogisim_KKLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLogisim_KKLDoc* CLogisim_KKLView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLogisim_KKLDoc)));
	return (CLogisim_KKLDoc*)m_pDocument;
}
#endif //_DEBUG



void CLogisim_KKLView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CView::OnLButtonDown(nFlags, point);
}


void CLogisim_KKLView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	ANDGATE and(point);
	and.Paint(dc);

	CView::OnLButtonUp(nFlags, point);
}




void CLogisim_KKLView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	BITLAMP b(point);
	b.Rotate(dc, point,360);

	CView::OnRButtonUp(nFlags, point);
}
