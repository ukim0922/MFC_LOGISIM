
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "KKL_LOGISIM.h"
#include "ChildView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int gate_num = 0; //게이트 수
char gate_result[50]; //게이트 최대 50개


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	CBitmap andGate;
	andGate.LoadBitmap(IDB_BITMAP_AND);
	BITMAP andGateinfo;
	andGate.GetBitmap(&andGateinfo);

	if (/*게이트 추가되면*/1)
	{
		gate_result[gate_num - 1] = 'F';  //게이트 생성번호 == 출력번호 하고싶은데 string이 왜안써질까
	}

	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 유진 : 여기에 게이트에 마우스 댔을 때 초록동그라미 뜨도록 하기
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	twoInputoneOutput();
	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::twoInputoneOutput() {
	//두입력한출력 인식하도록?
}