
// LogiSim_KKLView.cpp : CLogiSim_KKLView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "LogiSim_KKL.h"
#endif

#include "LogiSim_KKLDoc.h"
#include "LogiSim_KKLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLogiSim_KKLView

IMPLEMENT_DYNCREATE(CLogiSim_KKLView, CView)

BEGIN_MESSAGE_MAP(CLogiSim_KKLView, CView)
END_MESSAGE_MAP()

// CLogiSim_KKLView ����/�Ҹ�

CLogiSim_KKLView::CLogiSim_KKLView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CLogiSim_KKLView::~CLogiSim_KKLView()
{
}

BOOL CLogiSim_KKLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CLogiSim_KKLView �׸���

void CLogiSim_KKLView::OnDraw(CDC* /*pDC*/)
{
	CLogiSim_KKLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	TextOut(NULL, 100, 100, _T("Hello KKL World!"), 1);
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CLogiSim_KKLView ����

#ifdef _DEBUG
void CLogiSim_KKLView::AssertValid() const
{
	CView::AssertValid();
}

void CLogiSim_KKLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLogiSim_KKLDoc* CLogiSim_KKLView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLogiSim_KKLDoc)));
	return (CLogiSim_KKLDoc*)m_pDocument;
}
#endif //_DEBUG


// CLogiSim_KKLView �޽��� ó����
