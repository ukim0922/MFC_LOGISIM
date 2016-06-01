
// Logisim_KKLView.h : CLogisim_KKLView 클래스의 인터페이스
//

#pragma once


class CLogisim_KKLView : public CView
{
protected: // serialization에서만 만들어집니다.
	CLogisim_KKLView();
	DECLARE_DYNCREATE(CLogisim_KKLView)

// 특성입니다.
public:
	CLogisim_KKLDoc* GetDocument() const;
	int x; // 
	int y; //

// 작업입니다. 
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CLogisim_KKLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CArray<CPoint, CPoint&> locPoint;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Logisim_KKLView.cpp의 디버그 버전//
inline CLogisim_KKLDoc* CLogisim_KKLView::GetDocument() const
   { return reinterpret_cast<CLogisim_KKLDoc*>(m_pDocument); }
#endif

