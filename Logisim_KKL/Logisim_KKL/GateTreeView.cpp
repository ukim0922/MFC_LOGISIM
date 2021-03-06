// GateTreeView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Logisim_KKL.h"
#include "GateTreeView.h"
#include "MainFrm.h"


// CGateTreeView

IMPLEMENT_DYNCREATE(CGateTreeView, CTreeView)

CGateTreeView::CGateTreeView()
{

}

CGateTreeView::~CGateTreeView()
{
}

BEGIN_MESSAGE_MAP(CGateTreeView, CTreeView)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(TVN_SELCHANGING, &CGateTreeView::OnTvnSelchanging)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CGateTreeView::OnTvnSelchanged)
	ON_NOTIFY_REFLECT(NM_CLICK, &CGateTreeView::OnNMClick)
END_MESSAGE_MAP()


// CGateTreeView 진단입니다.

#ifdef _DEBUG
void CGateTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CGateTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CGateTreeView 메시지 처리기입니다.


int CGateTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	CTreeCtrl& tree = GetTreeCtrl();

	//// 이미지 리스트 생성과 초기화
	//CImageList il;
	//il.Create(IDB_BITMAP1, 16, 16, RGB(255, 255, 255));

	//// 이미지 리스트 설정
	//Library.SetImageList(&il, TVSIL_NORMAL);
	//il.Detach();

	// 항목 추가
	/*1레벨 초기화*/
	HTREEITEM hGATE = tree.InsertItem(_T("GATE"), 0, 0, TVI_ROOT, TVI_LAST);
	tree.InsertItem(_T("AND"), 1, 1, hGATE, TVI_LAST);
	tree.InsertItem(_T("OR"), 1, 1, hGATE, TVI_LAST);
	tree.InsertItem(_T("NOT"), 1, 1, hGATE, TVI_LAST);
	tree.InsertItem(_T("NAND"), 1, 1, hGATE, TVI_LAST);
	tree.InsertItem(_T("NOR"), 1, 1, hGATE, TVI_LAST);
	tree.InsertItem(_T("XOR"), 1, 1, hGATE, TVI_LAST);

	HTREEITEM hFF = tree.InsertItem(_T("Flip-Flop"), 0, 0, TVI_ROOT, TVI_LAST);
	tree.InsertItem(_T("D-FF"), 1, 1, hFF, TVI_LAST);
	tree.InsertItem(_T("JK-FF"), 1, 1, hFF, TVI_LAST);
	tree.InsertItem(_T("T-FF"), 1, 1, hFF, TVI_LAST);

	HTREEITEM hINPUT = tree.InsertItem(_T("IN-PUT"), 0, 0, TVI_ROOT, TVI_LAST);
	tree.InsertItem(_T("Input"), 1, 1, hINPUT, TVI_LAST);
	tree.InsertItem(_T("CLK"), 1, 1, hINPUT, TVI_LAST);

	HTREEITEM hOUTPUT = tree.InsertItem(_T("OUT-PUT"), 0, 0, TVI_ROOT, TVI_LAST);
	tree.InsertItem(_T("LAMP"), 1, 1, hOUTPUT, TVI_LAST);
	tree.InsertItem(_T("7-segment"), 1, 1, hOUTPUT, TVI_LAST);


	tree.Expand(hGATE, TVE_EXPAND);
	tree.Expand(hFF, TVE_EXPAND);		
	tree.Expand(hINPUT, TVE_EXPAND);

	return 0;
}


BOOL CGateTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	cs.style |= WS_CHILD | WS_VISIBLE | WS_BORDER |
		TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT;
	return CTreeView::PreCreateWindow(cs);
}



void CGateTreeView::OnTvnSelchanging(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	*pResult = 0;
}


void CGateTreeView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CTreeCtrl & tree = GetTreeCtrl();
	HTREEITEM hItem = tree.GetSelectedItem();

	CString str = tree.GetItemText(hItem);

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	pFrame->m_pLogisimView->gatename = str;

	*pResult = 0;
}


void CGateTreeView::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CTreeCtrl & tree = GetTreeCtrl();
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->m_pLogisimView->selected = TRUE;

	*pResult = 0;
}
