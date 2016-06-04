
// Logisim_KKLView.cpp : CLogisim_KKLView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Logisim_KKL.h"
#endif

#include "Logisim_KKLDoc.h"
#include "Logisim_KKLView.h"
#include "LogicEngine.h"    //엔진 추가
#include "FilpFlopEngine.h"    //엔진 추가
#include "Line.h" //라인 추가


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLogisim_KKLView

IMPLEMENT_DYNCREATE(CLogisim_KKLView, CView)

BEGIN_MESSAGE_MAP(CLogisim_KKLView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_HIGH, &CLogisim_KKLView::OnHighTRG)
	ON_COMMAND(ID_LOW, &CLogisim_KKLView::OnLowTRG)
	ON_UPDATE_COMMAND_UI(ID_HIGH, &CLogisim_KKLView::OnUpdateHigh)
	ON_UPDATE_COMMAND_UI(ID_LOW, &CLogisim_KKLView::OnUpdateLow)
END_MESSAGE_MAP()

// CLogisim_KKLView 생성/소멸

CLogisim_KKLView::CLogisim_KKLView()
	: gatename(_T(""))
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CLogisim_KKLView::~CLogisim_KKLView()
{
}

BOOL CLogisim_KKLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CLogisim_KKLView 그리기

void CLogisim_KKLView::OnDraw(CDC* pDC)
{
	CLogisim_KKLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	//좌표 표현
	CRect rect;
	GetWindowRect(&rect);
	locPoint.SetSize(0);
	for (int i = 0; i < rect.Width(); i = i + 8) {
		for (int j = 0; j < rect.Height(); j = j + 8) {
			pDC->SetPixelV(i, j, RGB(143, 216, 230));
			locPoint.Add(CPoint(i, j));
		}
	}

	if (!pDoc)
		return;
	//TEST
	BITINPUT a, b;
	a.output[0].boolState = TRUE;
	b.output[0].boolState = FALSE;

	ORGATE c;
	c.input[0].boolState = a.output[0].boolState;
	c.input[1].boolState = b.output[0].boolState;
	c.GateLogic();

	CString str;
	str.Format(_T("output : %d"),c.output[0].boolState);
	//str.Format(_T("Array Size : %d"), gates.GetSize());
	pDC->TextOut(200, 200, str);


	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CLogisim_KKLView 진단

#ifdef _DEBUG
void CLogisim_KKLView::AssertValid() const
{
	CView::AssertValid();
}

void CLogisim_KKLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLogisim_KKLDoc* CLogisim_KKLView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLogisim_KKLDoc)));
	return (CLogisim_KKLDoc*)m_pDocument;
}
#endif //_DEBUG



void CLogisim_KKLView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 눌렀을 때의 flag 및 좌표 저장
	mouse_check = true;
	m_prev_pos.x = point.x;
	m_prev_pos.y = point.y;

	CClientDC dc(this);
	/*if (selected == true) {*/
	dc.TextOut(200, 250, gatename);

	if (selected) {
		dc.TextOutW(200, 300, _T("TRUE"));
	}
	else
		dc.TextOutW(200, 300, _T("FALSE"));


	CView::OnLButtonDown(nFlags, point);
}


void CLogisim_KKLView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//마우스 드래그 flag 변경
	mouse_check = false;
	LogicEngine* gate;
	CClientDC dc(this);

	if(selected){
		if (gatename == "AND") {
			gate = new ANDGATE(point,IDB_BITMAP_AND);
			gates.Add(*gate);
			gate->Paint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "OR") {
			gate = new ORGATE(point, IDB_BITMAP_OR);
			gates.Add(*gate);
			gate->Paint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "NOT") {
			gate = new NOTGATE(point, IDB_BITMAP_NOT);
			gates.Add(*gate);
			gate->SmallPaint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "NAND") {
			gate = new NANDGATE(point, IDB_BITMAP_NAND);
			gates.Add(*gate);
			gate->Paint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "NOR") {
			gate = new NORGATE(point, IDB_BITMAP_NOR);
			gates.Add(*gate);
			gate->Paint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "XOR") {
			gate = new XORGATE(point, IDB_BITMAP_XOR);
			gates.Add(*gate);
			gate->Paint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "D-FF") {
			gate = new DFF(point, IDB_BITMAP_DFF);
			gates.Add(*gate);
			gate->Paint(dc);
			gatename = "";
			selected = FALSE;

		}
		else if (gatename == "JK-FF") {
			gate = new JKFF(point, IDB_BITMAP_JKFF);
			gates.Add(*gate);
			gate->Paint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "T-FF") {
			gate = new TFF(point, IDB_BITMAP_TFF);
			gates.Add(*gate);
			gate->Paint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "LAMP") {
			gate = new BITLAMP(point, IDB_BITMAP_LON);
			gates.Add(*gate);
			gate->SmallPaint(dc);
			gate->PrintLabel(dc,gatename);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "입력") {
			gate = new BITINPUT(point, IDB_BITMAP_BITINPUT_0);
			gates.Add(*gate);
			gate->SmallPaint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "CLK") {
			gate = new CLOCK_SIGNAL(point, IDB_BITMAP_CLK0);
			gates.Add(*gate);
			gate->SmallPaint(dc);
			gatename = "";
			selected = FALSE;
		}
		CView::OnLButtonUp(nFlags, point);
	}
}




void CLogisim_KKLView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	if (gatename == "AND") {
		ANDGATE and (point, IDB_BITMAP_AND);
		and.Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "OR") {
		ORGATE or (point, IDB_BITMAP_OR);
		or .Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "NOT") {
		NOTGATE not (point, IDB_BITMAP_NOT);
		not.Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "NAND") {
		NANDGATE nand(point, IDB_BITMAP_NAND);
		nand.Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "NOR") {
		NORGATE nor(point, IDB_BITMAP_NOR);
		nor.Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "XOR") {
		XORGATE xor (point, IDB_BITMAP_XOR);
		xor.Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "D-FF") {

	}
	else if (gatename == "JK-FF") {

	}
	else if (gatename == "T-FF") {
		TFF tff(point, IDB_BITMAP_TFF);
		tff.Rotate(dc, 90);
		gatename = "";
	}
	else if (gatename == "LAMP") {
		BITLAMP lamp(point, IDB_BITMAP_LON);
		lamp.Rotate(dc, 90);
		gatename = "";
	}
	CView::OnRButtonUp(nFlags, point);
}

void CLogisim_KKLView::OnMouseMove(UINT nFlags, CPoint point)
{

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CClientDC dc(this);
	
	CRect* rect;
	rect = new CRect;
	// 사각형 (m_prev_pos.x-5, m_prev_pos.y-5)(point.x+5, point.y+5) 선 인식, ptinrect 함수 사용
	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = dc.SelectObject(&pen);

	
	if (mouse_check) {
		/*if(연결된단자가 input단자 or output단자) 영역으로 인식
		dc.MoveTo(m_prev_pos.x, m_prev_pos.y);
		dc.LineTo(point.x, point.y);
		m_prev_pos = point;
		구조체 생성 : 사각형 (m_prev_pos.x-5, m_prev_pos.y-5)(point.x+5, point.y+5)
		structure->statu = 단자의 상태;

		else if( struct.rect,ptInRect(point) )  선이 있는 영역-> 사각형. 비교를 모든 사각형으로 해야함..? => 함수를 만들어야함
		
		dc.MoveTo(m_prev_pos.x, m_prev_pos.y);
		dc.LineTo(point.x, point.y);
		m_prev_pos = point;
		구조체 생성 : 사각형 (m_prev_pos.x-5, m_prev_pos.y-5)(point.x+5, point.y+5)
		새로만든 struct.statu = 연결되는 struct.statu;

		*/

		dc.MoveTo(m_prev_pos.x, m_prev_pos.y);
		dc.LineTo(point.x, point.y);
		m_prev_pos = point;
	}

	
	CView::OnMouseMove(nFlags, point);
}


void CLogisim_KKLView::OnHighTRG()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	h_ck = true;
}


void CLogisim_KKLView::OnLowTRG()
{
	h_ck = false;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CLogisim_KKLView::OnUpdateHigh(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(h_ck == true);
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
}


void CLogisim_KKLView::OnUpdateLow(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(h_ck == false);
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
}
