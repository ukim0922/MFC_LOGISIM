#include "stdafx.h"
#include "FixedSplitterWnd.h"

BEGIN_MESSAGE_MAP(CFixedSplitterWnd, CSplitterWnd)
	//{{AFX_MSG_MAP(CFixedSplitterWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
//////////////////////////////////////////////////////////////////////
//CFixedSplitterWnd message handlers
void CFixedSplitterWnd::OnMouseMove(UINT nFlags, CPoint point) {
	// TODO:
	// �⺻������ ���ǵ� �Լ��� CSplitterWnd::OnMOuseMove(nFlag, point)�̴�.
	CWnd::OnMouseMove(nFlags, point); // �ƹ� �ϵ� ���� �ʴ´�.
}

void CFixedSplitterWnd::OnLButtonDown(UINT nFlags, CPoint point) {
	// TODO:
	CWnd::OnLButtonDown(nFlags, point);
}

void CFixedSplitterWnd::OnLButtonUp(UINT nFlags, CPoint point) {
	// TODO:
	CWnd::OnLButtonUp(nFlags, point);
}

void CFixedSplitterWnd::OnLButtonDblClk(UINT nFlags, CPoint point) {
	// TODO:
	CWnd::OnLButtonDblClk(nFlags, point);
}