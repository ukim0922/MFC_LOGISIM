// LogisimTree.cpp : 구현 파일입니다.
//

#include "stdafx.h"

#include "Logisim_KKLDoc.h"
#include "Logisim_KKL.h"
#include "LogisimTree.h"


// CLogisimTree

IMPLEMENT_DYNCREATE(CLogisimTree, CView)

CLogisimTree::CLogisimTree()
{

}

CLogisimTree::~CLogisimTree()
{
}

BEGIN_MESSAGE_MAP(CLogisimTree, CView)
END_MESSAGE_MAP()


// CLogisimTree 그리기입니다.

void CLogisimTree::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	CRect rect;
	GetClientRect(rect);
	CSize size1(MulDiv(rect.Width(), 20, 150), ::GetSystemMetrics(SM_CYSCREEN)); // 폭(20%)

	// 트리 컨트롤 생성
	Library.Create(WS_CHILD | WS_VISIBLE | WS_BORDER |
		TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT,rect, this, IDC_TREE1);

	//// 이미지 리스트 생성과 초기화
	//CImageList il;
	//il.Create(IDB_BITMAP1, 16, 16, RGB(255, 255, 255));

	//// 이미지 리스트 설정
	//Library.SetImageList(&il, TVSIL_NORMAL);
	//il.Detach();

	// 항목 추가
	/*1레벨 초기화*/
	HTREEITEM hGATE = Library.InsertItem(_T("GATE"), 0, 0, TVI_ROOT, TVI_LAST);
	HTREEITEM hFF = Library.InsertItem(_T("Flip-Flop"), 0, 0, TVI_ROOT, TVI_LAST);
	
	/*2레벨 초기화*/
	HTREEITEM hGATES[6];
	HTREEITEM hFFS[3];
	CString gates[] = {
		_T("AND"), _T("OR"),_T("NOT"),_T("NAND"),_T("NOR"),_T("XOR")
	};
	CString filpflop[] = {
		_T("D-FF"),_T("JK-FF"),_T("T-FF")
	};
	for (int i = 0; i < 6; i++) {
		hGATES[i] = Library.InsertItem(gates[i], 1, 1, hGATE, TVI_LAST);
	}
	for (int i = 0; i < 3; i++) {
		hFFS[i] = Library.InsertItem(filpflop[i], 1, 1, hFF, TVI_LAST);
	}


	/*3레벨 초기화*/

	// TODO: 여기에 그리기 코드를 추가합니다.
}


// CLogisimTree 진단입니다.

#ifdef _DEBUG
void CLogisimTree::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CLogisimTree::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLogisimTree 메시지 처리기입니다.
