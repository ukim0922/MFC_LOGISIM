
// LogiSim_KKLView.h : CLogiSim_KKLView Ŭ������ �������̽�
//

#pragma once


class CLogiSim_KKLView : public CView
{
protected: // serialization������ ��������ϴ�.
	CLogiSim_KKLView();
	DECLARE_DYNCREATE(CLogiSim_KKLView)

// Ư���Դϴ�.
public:
	CLogiSim_KKLDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CLogiSim_KKLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // LogiSim_KKLView.cpp�� ����� ����
inline CLogiSim_KKLDoc* CLogiSim_KKLView::GetDocument() const
   { return reinterpret_cast<CLogiSim_KKLDoc*>(m_pDocument); }
#endif

