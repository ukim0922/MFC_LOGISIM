
// Logisim_KKLView.h : CLogisim_KKLView 클래스의 인터페이스
//
#include "LogicEngine.h"
//#include "FilpFlopEngine.h"
#include "Line.h"
#pragma once
class CLogisim_KKLView : public CView
{
protected: // serialization에서만 만들어집니다.
	CLogisim_KKLView();
	DECLARE_DYNCREATE(CLogisim_KKLView)

// 특성입니다.
public:
	bool check_OutputArray(CPoint point, Line& temp);
	bool check_InputArray(CPoint point, Line& temp);
	void rotate(CClientDC & dc, CPoint point);
	CLogisim_KKLDoc* GetDocument() const;
	CArray<LogicEngine, LogicEngine&> gates;
	CArray<ANDGATE, ANDGATE&> andgates;
	CArray<ORGATE, ORGATE&> orgates;
	CArray<NOTGATE, NOTGATE&> notgates;
	CArray<NORGATE, NORGATE&> norgates;
	CArray<XORGATE, XORGATE&> xorgates;
	CArray<NANDGATE, NANDGATE&> nandgates;

	CArray<LogicEngine, LogicEngine&> dffs;
	CArray<LogicEngine, LogicEngine&> tffs;
	CArray<LogicEngine, LogicEngine&> jkffs;

	CArray<CLOCK_SIGNAL, CLOCK_SIGNAL&> clocks;
	CArray<BITINPUT, BITINPUT&> bitinputs;
	CArray<BITLAMP, BITLAMP&> lamps;


	bool mouse_check = false;  //마우스 드래그된 상태 체크
	CPoint m_prev_pos; //드래그 시작 좌표 저장
	CPoint m_start_pos;
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
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	
	bool selected;
	CString gatename;
	//bool clock_pre; //클럭변수
	//bool clock_cur;
	bool h_ck; //에지트리거방식 (상승이면true, 하강이면false) 클릭으로받아올예정
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnHighTRG();
	afx_msg void OnLowTRG();
	afx_msg void OnUpdateHigh(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLow(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // Logisim_KKLView.cpp의 디버그 버전
inline CLogisim_KKLDoc* CLogisim_KKLView::GetDocument() const
   { return reinterpret_cast<CLogisim_KKLDoc*>(m_pDocument); }
#endif

