
// Logisim_KKLView.h : CLogisim_KKLView Ŭ������ �������̽�
//

#pragma once


class CLogisim_KKLView : public CView
{
protected: // serialization������ ��������ϴ�.
	CLogisim_KKLView();
	DECLARE_DYNCREATE(CLogisim_KKLView)

// Ư���Դϴ�.
public:
	CLogisim_KKLDoc* GetDocument() const;
	int x; // 
	int y; //

// �۾��Դϴ�. 
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CLogisim_KKLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CArray<CPoint, CPoint&> locPoint;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Logisim_KKLView.cpp�� ����� ����//
inline CLogisim_KKLDoc* CLogisim_KKLView::GetDocument() const
   { return reinterpret_cast<CLogisim_KKLDoc*>(m_pDocument); }
#endif

