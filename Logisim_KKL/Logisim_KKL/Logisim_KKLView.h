
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
	bool mouse_check = false;  //���콺 �巡�׵� ���� üũ
	CPoint m_prev_pos; //�巡�� ���� ��ǥ ����
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
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	
	bool selected;
	CString gatename;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Logisim_KKLView.cpp�� ����� ����
inline CLogisim_KKLDoc* CLogisim_KKLView::GetDocument() const
   { return reinterpret_cast<CLogisim_KKLDoc*>(m_pDocument); }
#endif

