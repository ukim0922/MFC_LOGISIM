//#include "stdafx.h"
//#include "FilpFlopEngine.h"
//#include "MainFrm.h"
//
//void FilpFlopEngine::FlipFlopLogic()
//{
//}
//
//FilpFlopEngine::FilpFlopEngine()
//{
//}
//
//
//FilpFlopEngine::~FilpFlopEngine()
//{
//}
//
//
//void  FilpFlopEngine::Paint(CClientDC &dc) {
//	CBitmap bitmap;
//	bitmap.LoadBitmap(BITMAPID);
//	BITMAP bmpinfo;
//	bitmap.GetBitmap(&bmpinfo);
//	CDC dcmem;
//
//	dcmem.CreateCompatibleDC(&dc);
//	dcmem.SelectObject(&bitmap);
//	dc.BitBlt(MPoint.x, MPoint.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
//}
//void  FilpFlopEngine::Rotate(CClientDC &dc, Gdiplus::REAL angle) {
//	Bitmap *pBitmap;
//	pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(BITMAPID));
//	Bitmap tempbmp(pBitmap->GetWidth(), pBitmap->GetHeight(), PixelFormat24bppRGB);
//	int ix, iy;
//	ix = int(pBitmap->GetWidth() / (-2.0));
//	iy = int(pBitmap->GetHeight() / (-2.0));
//
//	Graphics graphics(dc);
//	graphics.SetSmoothingMode(SmoothingModeHighQuality);
//	Graphics tempgx(&tempbmp);
//	tempgx.RotateTransform(angle);
//	tempgx.TranslateTransform(REAL(-ix), REAL(-iy), MatrixOrderAppend);
//	Point dest[3] = { Point(ix, iy), Point(ix + pBitmap->GetWidth() + 1, iy), Point(ix, iy + pBitmap->GetHeight() + 1) };
//	tempgx.DrawImage(pBitmap, dest, 3, 0, 0, pBitmap->GetWidth(), pBitmap->GetHeight(), UnitPixel);
//	graphics.DrawImage(&tempbmp, MPoint.x, MPoint.y);
//}
//
//
//void DFF::FlipFlopLogic()
//{
//	if (h_ck == TRUE) //상승 에지트리거
//	{
//		if (clock_pre == TRUE && clock_cur == FALSE)
//		{
//			output[0].boolState = input[0].boolState;
//		}
//	}
//	else //하강 에지트리거
//	{
//		if (clock_pre == FALSE && clock_cur == TRUE)
//		{
//			output[0].boolState = input[0].boolState;
//		}
//	}
//}
//
//void TFF::FlipFlopLogic()
//{
//		if (input[0].boolState) {
//
//			if (h_ck == TRUE) //상승 에지트리거
//			{
//				if (clock_pre == TRUE && clock_cur == FALSE)
//				{
//					bool temp;
//					temp = output[0].boolState;
//					output[0].boolState = output[1].boolState;
//					output[0].boolState = temp;
//				}
//			}
//			else //하강 에지트리거
//			{
//				if (clock_pre == FALSE && clock_cur == TRUE)
//				{
//					bool temp;
//					temp = output[0].boolState;
//					output[0].boolState = output[1].boolState;
//					output[0].boolState = temp;
//				}
//			}
//		}
//		else {
//			//변함이 없음.
//		}
//}
//
//void JKFF::FlipFlopLogic()
//		{
//	if (h_ck == TRUE) //상승 에지 트리거
//	{
//			if (clock_pre == TRUE && clock_cur == FALSE)
//			{
//			if ((input[0].boolState == FALSE) && (input[1].boolState == FALSE)) {
//				// 변화 없음
//			}
//			else if ((input[0].boolState == FALSE) && (input[1].boolState == TRUE))
//			{	// 0으로 리셋
//				output[0].boolState = FALSE;
//		}
//			else if ((input[0].boolState == TRUE) && (input[1].boolState == FALSE))
//			{	// 1로 세트
//				output[0].boolState = TRUE;
//			}
//			else if ((input[0].boolState == TRUE) && (input[1].boolState == TRUE))
//			{	// 토글
//				if (output[0].boolState)
//					output[0].boolState = FALSE;
//				else
//					output[0].boolState = TRUE;
//		}
//			else
//		{
//				AfxMessageBox(_T("JK FilpFilop 논리 에러"), MB_OKCANCEL);
//			}
//
//			if (output[0].boolState) //Q가 T이면
//				output[1].boolState = FALSE; //Q'는 F
//			else // Q가 F면
//				output[1].boolState = TRUE; // Q'는 T
//
//		}
//	}
//		else //하강 에지 트리거
//		{
//		if (clock_pre == FALSE && clock_cur == TRUE)
//		{
//			if ((input[0].boolState == FALSE) && (input[1].boolState == FALSE)) {
//				// 변화 없음
//			}
//			else if ((input[0].boolState == FALSE) && (input[1].boolState == TRUE))
//			{	// 0으로 리셋
//				output[0].boolState = FALSE;
//			}
//			else if ((input[0].boolState == TRUE) && (input[1].boolState == FALSE))
//			{	// 1로 세트
//				output[0].boolState = TRUE;
//			}
//			else if ((input[0].boolState == TRUE) && (input[1].boolState == TRUE))
//			{	// 토글
//				if (output[0].boolState)
//					output[0].boolState = FALSE;
//				else
//					output[0].boolState = TRUE;
//			}
//			else
//			{
//				AfxMessageBox(_T("JK FilpFilop 논리 에러"), MB_OKCANCEL);
//			}
//
//			if (output[0].boolState) //Q가 T이면
//				output[1].boolState = FALSE; //Q'는 F
//			else // Q가 F면
//				output[1].boolState = TRUE; // Q'는 T
//		}
//	}
//}
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
//	DFF(CPoint MPoint, UINT BITMAPID) : FilpFlopEngine(MPoint, BITMAPID) {
//		this->gatenumber = D_FF;
//	}
//	void FlipFlopLogic();
//
//};
//
//class TFF : public FilpFlopEngine {
//public:
//	TFF(CPoint MPoint, UINT BITMAPID) : FilpFlopEngine(MPoint, BITMAPID) {
//		this->gatenumber = T_FF;
//	}
//	void FlipFlopLogic();
//};
//
//class JKFF : public FilpFlopEngine {
//public:
//	JKFF(CPoint MPoint, UINT BITMAPID) : FilpFlopEngine(MPoint, BITMAPID) {
//		this->gatenumber = JK_FF;
//	}
//	void FlipFlopLogic();
//};
//void FilpFlopEngine::SetInOutValues(Gdiplus::REAL angle)
//{
//	CString name;
//	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
//	name = pFrame->m_pLogisimView->gatename;
//	if (name == "D-FF") {
//		switch ((int)angle % 360) {
//		case 0:
//			//사각형 영역 지정
//			input[0].rectState = CRect(MPoint.x - 4, MPoint.y + 12, MPoint.x + 4, MPoint.y + 20);
//			clk.rectState = CRect(MPoint.x - 4, MPoint.y + 32, MPoint.x + 4, MPoint.y + 40);
//			output[0].rectState = CRect(MPoint.x + 44, MPoint.y + 4, MPoint.x + 52, MPoint.y + 12);
//			output[1].rectState = CRect(MPoint.x + 44, MPoint.y + 32, MPoint.x + 52, MPoint.y + 40);
//			//좌표 영역 지정
//			input[0].pointState.x = MPoint.x;
//			input[0].pointState.y = MPoint.y + 16;
//			clk.pointState.x = MPoint.x;
//			clk.pointState.y = MPoint.y + 36;
//			output[0].pointState.x = MPoint.x + 48;
//			output[0].pointState.y = MPoint.y + 8;
//			output[1].pointState.x = MPoint.x + 48;
//			output[1].pointState.y = MPoint.y + 36;
//			break;
//		case 90:
//			//사각형 영역 지정
//			input[0].rectState = CRect(MPoint.x + 28, MPoint.y - 4, MPoint.x + 36, MPoint.y + 4);
//			clk.rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
//			output[0].rectState = CRect(MPoint.x + 36, MPoint.y + 44, MPoint.x + 44, MPoint.y + 52);
//			output[1].rectState = CRect(MPoint.x + 8, MPoint.y + 44, MPoint.x + 16, MPoint.y + 52);
//			//좌표 영역 지정
//			input[0].pointState.x = MPoint.x + 32;
//			input[0].pointState.y = MPoint.y;
//			clk.pointState.x = MPoint.x + 12;
//			clk.pointState.y = MPoint.y;
//			output[0].pointState.x = MPoint.x + 40;
//			output[0].pointState.y = MPoint.y + 48;
//			output[1].pointState.x = MPoint.x + 12;
//			output[1].pointState.y = MPoint.y + 48;
//			break;
//		case 180:
//			//사각형 영역 지정
//			input[0].rectState = CRect(MPoint.x + 44, MPoint.y + 28, MPoint.x + 52, MPoint.y + 36);
//			clk.rectState = CRect(MPoint.x + 44, MPoint.y + 8, MPoint.x + 52, MPoint.y + 16);
//			output[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
//			output[1].rectState = CRect(MPoint.x - 4, MPoint.y + 36, MPoint.x + 4, MPoint.y + 44);
//			//좌표 영역 지정
//			input[0].pointState.x = MPoint.x + 48;
//			input[0].pointState.y = MPoint.y + 32;
//			clk.pointState.x = MPoint.x + 48;
//			clk.pointState.y = MPoint.y + 12;
//			output[0].pointState.x = MPoint.x;
//			output[0].pointState.y = MPoint.y + 12;
//			output[1].pointState.x = MPoint.x;
//			output[1].pointState.y = MPoint.y + 40;
//			break;
//		case 270:
//			//사각형 영역 지정
//			input[0].rectState = CRect(MPoint.x + 4, MPoint.y - 4, MPoint.x + 12, MPoint.y + 4);
//			clk.rectState = CRect(MPoint.x + 32, MPoint.y - 4, MPoint.x + 40, MPoint.y + 4);
//			output[0].rectState = CRect(MPoint.x + 12, MPoint.y + 44, MPoint.x + 20, MPoint.y + 52);
//			output[1].rectState = CRect(MPoint.x + 44, MPoint.y + 44, MPoint.x + 52, MPoint.y + 52);
//			//좌표 영역 지정
//			input[0].pointState.x = MPoint.x + 8;
//			input[0].pointState.y = MPoint.y;
//			clk.pointState.x = MPoint.x + 36;
//			clk.pointState.y = MPoint.y;
//			output[0].pointState.x = MPoint.x + 16;
//			output[0].pointState.y = MPoint.y + 48;
//			output[1].pointState.x = MPoint.x + 36;
//			output[1].pointState.y = MPoint.y + 48;
//			break;
//		}
//	}
//	else if (name == "T-FF") {
//		switch ((int)angle % 360) {
//		case 0:
//			//사각형 영역 지정
//			input[1].rectState = CRect(MPoint.x - 4, MPoint.y + 12, MPoint.x + 4, MPoint.y + 20);
//			clk.rectState = CRect(MPoint.x - 4, MPoint.y + 32, MPoint.x + 4, MPoint.y + 40);
//			output[0].rectState = CRect(MPoint.x + 44, MPoint.y + 4, MPoint.x + 52, MPoint.y + 12);
//			output[1].rectState = CRect(MPoint.x + 44, MPoint.y + 32, MPoint.x + 52, MPoint.y + 40);
//			//좌표 영역 지정
//			input[1].pointState.x = MPoint.x;
//			input[1].pointState.y = MPoint.y + 16;
//			clk.pointState.x = MPoint.x;
//			clk.pointState.y = MPoint.y + 36;
//			output[0].pointState.x = MPoint.x + 48;
//			output[0].pointState.y = MPoint.y + 8;
//			output[1].pointState.x = MPoint.x + 48;
//			output[1].pointState.y = MPoint.y + 36;
//			break;
//		case 90:
//			//사각형 영역 지정
//			input[1].rectState = CRect(MPoint.x + 28, MPoint.y - 4, MPoint.x + 36, MPoint.y + 4);
//			clk.rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
//			output[0].rectState = CRect(MPoint.x + 36, MPoint.y + 44, MPoint.x + 44, MPoint.y + 52);
//			output[1].rectState = CRect(MPoint.x + 8, MPoint.y + 44, MPoint.x + 16, MPoint.y + 52);
//			//좌표 영역 지정
//			input[1].pointState.x = MPoint.x + 32;
//			input[1].pointState.y = MPoint.y;
//			clk.pointState.x = MPoint.x + 12;
//			clk.pointState.y = MPoint.y;
//			output[0].pointState.x = MPoint.x + 40;
//			output[0].pointState.y = MPoint.y + 48;
//			output[1].pointState.x = MPoint.x + 12;
//			output[1].pointState.y = MPoint.y + 48;
//			break;
//		case 180:
//			//사각형 영역 지정
//			input[1].rectState = CRect(MPoint.x + 44, MPoint.y + 28, MPoint.x + 52, MPoint.y + 36);
//			clk.rectState = CRect(MPoint.x + 44, MPoint.y + 8, MPoint.x + 52, MPoint.y + 16);
//			output[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
//			output[1].rectState = CRect(MPoint.x - 4, MPoint.y + 36, MPoint.x + 4, MPoint.y + 44);
//			//좌표 영역 지정
//			input[1].pointState.x = MPoint.x + 48;
//			input[1].pointState.y = MPoint.y + 32;
//			clk.pointState.x = MPoint.x + 48;
//			clk.pointState.y = MPoint.y + 12;
//			output[0].pointState.x = MPoint.x;
//			output[0].pointState.y = MPoint.y + 12;
//			output[1].pointState.x = MPoint.x;
//			output[1].pointState.y = MPoint.y + 40;
//			break;
//		case 270:
//			//사각형 영역 지정
//			input[1].rectState = CRect(MPoint.x + 4, MPoint.y - 4, MPoint.x + 12, MPoint.y + 4);
//			clk.rectState = CRect(MPoint.x + 32, MPoint.y - 4, MPoint.x + 40, MPoint.y + 4);
//			output[0].rectState = CRect(MPoint.x + 12, MPoint.y + 44, MPoint.x + 20, MPoint.y + 52);
//			output[1].rectState = CRect(MPoint.x + 44, MPoint.y + 44, MPoint.x + 52, MPoint.y + 52);
//			//좌표 영역 지정
//			input[1].pointState.x = MPoint.x + 8;
//			input[1].pointState.y = MPoint.y;
//			clk.pointState.x = MPoint.x + 36;
//			clk.pointState.y = MPoint.y;
//			output[0].pointState.x = MPoint.x + 16;
//			output[0].pointState.y = MPoint.y + 48;
//			output[1].pointState.x = MPoint.x + 36;
//			output[1].pointState.y = MPoint.y + 48;
//			break;
//		}
//	}
//	else if(name == "JK-FF"){
//		switch ((int)angle % 360) {
//		case 0:
//			//사각형 영역 지정
//			input[0].rectState = CRect(MPoint.x - 4, MPoint.y + 4, MPoint.x + 4, MPoint.y + 12);
//			input[1].rectState = CRect(MPoint.x - 4, MPoint.y + 20, MPoint.x + 4, MPoint.y + 28);
//			clk.rectState = CRect(MPoint.x - 4, MPoint.y + 32, MPoint.x + 4, MPoint.y + 40);
//			output[0].rectState = CRect(MPoint.x + 44, MPoint.y + 4, MPoint.x + 52, MPoint.y + 12);
//			output[1].rectState = CRect(MPoint.x + 44, MPoint.y + 32, MPoint.x + 52, MPoint.y + 40);
//			//좌표 영역 지정
//			input[0].pointState.x = MPoint.x;
//			input[0].pointState.y = MPoint.y + 8;
//			input[1].pointState.x = MPoint.x;
//			input[1].pointState.y = MPoint.y + 24;
//			clk.pointState.x = MPoint.x;
//			clk.pointState.y = MPoint.y + 36;
//			output[0].pointState.x = MPoint.x + 48;
//			output[0].pointState.y = MPoint.y + 8;
//			output[1].pointState.x = MPoint.x + 48;
//			output[1].pointState.y = MPoint.y + 36;
//			break;
//		case 90:
//			//사각형 영역 지정
//			input[0].rectState = CRect(MPoint.x + 36, MPoint.y - 4, MPoint.x + 44, MPoint.y + 4);
//			input[1].rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
//			clk.rectState = CRect(MPoint.x + 20, MPoint.y - 4, MPoint.x + 28, MPoint.y + 4);
//			output[0].rectState = CRect(MPoint.x + 36, MPoint.y + 44, MPoint.x + 44, MPoint.y + 52);
//			output[1].rectState = CRect(MPoint.x + 8, MPoint.y + 44, MPoint.x + 16, MPoint.y + 52);
//			//좌표 영역 지정
//			input[0].pointState.x = MPoint.x + 40;
//			input[0].pointState.y = MPoint.y;
//			input[1].pointState.x = MPoint.x + 12;
//			input[1].pointState.y = MPoint.y;
//			clk.pointState.x = MPoint.x + 24;
//			clk.pointState.y = MPoint.y;
//			output[0].pointState.x = MPoint.x + 40;
//			output[0].pointState.y = MPoint.y + 48;
//			output[1].pointState.x = MPoint.x + 12;
//			output[1].pointState.y = MPoint.y + 48;
//			break;
//		case 180:
//			//사각형 영역 지정
//			input[0].rectState = CRect(MPoint.x + 44, MPoint.y + 36, MPoint.x + 52, MPoint.y + 44);
//			input[1].rectState = CRect(MPoint.x + 44, MPoint.y + 8, MPoint.x + 52, MPoint.y + 16);
//			clk.rectState = CRect(MPoint.x + 44, MPoint.y + 20, MPoint.x + 52, MPoint.y + 28);
//			output[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
//			output[1].rectState = CRect(MPoint.x - 4, MPoint.y + 36, MPoint.x + 4, MPoint.y + 44);
//			//좌표 영역 지정
//			input[0].pointState.x = MPoint.x + 48;
//			input[0].pointState.y = MPoint.y + 40;
//			input[1].pointState.x = MPoint.x + 48;
//			input[1].pointState.y = MPoint.y + 12;
//			clk.pointState.x = MPoint.x + 48;
//			clk.pointState.y = MPoint.y + 24;
//			output[0].pointState.x = MPoint.x;
//			output[0].pointState.y = MPoint.y + 12;
//			output[1].pointState.x = MPoint.x;
//			output[1].pointState.y = MPoint.y + 40;
//			break;
//		case 270:
//			//사각형 영역 지정
//			input[0].rectState = CRect(MPoint.x + 4, MPoint.y + 44, MPoint.x + 12, MPoint.y + 52);
//			input[1].rectState = CRect(MPoint.x + 32, MPoint.y + 44, MPoint.x + 40, MPoint.y + 52);
//			clk.rectState = CRect(MPoint.x + 20, MPoint.y + 44, MPoint.x + 28, MPoint.y + 52);
//			output[0].rectState = CRect(MPoint.x + 4, MPoint.y - 4, MPoint.x + 12, MPoint.y + 4);
//			output[1].rectState = CRect(MPoint.x + 32, MPoint.y - 4, MPoint.x + 40, MPoint.y + 4);
//			//좌표 영역 지정
//			input[0].pointState.x = MPoint.x + 8;
//			input[0].pointState.y = MPoint.y + 48;
//			input[1].pointState.x = MPoint.x + 36;
//			input[1].pointState.y = MPoint.y + 48;
//			clk.pointState.x = MPoint.x + 24;
//			clk.pointState.y = MPoint.y + 48;
//			output[0].pointState.x = MPoint.x + 8;
//			output[0].pointState.y = MPoint.y;
//			output[1].pointState.x = MPoint.x + 36;
//			output[1].pointState.y = MPoint.y;
//			break;
//		}
//	}
//}