
// Logisim_KKLView.cpp : CLogisim_KKLView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Logisim_KKL.h"
#endif

#include "Logisim_KKLDoc.h"
#include "Logisim_KKLView.h"
#include "LogicEngine.h"    //���� �߰�
#include "FilpFlopEngine.h"    //���� �߰�
#include "Line.h" //���� �߰�

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

// CLogisim_KKLView ����/�Ҹ�

CLogisim_KKLView::CLogisim_KKLView()
	: gatename(_T(""))
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}


CLogisim_KKLView::~CLogisim_KKLView()
{
}

BOOL CLogisim_KKLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CLogisim_KKLView �׸���

void CLogisim_KKLView::OnDraw(CDC* pDC)
{
	CLogisim_KKLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	//��ǥ ǥ��
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


	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CLogisim_KKLView ����

#ifdef _DEBUG
void CLogisim_KKLView::AssertValid() const
{
	CView::AssertValid();
}

void CLogisim_KKLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLogisim_KKLDoc* CLogisim_KKLView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLogisim_KKLDoc)));
	return (CLogisim_KKLDoc*)m_pDocument;
}
#endif //_DEBUG


void CLogisim_KKLView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// ������ ���� flag �� ��ǥ ����
	if(gatename == "")
	{
		temp = new Line;
		//LineArray.Add(*temp);
		temp->start_pt = point;

		
		m_prev_pos.x = point.x;
		m_prev_pos.y = point.y;
		//int index = check_line(point);


		if (check_OutputArray(point, *temp)) //����Ʈ�鸸 , �ø��÷� ���� ���� �ؾ���
		{                                    //�ø��÷� output����.  input����, Ŭ�� ����
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//���콺 �巡�� flag ����
	
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
		else if (gatename == "�Է�") {
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	h_ck = true;
}


void CLogisim_KKLView::OnLowTRG()
{
	h_ck = false;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CLogisim_KKLView::OnUpdateHigh(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(h_ck == true);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}


void CLogisim_KKLView::OnUpdateLow(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(h_ck == false);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}
