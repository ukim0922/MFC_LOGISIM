#pragma once

#define IDC_TREE1 100
// CLogisimTree ���Դϴ�.

class CLogisimTree : public CView
{
	DECLARE_DYNCREATE(CLogisimTree)

protected:
	CLogisimTree();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CLogisimTree();

public:

	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl Library;
};


