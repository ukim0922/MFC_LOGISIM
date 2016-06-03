#include "stdafx.h"
#include "LogicEngine.h"
#include "Logisim_KKL.h"

bool clock_pre = TRUE; //클럭변수
bool clock_cur = TRUE;
bool h_ck = TRUE; //에지트리거방식 (상승이면true, 하강이면false) 클릭으로받아올예정

LogicEngine::LogicEngine()
{
}

void LogicEngine::Paint(CClientDC & dc)
{
	CBitmap bitmap;
	bitmap.LoadBitmap(BITMAPID);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CDC dcmem;

	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	dc.BitBlt(MPoint.x, MPoint.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
}

void LogicEngine::Rotate(CClientDC & dc, Gdiplus::REAL angle)
{
	Bitmap *pBitmap;
	pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(BITMAPID));
	Bitmap tempbmp(pBitmap->GetWidth(), pBitmap->GetHeight(), PixelFormat24bppRGB);
	int ix, iy;
	ix = int(pBitmap->GetWidth() / (-2.0));
	iy = int(pBitmap->GetHeight() / (-2.0));

	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	Graphics tempgx(&tempbmp);
	tempgx.RotateTransform(angle);
	tempgx.TranslateTransform(REAL(-ix), REAL(-iy), MatrixOrderAppend);
	Point dest[3] = { Point(ix, iy), Point(ix + pBitmap->GetWidth() + 1, iy), Point(ix, iy + pBitmap->GetHeight() + 1) };
	tempgx.DrawImage(pBitmap, dest, 3, 0, 0, pBitmap->GetWidth(), pBitmap->GetHeight(), UnitPixel);
	graphics.DrawImage(&tempbmp, MPoint.x, MPoint.y);
}

LogicEngine::~LogicEngine()
{
}

void LogicEngine::Gate(GateSelect Select, bool & Input1, bool & Input2)
{
	switch (Select)
	{
	case AND:
		if ((Input1&&Input2) == TRUE) {
			Output = TRUE;
		}
		else {
			Output = FALSE;
		}
		break;
	case OR:
		if ((Input1 == TRUE) || (Input2 == TRUE)) {
			Output = TRUE;
		}
		else
		{
			Output = FALSE;
		}
		break;
	case NAND:
		if (Input1 && Input2)
			Output = FALSE;
		else
			Output = TRUE;
		break;
	case NOR:
		if (Input1 || Input2)
			Output = FALSE;
		else
			Output = TRUE;
		break;
	case XOR:
		if (Input1 == Input2)
			Output = FALSE;
		else
			Output = TRUE;
		break;
	default:
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate 인 경우
		break;
	}

}

//NOT gate 구현
void LogicEngine::Gate(GateSelect Select, bool & input1)
{
	switch (Select)
	{
	case NOT:
		if (input1)
			Output = FALSE;
		else
			Output = TRUE;
		break;
	default:
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate 아닌 경우
		break;
		
	}

}

void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1) {		//d, t플립플롭
	switch(Select)
	{
	case T_FF:
		if (input1) {

			if (h_ck == TRUE) //상승 에지트리거
			{
				if (clock_pre == TRUE && clock_cur == FALSE)
				{
					bool temp;
					temp = Output_Q1;
					Output_Q1 = Output_Q2;
					Output_Q2 = temp;
				}
			}
			else //하강 에지트리거
			{
				if (clock_pre == FALSE && clock_cur == TRUE)
				{
					bool temp;
					temp = Output_Q1;
					Output_Q1 = Output_Q2;
					Output_Q2 = temp;
				}
			}
		}
		else {
			//변함이 없음.
		}
		break;

	case D_FF: //입력 그대로 출력
		if (h_ck == TRUE) //상승 에지트리거
		{
			if (clock_pre == TRUE && clock_cur == FALSE)
			{
				Output_Q1 = input1;
			}
		}
		else //하강 에지트리거
		{
			if (clock_pre == FALSE && clock_cur == TRUE)
			{
				Output_Q1 = input1;
			}
		}
		break;

	default:
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); 
		break;

	}
}

void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input_J, bool & input_K) {		//jk플립플롭
	switch (Select)
	{
	case JK_FF:
		if (h_ck == TRUE) //상승 에지 트리거
		{


		}
		else //하강 에지 트리거
		{

		}

		break;
	default:
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL);
		break;
	}
}


//T플립플롭
/*
TFF::TFF(CPoint &point) {
	this->point = point;
}
void TFF::Paint(CClientDC &dc) {
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_TFF);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CDC dcmem;

	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
}
void TFF::Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle) {
	Bitmap *pBitmap;
	pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_BITMAP_TFF));
	Bitmap tempbmp(pBitmap->GetWidth(), pBitmap->GetHeight(), PixelFormat24bppRGB);
	int ix, iy;
	ix = int(pBitmap->GetWidth() / (-2.0));
	iy = int(pBitmap->GetHeight() / (-2.0));

	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	Graphics tempgx(&tempbmp);
	tempgx.RotateTransform(angle);
	tempgx.TranslateTransform(REAL(-ix), REAL(-iy), MatrixOrderAppend);
	Point dest[3] = { Point(ix, iy), Point(ix + pBitmap->GetWidth() + 1, iy), Point(ix, iy + pBitmap->GetHeight() + 1) };
	tempgx.DrawImage(pBitmap, dest, 3, 0, 0, pBitmap->GetWidth(), pBitmap->GetHeight(), UnitPixel);
	graphics.DrawImage(&tempbmp, point.x, point.y);

}*/

//1비트 출력램프
void BITLAMP::Paint(CClientDC &dc) {
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_LON);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CDC dcmem;

	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	dc.StretchBlt(MPoint.x, MPoint.y, (bmpinfo.bmWidth) / 2, (bmpinfo.bmHeight) / 2, &dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
}

void BITLAMP::PrintLabel(CClientDC &dc) {
	SetLabel(_T("LAMP"));
	dc.TextOutW(MPoint.x-20, MPoint.y-15, GetLabel());

}
//void BITLAMP::Rotate(CClientDC &dc, Gdiplus::REAL angle) {
//	Bitmap *pBitmap;
//	pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_BITMAP_LON));
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
//	graphics.DrawImage(&tempbmp, MPoint.x, MPoint.y, (pBitmap->GetWidth()) / 2, (pBitmap->GetHeight()) / 2);
//
//}

// NOTGate 출력함수
void NOTGATE::Paint(CClientDC& dc)
{
	CBitmap bitmap;
	bitmap.LoadBitmap(BITMAPID);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CDC dcmem;

	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	dc.StretchBlt(MPoint.x, MPoint.y, (bmpinfo.bmWidth) / 2, (bmpinfo.bmHeight) / 2, &dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	//dc.BitBlt(MPoint.x, MPoint.y, (bmpinfo.bmWidth)/2, (bmpinfo.bmHeight)/2, &dcmem, 0, 0, SRCCOPY);
}

//7-segment 출력함수(완료)
void Seven::Print_7_segment( CClientDC &dc, bool input_a, bool input_b, bool input_c, bool input_d, bool input_e, bool input_f, bool input_g)
{

	if ((input_a && input_b && input_c && input_d && input_e && input_f == true) && (input_g == false) )
	{
		Paint(dc, 0);
	}
	else if ((input_b && input_c == true) && (input_a || input_d || input_e || input_f || input_g == false) )
	{
		Paint(dc, 1);
	}
	else if ((input_a && input_b  && input_d && input_e && input_g == true) && (input_c || input_f == false))
	{
		Paint(dc, 2);
	}
	else if ((input_a && input_b && input_c && input_d && input_g == true) && (input_e || input_f == false))
	{
		Paint(dc, 3);
	}
	else if ((input_b && input_c && input_f && input_g==true) && (input_a || input_d || input_e == false))
	{
		Paint(dc, 4);
	}
	else if ((input_a && input_c && input_d && input_f && input_g==true)&&(input_b || input_e == false))
	{
		Paint(dc, 5);
	}
	else if ((input_a && input_c && input_d && input_f && input_g && input_e == true)&&(input_b || input_e == false))
	{
		Paint(dc, 6);
	}
	else if ((input_a && input_b && input_c && input_f == true)&& (input_d || input_g == false))
	{
		Paint(dc, 7);
	}
	else if (input_a && input_b && input_c && input_d && input_e && input_f && input_g == true)
	{
		Paint(dc, 8);
	}
	else if ((input_a && input_b && input_c && input_d && input_f && input_g == true)&& (input_e == false))
	{
		Paint(dc, 9);
	}
	else
	{
		Paint(dc, 10);
	}
}


Seven::Seven(CPoint &point) {
	this->point = point;
}

//7-segment 글자별 출력함수(진행중)
void Seven::Paint(CClientDC &dc, int num) {
	CBitmap bitmap_w, bitmap_h;
	bitmap_w.LoadBitmap(IDB_BITMAP_W);
	bitmap_h.LoadBitmap(IDB_BITMAP_H);
	BITMAP bmpinfo_w, bmpinfo_h;
	bitmap_w.GetBitmap(&bmpinfo_w);
	bitmap_h.GetBitmap(&bmpinfo_h);
	CDC dcmem_w, dcmem_h;

	dcmem_w.CreateCompatibleDC(&dc);
	dcmem_w.SelectObject(&bitmap_w);

	dcmem_w.CreateCompatibleDC(&dc);
	dcmem_w.SelectObject(&bitmap_w);

	

	switch (num)
	{
	case 0:
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x - bmpinfo_w.bmWidth, point.y + bmpinfo_h.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);
		dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + bmpinfo_h.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		break;
	case 1:
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		break;
	case 2:
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		break;
	case 3:
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		break;
	case 4:
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		break;
	case 5:
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		break;
	case 6:
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		break;
	case 7:
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		break;
	case 8:
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		break;
	case 9:
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);
		break;
	default:
		break;
	}

}  

//회전함수
void NOTGATE::Rotate(CClientDC &dc, Gdiplus::REAL angle) {
	Bitmap *pBitmap;
	pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_BITMAP_NOT));
	Bitmap tempbmp(pBitmap->GetWidth(), pBitmap->GetHeight(), PixelFormat24bppRGB);
	int ix, iy;
	ix = int(pBitmap->GetWidth() / (-2.0));
	iy = int(pBitmap->GetHeight() / (-2.0));

	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	Graphics tempgx(&tempbmp);
	tempgx.RotateTransform(angle);
	tempgx.TranslateTransform(REAL(-ix), REAL(-iy), MatrixOrderAppend);
	Point dest[3] = { Point(ix, iy), Point(ix + pBitmap->GetWidth() + 1, iy), Point(ix, iy + pBitmap->GetHeight() + 1) };
	tempgx.DrawImage(pBitmap, dest, 3, 0, 0, pBitmap->GetWidth(), pBitmap->GetHeight(), UnitPixel);
	graphics.DrawImage(&tempbmp, MPoint.x, MPoint.y, (pBitmap->GetWidth())/2, (pBitmap->GetHeight())/2);
}

BOOL SetRect(CPoint& point, CPoint& in) {
	for (int i = 0; i < RectArr.GetSize(); i++) {
		if (PtInRect(RectArr[i].first_in, point)) {
			in = RectArr[i].input1.CenterPoint();
			return TRUE;
		}
		else if (PtInRect(RectArr[i].second_in, point)) {
			in = gateArr[i].input2.CenterPoint();
			return TRUE;
		}
		else if (PtInRect(RectArr[i].out, point)) {
			in = gateArr[i].output.CenterPoint();
			return TRUE;
		}
	}
	return NULL;
}