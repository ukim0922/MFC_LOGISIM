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

void LogicEngine::Rotate(CClientDC & dc, CPoint & point, Gdiplus::REAL angle)
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
	graphics.DrawImage(&tempbmp, point.x, point.y);
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
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate 아닌 경우
		break;

	}
}

void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1, bool & input2) {		//jk플립플롭

}

//AND게이트
//ANDGATE::ANDGATE(CPoint MPoint) {
//	this->MPoint = MPoint;
//}
//void ANDGATE::Paint(CClientDC &dc) {
//	CBitmap bitmap;
//	bitmap.LoadBitmap(IDB_BITMAP_AND);
//	BITMAP bmpinfo;
//	bitmap.GetBitmap(&bmpinfo);
//	CDC dcmem;
//
//	dcmem.CreateCompatibleDC(&dc);
//	dcmem.SelectObject(&bitmap);
//	dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
//}
//void ANDGATE::Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle) {
//	Bitmap *pBitmap;
//	pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_BITMAP_AND));
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
//	graphics.DrawImage(&tempbmp, point.x, point.y);
//
//}


//OR게이트
ORGATE::ORGATE(CPoint &point) {
	this->point = point;
}
void ORGATE::Paint(CClientDC &dc) {
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_AND);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CDC dcmem;

	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
}
void ORGATE::Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle) {
	Bitmap *pBitmap;
	pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_BITMAP_AND));
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

}

//XOR게이트
XORGATE::XORGATE(CPoint &point) {
	this->point = point;
}
void XORGATE::Paint(CClientDC &dc) {
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_XOR);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CDC dcmem;

	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
}
void XORGATE::Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle) {
	Bitmap *pBitmap;
	pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_BITMAP_XOR));
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

}

//NAND게이트
NANDGATE::NANDGATE(CPoint &point) {
this->point = point;
}
void NANDGATE::Paint(CClientDC &dc) {
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_NAND);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CDC dcmem;

	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
}
void NANDGATE::Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle) {
	Bitmap *pBitmap;
	pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_BITMAP_NAND));
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

}

//NOR게이트
NORGATE::NORGATE(CPoint &point) {
	this->point = point;
}
void NORGATE::Paint(CClientDC &dc) {
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_NOR);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CDC dcmem;

	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
}
void NORGATE::Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle) {
	Bitmap *pBitmap;
	pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_BITMAP_NOR));
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

}

//NOT게이트
NOTGATE::NOTGATE(CPoint &point) {
	this->point = point;
}
void NOTGATE::Paint(CClientDC &dc) {
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_NOT);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CDC dcmem;

	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
}
void NOTGATE::Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle) {
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
	graphics.DrawImage(&tempbmp, point.x, point.y);

}

//T플립플롭
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

}

//1비트 출력램프
BITLAMP::BITLAMP(CPoint &point) {
	this->point = point;
}
void BITLAMP::Paint(CClientDC &dc) {
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_LON);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CDC dcmem;

	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
}
void BITLAMP::Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle) {
	Bitmap *pBitmap;
	pBitmap = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_BITMAP_LON));
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

}

//ANDGATE::~ANDGATE()
//{
//}
