#pragma once

#define IDC_TREE1 100
// CLogisimTree 뷰입니다.

class CLogisimTree : public CView
{
	DECLARE_DYNCREATE(CLogisimTree)

protected:
	CLogisimTree();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CLogisimTree();

public:

	virtual void OnDraw(CDC* pDC);      // 이 뷰를 그리기 위해 재정의되었습니다.
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


