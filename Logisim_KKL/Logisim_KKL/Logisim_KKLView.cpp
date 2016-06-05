
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

CArray < Line, Line& > LineArray;
Line* temp;
int check_line(CPoint point)
{
	int array_size = LineArray.GetSize();
	for (int i = 0; i < array_size; i++)
	{
		if (PtInRect(LineArray.GetAt(i).rect, point))
			return i;
	}
	return -1;
}

bool CLogisim_KKLView::check_OutputArray(CPoint point, Line& temp)
{
	for (int i = 0; i < andgates.GetSize(); i++)
	{
		if (PtInRect(andgates.GetAt(i).output[0].rectState, point))
			temp.statu = andgates.GetAt(i).output[0].boolState;
			return true;
		
	}
	for (int i = 0; i < orgates.GetSize(); i++)
	{
		if (PtInRect(orgates.GetAt(i).output[0].rectState, point))
			temp.statu = orgates.GetAt(i).output[0].boolState;
			return true;

	}
	for (int i = 0; i < notgates.GetSize(); i++)
	{
		if (PtInRect(notgates.GetAt(i).output[0].rectState, point))
			temp.statu = notgates.GetAt(i).output[0].boolState;
			return true;

	}
	for (int i = 0; i < norgates.GetSize(); i++)
	{
		if (PtInRect(norgates.GetAt(i).output[0].rectState, point))
			temp.statu = norgates.GetAt(i).output[0].boolState;
			return true;

	}
	for (int i = 0; i < nandgates.GetSize(); i++)
	{
		if (PtInRect(nandgates.GetAt(i).output[0].rectState, point))
			temp.statu = nandgates.GetAt(i).output[0].boolState;
			return true;

	}
	for (int i = 0; i <xorgates.GetSize(); i++)
	{
		if (PtInRect(xorgates.GetAt(i).output[0].rectState, point))
			temp.statu = xorgates.GetAt(i).output[0].boolState;
		return true;

	}
	return false;
}
bool CLogisim_KKLView:: check_InputArray(CPoint point, Line& temp)
{
	return false;
}

//int check_InputArray()
//{
//
//}


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
	if(gatename == "")
	{
		temp = new Line;
		//LineArray.Add(*temp);
		temp->start_pt = point;

		
		m_prev_pos.x = point.x;
		m_prev_pos.y = point.y;
		//int index = check_line(point);


		if (check_OutputArray(point, *temp)) //게이트들만 , 플립플롭 영역 따로 해야함
		{                                    //플립플롭 output영역.  input영역, 클럭 영역
			mouse_check = true;
		}
		else if (check_line(point) >= 0)
		{
			(*temp).statu = LineArray.GetAt(check_line(point)).statu;
			mouse_check = true;
		}
		
	}
	

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
	
	if (mouse_check)
	{
	mouse_check = false;
	(*temp).desti_pt = point;

		if (PtInRect(andgates.GetAt(0).input[0].rectState, point))
		{
			andgates.GetAt(0).input[0].boolState = (*temp).statu;
		}
		else if (PtInRect(andgates.GetAt(0).input[1].rectState, point))
		{
			andgates.GetAt(0).input[1].boolState = (*temp).statu;
		}

		(*temp).setLineRect();
		LineArray.Add(*temp);
	}
	

	CClientDC dc(this);
	LogicEngine* gate;
	ANDGATE* and;
	ORGATE* or ;
	NOTGATE* not;
	NANDGATE* nand;
	NORGATE* nor;
	XORGATE* xor;

	CLOCK_SIGNAL* clock;
	BITINPUT* bitinput;
	BITLAMP* lamp;


	if(selected){
		if (gatename == "AND") {
			and = new ANDGATE(point,IDB_BITMAP_AND);
			andgates.Add(*and);
			and->Paint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "OR") {
			or = new ORGATE(point, IDB_BITMAP_OR);
			orgates.Add(*or );
			or ->Paint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "NOT") {
			not = new NOTGATE(point,IDB_BITMAP_NOT);
			notgates.Add(*not);
			not->SmallPaint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "NAND") {
			nand = new NANDGATE(point, IDB_BITMAP_NAND);
			nandgates.Add(*nand);
			nand->Paint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "NOR") {
			nor = new NORGATE(point, IDB_BITMAP_NOR);
			norgates.Add(*nor);
			nor->Paint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "XOR") {
			xor = new XORGATE(point, IDB_BITMAP_XOR);
			xorgates.Add(*xor);
			xor->Paint(dc);
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
			lamp = new BITLAMP(point, IDB_BITMAP_LON);
			lamps.Add(*lamp);
			lamp->SmallPaint(dc);
			lamp->PrintLabel(dc,gatename);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "입력") {
			bitinput = new BITINPUT(point, IDB_BITMAP_BITINPUT_0);
			bitinputs.Add(*bitinput);
			bitinput->SmallPaint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "CLK") {
			clock = new CLOCK_SIGNAL(point, IDB_BITMAP_CLK0);
			clocks.Add(*clock);
			clock->SmallPaint(dc);
			gatename = "";
			selected = FALSE;
		}
		/*else if (gatename == "7-segment") {
			gate = new Seven(point, );
			gates.Add(*gate);
			gate->SmallPaint(dc);
			gatename = "";
			selected = FALSE;
		}
		*/
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
	if (mouse_check)
	{
		if (point.x == m_prev_pos.x || point.y == m_prev_pos.y)
		{
			dc.MoveTo(m_prev_pos.x, m_prev_pos.y);
			dc.LineTo(point.x, point.y);
			m_prev_pos = point;
		}
		
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
