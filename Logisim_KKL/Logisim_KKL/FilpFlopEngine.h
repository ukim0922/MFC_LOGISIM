//#pragma once
//#include "LogicEngine.h"
//#include "MainFrm.h"
//
//class FilpFlopEngine : public LogicEngine
//{
//public:
//	InOutValues clk;
//
//	//CMainFrame *pFrame_clock_pre = (CMainFrame *)AfxGetMainWnd();
//	//CMainFrame *pFrame_clock_cur = (CMainFrame *)AfxGetMainWnd();
//	//CMainFrame *pFrame_h_ck = (CMainFrame *)AfxGetMainWnd();
//	
//
//	bool clock_pre /*= pFrame_clock_pre->m_pLogisimView->clock_pre;*/;
//	bool clock_cur /*= pFrame_clock_cur->m_pLogisimView->clock_cur;*/;
//	bool h_ck /*= pFrame_h_ck->m_pLogisimView->h_ck;*/;
//
//	CLogisim_KKLView*  m_pLogisimView;
//	CGateTreeView*	   m_pTreeView;
//	
//	void SetInOutValues(Gdiplus::REAL angle);
//	//플립플롭 기능 구현
//	void FlipFlopLogic();
//
//	FilpFlopEngine();
//	FilpFlopEngine(CPoint MPoint, UINT BITMAPID) {
//		this->MPoint = MPoint;
//		this->BITMAPID = BITMAPID;
//	}
//	~FilpFlopEngine();
//	void Paint(CClientDC & dc);
//	void Rotate(CClientDC & dc, Gdiplus::REAL angle);
//};
//
//
////플립플롭
//class DFF : public FilpFlopEngine {
//public:
//	DFF() {};
//	~DFF() {};
//	DFF(CPoint MPoint, UINT BITMAPID) : FilpFlopEngine(MPoint, BITMAPID) {
//		this->gatenumber = D_FF;
//	}
//	void FlipFlopLogic();
//
//};
//
//class TFF : public FilpFlopEngine {
//public:
//	TFF() {};
//	~TFF() {};
//	TFF(CPoint MPoint, UINT BITMAPID) : FilpFlopEngine(MPoint, BITMAPID) {
//		this->gatenumber = T_FF;
//	}
//	void FlipFlopLogic();
//};
//
//class JKFF : public FilpFlopEngine {
//public:
//	JKFF() {};
//	~JKFF() {};
//	JKFF(CPoint MPoint, UINT BITMAPID) : FilpFlopEngine(MPoint, BITMAPID) {
//		this->gatenumber = JK_FF;
//	}
//	void FlipFlopLogic();
//};