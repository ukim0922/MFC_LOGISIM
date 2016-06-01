// GateTreeView.cpp : ���� �����Դϴ�.
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
//	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CGateTreeView::OnTvnSelchanged)
	ON_NOTIFY_REFLECT(TVN_SELCHANGING, &CGateTreeView::OnTvnSelchanging)
END_MESSAGE_MAP()


// CGateTreeView �����Դϴ�.

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


// CGateTreeView �޽��� ó�����Դϴ�.


int CGateTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	CTreeCtrl& tree = GetTreeCtrl();

	//// �̹��� ����Ʈ ������ �ʱ�ȭ
	//CImageList il;
	//il.Create(IDB_BITMAP1, 16, 16, RGB(255, 255, 255));

	//// �̹��� ����Ʈ ����
	//Library.SetImageList(&il, TVSIL_NORMAL);
	//il.Detach();

	// �׸� �߰�
	/*1���� �ʱ�ȭ*/
	HTREEITEM hGATE = tree.InsertItem(_T("GATE"), 0, 0, TVI_ROOT, TVI_LAST);
	HTREEITEM hFF = tree.InsertItem(_T("Flip-Flop"), 0, 0, TVI_ROOT, TVI_LAST);

	/*2���� �ʱ�ȭ*/
	HTREEITEM hGATES[6];
	HTREEITEM hFFS[3];
	CString gates[] = {
		_T("AND"), _T("OR"),_T("NOT"),_T("NAND"),_T("NOR"),_T("XOR")
	};
	CString filpflop[] = {
		_T("D-FF"),_T("JK-FF"),_T("T-FF")
	};
	for (int i = 0; i < 6; i++) {
		hGATES[i] = tree.InsertItem(gates[i], 1, 1, hGATE, TVI_LAST);

	}
	for (int i = 0; i < 3; i++) {
		hFFS[i] = tree.InsertItem(filpflop[i], 1, 1, hFF, TVI_LAST);

	}
	return 0;
}


BOOL CGateTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	cs.style |= WS_CHILD | WS_VISIBLE | WS_BORDER |
		TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT;
	return CTreeView::PreCreateWindow(cs);
}


//void CGateTreeView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
//	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//
//	
//	*pResult = 0;
//}


void CGateTreeView::OnTvnSelchanging(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CTreeCtrl & tree = GetTreeCtrl();
	HTREEITEM hItem = tree.GetSelectedItem();

	CString str = tree.GetItemText(hItem);

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->m_pLogisimView->gatename = str;

	*pResult = 0;
}
