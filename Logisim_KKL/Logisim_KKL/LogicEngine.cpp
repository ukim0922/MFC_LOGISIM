#include "stdafx.h"
#include "LogicEngine.h"
#include "Logisim_KKL.h"

bool clock_pre = TRUE; //Ŭ������
bool clock_cur = TRUE;
bool h_ck = TRUE; //����Ʈ���Ź�� (����̸�true, �ϰ��̸�false) Ŭ�����ι޾ƿÿ���

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
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate �� ���
		break;
	}

}

//NOT gate ����
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
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate �ƴ� ���
		break;
		
	}

}

void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1) {		//d, t�ø��÷�
	switch(Select)
	{
	case T_FF:
		if (input1) {

			if (h_ck == TRUE) //��� ����Ʈ����
			{
				if (clock_pre == TRUE && clock_cur == FALSE)
				{
					bool temp;
					temp = Output_Q1;
					Output_Q1 = Output_Q2;
					Output_Q2 = temp;
				}
			}
			else //�ϰ� ����Ʈ����
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
			//������ ����.
		}
		break;

	case D_FF: //�Է� �״�� ���
		if (h_ck == TRUE) //��� ����Ʈ����
		{
			if (clock_pre == TRUE && clock_cur == FALSE)
			{
				Output_Q1 = input1;
			}
		}
		else //�ϰ� ����Ʈ����
		{
			if (clock_pre == FALSE && clock_cur == TRUE)
			{
				Output_Q1 = input1;
			}
		}
		break;
	default:
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate �ƴ� ���
		break;

	}
}

void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1, bool & input2) {		//jk�ø��÷�

}

//AND����Ʈ
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


//OR����Ʈ
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

//XOR����Ʈ
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

//NAND����Ʈ
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

//NOR����Ʈ
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

//NOT����Ʈ
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

//T�ø��÷�
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

//1��Ʈ ��·���
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
