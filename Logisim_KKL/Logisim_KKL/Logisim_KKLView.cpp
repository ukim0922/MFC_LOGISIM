
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

int CLogisim_KKLView::check_line(CPoint point)
{
	int array_size = LineArray.GetSize();
	for (int i = 0; i < array_size; i++)
	{
		if (PtInRect(LineArray.GetAt(i).rect, point))
			selected_point = LineArray.GetAt(i).rect.CenterPoint();
			return i;
	}
	return -1;
}
bool CLogisim_KKLView::check_OutputArray(CPoint point, Line& temp)
{
	//게이트
	for (int i = 0; i < andgates.GetSize(); i++)
	{
		if (PtInRect(andgates.GetAt(i).output[0].rectState, point))
		{
			temp.statu = andgates.GetAt(i).output[0].boolState;
			selected_point = andgates.GetAt(i).output[0].pointState;
			return true;
		}
		
	}
	for (int i = 0; i < orgates.GetSize(); i++)
	{
		if (PtInRect(orgates.GetAt(i).output[0].rectState, point))
		{
			temp.statu = orgates.GetAt(i).output[0].boolState;
			selected_point = orgates.GetAt(i).output[0].pointState;
			return true;
		}
	}
	for (int i = 0; i < notgates.GetSize(); i++)
	{
		if (PtInRect(notgates.GetAt(i).output[0].rectState, point))
		{
			temp.statu = notgates.GetAt(i).output[0].boolState;
			selected_point = notgates.GetAt(i).output[0].pointState;
			return true;
		}

	}
	for (int i = 0; i < norgates.GetSize(); i++)
	{
		if (PtInRect(norgates.GetAt(i).output[0].rectState, point))
		{
			temp.statu = norgates.GetAt(i).output[0].boolState;
			selected_point = norgates.GetAt(i).output[0].pointState;
			return true;
		}

	}
	for (int i = 0; i < nandgates.GetSize(); i++)
	{
		if (PtInRect(nandgates.GetAt(i).output[0].rectState, point))
		{
			temp.statu = nandgates.GetAt(i).output[0].boolState;
			selected_point = nandgates.GetAt(i).output[0].pointState;
			return true;
		}

	}
	for (int i = 0; i <xorgates.GetSize(); i++)
	{
		if (PtInRect(xorgates.GetAt(i).output[0].rectState, point))
		{
			temp.statu = xorgates.GetAt(i).output[0].boolState;
			selected_point = xorgates.GetAt(i).output[0].pointState;
			return true;
		}

	}
	//플립플롭
	for (int i = 0; i <dffs.GetSize(); i++)
	{
		if (PtInRect(dffs.GetAt(i).output[0].rectState, point))
		{
			temp.statu = dffs.GetAt(i).output[0].boolState;
			selected_point = dffs.GetAt(i).output[0].pointState;
			return true;
		}
		else if (PtInRect(dffs.GetAt(i).output[1].rectState, point))
		{
			temp.statu = dffs.GetAt(i).output[1].boolState;
			selected_point = dffs.GetAt(i).output[0].pointState;
			return true;
		}

	}
	for (int i = 0; i <tffs.GetSize(); i++)
	{
		if (PtInRect(tffs.GetAt(i).output[0].rectState, point))
		{
			temp.statu = tffs.GetAt(i).output[0].boolState;
			selected_point = tffs.GetAt(i).output[0].pointState;
			return true;
		}
		else if (PtInRect(tffs.GetAt(i).output[1].rectState, point))
		{
			temp.statu = tffs.GetAt(i).output[1].boolState;
			selected_point = tffs.GetAt(i).output[0].pointState;
			return true;
		}

	}
	for (int i = 0; i <jkffs.GetSize(); i++)
	{
		if (PtInRect(jkffs.GetAt(i).output[0].rectState, point))
		{
			temp.statu = jkffs.GetAt(i).output[0].boolState;
			selected_point = jkffs.GetAt(i).output[0].pointState;
			return true;
		}
		else if (PtInRect(jkffs.GetAt(i).output[1].rectState, point))
		{
			temp.statu = jkffs.GetAt(i).output[1].boolState;
			selected_point = jkffs.GetAt(i).output[0].pointState;
			return true;
		}

	}
	//입력, 클럭
	for (int i = 0; i <clocks.GetSize(); i++)
	{
		if (PtInRect(clocks.GetAt(i).output[0].rectState, point))
		{
			temp.statu = clocks.GetAt(i).output[0].boolState;
			selected_point = clocks.GetAt(i).output[0].pointState;
			return true;
		}

	}
	for (int i = 0; i <bitinputs.GetSize(); i++)
	{
		if (PtInRect(bitinputs.GetAt(i).output[0].rectState, point))
		{
			temp.statu = bitinputs.GetAt(i).output[0].boolState;
			selected_point = bitinputs.GetAt(i).output[0].pointState;
			return true;
		}

	}
	return false;
}

bool CLogisim_KKLView:: check_InputArray(CPoint point, Line& temp)
{
	//게이트
	for (int i = 0; i < andgates.GetSize(); i++)
	{
		if (PtInRect(andgates.GetAt(i).input[0].rectState, point))
		{
			andgates.GetAt(i).input[0].boolState = temp.statu;
			return true;
		}
		else if (PtInRect(andgates.GetAt(i).input[1].rectState, point))
		{
			andgates.GetAt(i).input[1].boolState = temp.statu;
			return true;
		}
	}
	for (int i = 0; i < orgates.GetSize(); i++)
	{
		if (PtInRect(orgates.GetAt(i).output[0].rectState, point))
		{
			orgates.GetAt(i).input[0].boolState = temp.statu;
			return true;
		}
		else if (PtInRect(orgates.GetAt(i).input[1].rectState, point))
		{
			orgates.GetAt(i).input[1].boolState = temp.statu;
			return true;
		}
	}
	for (int i = 0; i < notgates.GetSize(); i++)
	{
		if (PtInRect(notgates.GetAt(i).output[0].rectState, point))
		{
			notgates.GetAt(i).input[0].boolState = temp.statu;
			return true;
		}
		else if (PtInRect(notgates.GetAt(i).input[1].rectState, point))
		{
			notgates.GetAt(i).input[1].boolState = temp.statu;
			return true;
		}
	}
	for (int i = 0; i < norgates.GetSize(); i++)
	{
		if (PtInRect(norgates.GetAt(i).input[0].rectState, point))
		{
			norgates.GetAt(i).input[0].boolState = temp.statu;
			return true;
		}
		else if (PtInRect(norgates.GetAt(i).input[1].rectState, point))
		{
			norgates.GetAt(i).input[1].boolState = temp.statu;
			return true;
		}

	}
	for (int i = 0; i < nandgates.GetSize(); i++)
	{
		if (PtInRect(nandgates.GetAt(i).input[0].rectState, point))
		{
			nandgates.GetAt(i).input[0].boolState = temp.statu;
			return true;
		}
		else if (PtInRect(nandgates.GetAt(i).input[1].rectState, point))
		{
			nandgates.GetAt(i).input[1].boolState = temp.statu;
			return true;
		}

	}
	for (int i = 0; i <xorgates.GetSize(); i++)
	{
		if (PtInRect(xorgates.GetAt(i).input[0].rectState, point))
		{
			xorgates.GetAt(i).input[0].boolState = temp.statu;
			return true;
		}
		else if (PtInRect(xorgates.GetAt(i).input[1].rectState, point))
		{
			xorgates.GetAt(i).input[1].boolState = temp.statu;
			return true;
		}

	}
	//플립플롭
	for (int i = 0; i <dffs.GetSize(); i++)
	{
		if (PtInRect(dffs.GetAt(i).input[0].rectState, point))
		{
			dffs.GetAt(i).input[0].boolState = temp.statu;
			return true;
		}
		else if (PtInRect(dffs.GetAt(i).input[1].rectState, point))		//clk
		{
			dffs.GetAt(i).input[1].boolState = temp.statu;
			return true;
		}

	}
	for (int i = 0; i <tffs.GetSize(); i++)
	{
		if (PtInRect(tffs.GetAt(i).input[0].rectState, point))			//clk
		{
			tffs.GetAt(i).input[0].boolState = temp.statu;
			return true;
		}
		else if (PtInRect(tffs.GetAt(i).input[1].rectState, point))
		{
			tffs.GetAt(i).input[1].boolState = temp.statu;
			return true;
		}

	}
	for (int i = 0; i <jkffs.GetSize(); i++)
	{
		if (PtInRect(jkffs.GetAt(i).input[0].rectState, point))
		{
			jkffs.GetAt(i).input[0].boolState = temp.statu;
			return true;
		}
		else if (PtInRect(jkffs.GetAt(i).input[1].rectState, point))
		{
			jkffs.GetAt(i).input[1].boolState = temp.statu;
			return true;
		}
		else if (PtInRect(jkffs.GetAt(i).input[1].rectState, point))	//clk
		{
			jkffs.GetAt(i).input[1].boolState = temp.statu;
			return true;
		}

	}
	//출력
	for (int i = 0; i <lamps.GetSize(); i++)
	{
		if (PtInRect(lamps.GetAt(i).input[0].rectState, point))
		{
			lamps.GetAt(i).input[0].boolState = temp.statu;
			return true;
		}

	}
	return false;
}

void CLogisim_KKLView::rotate(CClientDC & dc, CPoint point) {
	//게이트일 때
	for (int i = 0; i < andgates.GetSize(); i++)
	{
		if (PtInRect(andgates.GetAt(i).MRect, point)) {
			andgates.GetAt(i).angle += 90;
			andgates.GetAt(i).Rotate(dc, andgates.GetAt(i).angle);
			andgates.GetAt(i).SetInOutValues(andgates.GetAt(i).angle);
		}
	}
	for (int i = 0; i < orgates.GetSize(); i++)
	{
		if (PtInRect(orgates.GetAt(i).MRect, point)) {
			orgates.GetAt(i).angle += 90;
			orgates.GetAt(i).Rotate(dc, orgates.GetAt(i).angle);
			orgates.GetAt(i).SetInOutValues(orgates.GetAt(i).angle);
		}
	}
	for (int i = 0; i < notgates.GetSize(); i++)
	{
		if (PtInRect(notgates.GetAt(i).MRect, point)) {
			notgates.GetAt(i).angle += 90;
			notgates.GetAt(i).SmallRotate(dc, notgates.GetAt(i).angle);
			notgates.GetAt(i).SetInOutValues(notgates.GetAt(i).angle);
		}
	}
	for (int i = 0; i < norgates.GetSize(); i++)
	{
		if (PtInRect(norgates.GetAt(i).MRect, point)) {
			norgates.GetAt(i).angle += 90;
			norgates.GetAt(i).Rotate(dc, norgates.GetAt(i).angle);
			norgates.GetAt(i).SetInOutValues(norgates.GetAt(i).angle);
		}
	}
	for (int i = 0; i < nandgates.GetSize(); i++)
	{
		if (PtInRect(nandgates.GetAt(i).MRect, point)) {
			nandgates.GetAt(i).angle += 90;
			nandgates.GetAt(i).Rotate(dc, nandgates.GetAt(i).angle);
			nandgates.GetAt(i).SetInOutValues(nandgates.GetAt(i).angle);
		}
	}
	for (int i = 0; i <xorgates.GetSize(); i++)
	{
		if (PtInRect(xorgates.GetAt(i).MRect, point)) {
			xorgates.GetAt(i).angle += 90;
			xorgates.GetAt(i).Rotate(dc, xorgates.GetAt(i).angle);
			xorgates.GetAt(i).SetInOutValues(xorgates.GetAt(i).angle);
		}
	}
	//플립플롭일 때
	for (int i = 0; i <tffs.GetSize(); i++)
	{
		if (PtInRect(tffs.GetAt(i).MRect, point)) {
			tffs.GetAt(i).angle += 90;
			tffs.GetAt(i).Rotate(dc, tffs.GetAt(i).angle);
			tffs.GetAt(i).SetInOutValues(tffs.GetAt(i).angle);
		}
	}
	for (int i = 0; i <dffs.GetSize(); i++)
	{
		if (PtInRect(dffs.GetAt(i).MRect, point)) {
			dffs.GetAt(i).angle += 90;
			dffs.GetAt(i).Rotate(dc, dffs.GetAt(i).angle);
			dffs.GetAt(i).SetInOutValues(dffs.GetAt(i).angle);
		}
	}
	for (int i = 0; i <jkffs.GetSize(); i++)
	{
		if (PtInRect(jkffs.GetAt(i).MRect, point)) {
			jkffs.GetAt(i).angle += 90;
			jkffs.GetAt(i).Rotate(dc, jkffs.GetAt(i).angle);
			jkffs.GetAt(i).SetInOutValues(jkffs.GetAt(i).angle);
		}
	}
	//입출력램프일 때
	for (int i = 0; i <bitinputs.GetSize(); i++)
	{
		if (PtInRect(bitinputs.GetAt(i).MRect, point)) {
			bitinputs.GetAt(i).angle += 90;
			bitinputs.GetAt(i).SmallRotate(dc, bitinputs.GetAt(i).angle);
			bitinputs.GetAt(i).SetInOutValues(bitinputs.GetAt(i).angle);
		}
	}
	for (int i = 0; i <lamps.GetSize(); i++)
	{
		if (PtInRect(lamps.GetAt(i).MRect, point)) {
			lamps.GetAt(i).angle += 90;
			lamps.GetAt(i).SmallRotate(dc, lamps.GetAt(i).angle);
			lamps.GetAt(i).SetInOutValues(lamps.GetAt(i).angle);
		}
	}
	for (int i = 0; i <clocks.GetSize(); i++)
	{
		if (PtInRect(clocks.GetAt(i).MRect, point)) {
			clocks.GetAt(i).angle += 90;
			clocks.GetAt(i).SmallRotate(dc, clocks.GetAt(i).angle);
			clocks.GetAt(i).SetInOutValues(clocks.GetAt(i).angle);
		}
	}
}

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
	ON_WM_LBUTTONDBLCLK()
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
	//BITINPUT a, b;
	//a.output[0].boolState = TRUE;
	//b.output[0].boolState = FALSE;

	//ORGATE c;
	//c.input[0].boolState = a.output[0].boolState;
	//c.input[1].boolState = b.output[0].boolState;
	//c.GateLogic();

	//CString str;
	//str.Format(_T("output : %d"),c.output[0].boolState);
	////str.Format(_T("Array Size : %d"), gates.GetSize());
	//pDC->TextOut(200, 200, str);


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
		temp->start_pt = point;
		m_start_pos = point;
		m_prev_pos = point;

		if (check_OutputArray(point, *temp)) //게이트들만 , 플립플롭 영역 따로 해야함
		{                                    //플립플롭 output영역.  input영역, 클럭 영역
			mouse_check = true;
		}
		
	    else if (check_line(point) >= 0)
		{
			(*temp).statu = LineArray.GetAt(check_line(point)).statu;
			mouse_check = true;
		}
		else
		{
			mouse_check = false;
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

		check_InputArray(point, *temp);
		(*temp).setLineRect();
		LineArray.Add(*temp);
	}
	

	CClientDC dc(this);

	ANDGATE* and;
	ORGATE* or ;
	NOTGATE* not;
	NANDGATE* nand;
	NORGATE* nor;
	XORGATE* xor;
	
	DFF* dff;
	TFF* tff;
	JKFF* jkff;

	
	Seven* seven;
	CLOCK_SIGNAL* clock;
	BITINPUT* bitinput;
	BITLAMP* lamp;


	if(selected){
		if (gatename == "AND") {
			and = new ANDGATE(point,IDB_BITMAP_AND);
			andgates.Add(*and);
			ALL.Add(*and);
			and->Paint(dc);
			and->PrintLabel(dc, gatename);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "OR") {
			or = new ORGATE(point, IDB_BITMAP_OR);
			orgates.Add(*or );
			ALL.Add(*or);
			or ->Paint(dc);
			or->PrintLabel(dc, gatename);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "NOT") {
			not = new NOTGATE(point,IDB_BITMAP_NOT);
			notgates.Add(*not);
			ALL.Add(*not);
			not->SmallPaint(dc);
			not->PrintLabel(dc, gatename);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "NAND") {
			nand = new NANDGATE(point, IDB_BITMAP_NAND);
			nandgates.Add(*nand);
			ALL.Add(*nand);
			nand->Paint(dc);
			nand->PrintLabel(dc, gatename);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "NOR") {
			nor = new NORGATE(point, IDB_BITMAP_NOR);
			norgates.Add(*nor);
			ALL.Add(*nor);
			nor->Paint(dc);
			nor->PrintLabel(dc, gatename);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "XOR") {
			xor = new XORGATE(point, IDB_BITMAP_XOR);
			xorgates.Add(*xor);
			ALL.Add(*xor);
			xor->Paint(dc);
			xor->PrintLabel(dc, gatename);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "D-FF") {
			dff = new DFF(point, IDB_BITMAP_DFF);
			dffs.Add(*dff);
			dff->Paint(dc);
			dff->PrintLabel(dc, gatename);
			ALL.Add(*dff);
			gatename = "";
			selected = FALSE;

		}
		else if (gatename == "JK-FF") {
			jkff = new JKFF(point, IDB_BITMAP_JKFF);
			jkffs.Add(*jkff);
			ALL.Add(*jkff);
			jkff->Paint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "T-FF") {
			tff = new TFF(point, IDB_BITMAP_TFF);
			tffs.Add(*tff);
			ALL.Add(*tff);
			tff->Paint(dc);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "LAMP") {
			lamp = new BITLAMP(point, IDB_BITMAP_LON);
			lamps.Add(*lamp);
			ALL.Add(*lamp);
			lamp->SmallPaint(dc);
			lamp->PrintLabel(dc,gatename);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "Input") {
			bitinput = new BITINPUT(point, IDB_BITMAP_BITINPUT_0);
			bitinputs.Add(*bitinput);
			ALL.Add(*bitinput);
			bitinput->SmallPaint(dc);
			bitinput->PrintLabel(dc, gatename);
			gatename = "";
			selected = FALSE;
		}
		else if (gatename == "CLK") {
			clock = new CLOCK_SIGNAL(point, IDB_BITMAP_CLK0);
			clocks.Add(*clock);
			ALL.Add(*clock);
			clock->SmallPaint(dc);
			gatename = "";
			selected = FALSE;
		}
		/*
		else if (gatename == "7-segment") {
			seven = new Seven(point);
			seven->Print_7_segment(dc);
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
	if (gatename == "") {
		rotate(dc, point);
	}
	CView::OnRButtonUp(nFlags, point);
}

void CLogisim_KKLView::OnMouseMove(UINT nFlags, CPoint point)
{

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CPen pen;
	pen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));    // 검은색 펜 생성
	CPen* oldPen = dc.SelectObject(&pen);
	if (mouse_check)
	{
		if (point.x == m_start_pos.x || point.y == m_start_pos.y)
		{
			dc.MoveTo(m_prev_pos.x, m_prev_pos.y);
			dc.LineTo(point.x, point.y);
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

bool CLogisim_KKLView::CheckInput(CPoint point ,int& i)
{
	for (i = 0; i < bitinputs.GetSize(); i++) {
		if (PtInRect(bitinputs.GetAt(i).MRect, point)) {
			return true;
			break;
		}
	}
	return false;
}

/*
CRectTracker함수

void CLogisim_KKLView::Cut(CPoint point)
{
	CPtrArray cut_Array;
	CRect cutRect;
	cutRect.SetRect(m_start_pos, point);
	for (int i = 0; i < LineArray.GetSize();; i++)
	{
		if (PtInRect(cutRect, LineArray.GetAt(i).start_pt))
		{
			cut_Array.Add(&LineArray.GetAt(i));
		}
	}
	for (int i = 0; i < ALL.GetSize(); i++)
	{
		if (PtInRect(cutRect, ALL.GetAt(i).MPoint))
		{
			cut_Array.Add(&ALL.GetAt(i));
		}
	}


}
*/

bool CLogisim_KKLView::CheckCLK(CPoint point, int& i)
{
	for (i = 0; i < clocks.GetSize(); i++) {
		if (PtInRect(clocks.GetAt(i).MRect, point)) {
			return true;
			break;
		}
	}
	return false;
}

void CLogisim_KKLView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	int i=0;
	if (CheckInput(point, i)) {
		if (bitinputs.GetAt(i).output[0].boolState)
		{	
			bitinputs.GetAt(i).output[0].boolState = false;
			bitinputs.GetAt(i).BITMAPID = IDB_BITMAP_BITINPUT_0;
			bitinputs.GetAt(i).SmallPaint(dc);
		}
		else
		{
			bitinputs.GetAt(i).output[0].boolState = true;
			bitinputs.GetAt(i).BITMAPID = IDB_BITMAP_BITINPUT_1;
			bitinputs.GetAt(i).SmallPaint(dc);
		}

	}

	
	else if (CheckCLK(point, i)) {
		if (clocks.GetAt(i).output[0].boolState)
		{	
			clocks.GetAt(i).pre_clk = true;
			clocks.GetAt(i).output[0].boolState = false;
			clocks.GetAt(i).BITMAPID = IDB_BITMAP_CLK0;
			clocks.GetAt(i).SmallPaint(dc);
		}
		else
		{	
			clocks.GetAt(i).pre_clk = false;
			clocks.GetAt(i).output[0].boolState = true;
			clocks.GetAt(i).BITMAPID = IDB_BITMAP_CKL1;
			clocks.GetAt(i).SmallPaint(dc);
		}
	}
	CView::OnLButtonDblClk(nFlags, point);
}
