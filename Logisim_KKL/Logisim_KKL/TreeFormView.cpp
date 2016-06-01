// TreeFormView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Logisim_KKL.h"
#include "TreeFormView.h"


// CTreeFormView

IMPLEMENT_DYNCREATE(CTreeFormView, CFormView)

CTreeFormView::CTreeFormView()
	: CFormView(IDD_TREEFORMVIEW)
{

}

CTreeFormView::~CTreeFormView()
{
}

void CTreeFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTreeFormView, CFormView)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CTreeFormView::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// CTreeFormView �����Դϴ�.

#ifdef _DEBUG
void CTreeFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CTreeFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CTreeFormView �޽��� ó�����Դϴ�.


void CTreeFormView::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}
