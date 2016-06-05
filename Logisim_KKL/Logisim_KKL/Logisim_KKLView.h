
// Logisim_KKLView.h : CLogisim_KKLView Ŭ������ �������̽�
//
#include "LogicEngine.h"
//#include "FilpFlopEngine.h"
#include "Line.h"
#pragma once
class CLogisim_KKLView : public CView
{
protected: // serialization������ ��������ϴ�.
	CLogisim_KKLView();
	DECLARE_DYNCREATE(CLogisim_KKLView)

// Ư���Դϴ�.
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


	bool mouse_check = false;  //���콺 �巡�׵� ���� üũ
	CPoint m_prev_pos; //�巡�� ���� ��ǥ ����
	CPoint m_start_pos;
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
	//bool clock_pre; //Ŭ������
	//bool clock_cur;
	bool h_ck; //����Ʈ���Ź�� (����̸�true, �ϰ��̸�false) Ŭ�����ι޾ƿÿ���
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnHighTRG();
	afx_msg void OnLowTRG();
	afx_msg void OnUpdateHigh(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLow(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // Logisim_KKLView.cpp�� ����� ����
inline CLogisim_KKLDoc* CLogisim_KKLView::GetDocument() const
   { return reinterpret_cast<CLogisim_KKLDoc*>(m_pDocument); }
#endif

