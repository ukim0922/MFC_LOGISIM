#include "stdafx.h"
#include "LogicEngine.h"
#include "Logisim_KKL.h"
#include "MainFrm.h"


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

void LogicEngine::PrintLabel(CClientDC &dc,CString Label) {
	SetLabel(Label);
	dc.TextOutW(MPoint.x - 20, MPoint.y - 15, GetLabel());

}

LogicEngine::~LogicEngine()
{
}

void LogicEngine::Gate(GateSelect Select)
{
	switch (Select)
	{
	case NOT:
		if (input[0].boolState)
			output[0].boolState = FALSE;
		else
			output[0].boolState = TRUE;
		break;
	case AND:
		if ((input[0].boolState&&input[1].boolState) == TRUE) {
			output[0].boolState = TRUE;
		}
		else {
			output[0].boolState = FALSE;
		}
		break;
	case OR:
		if ((input[0].boolState == TRUE) || (input[1].boolState == TRUE)) {
			output[0].boolState = TRUE;
		}
		else
		{
			output[0].boolState = FALSE;
		}
		break;
	case NAND:
		if (input[0].boolState && input[1].boolState)
			output[0].boolState = FALSE;
		else
			output[0].boolState = TRUE;
		break;
	case NOR:
		if (input[0].boolState || input[1].boolState)
			output[0].boolState = FALSE;
		else
			output[0].boolState = TRUE;
		break;
	case XOR:
		if (input[0].boolState == input[1].boolState)
			output[0].boolState = FALSE;
		else
			output[0].boolState = TRUE;
		break;
	default:
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate 인 경우
		break;
	}

}




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
}


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
			dc.BitBlt(point.x- bmpinfo_w.bmWidth , point.y + bmpinfo_h.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);
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
//
//BOOL SetRect(CPoint& point, CPoint& in) {
//	for (int i = 0; i < RectArr.GetSize(); i++) {
//		if (PtInRect(RectArr[i].input1, point)) {
//			in = RectArr[i].input1.CenterPoint();
//			return TRUE;
//		}
//		else if (PtInRect(RectArr[i].input2, point)) {
//			in = RectArr[i].input2.CenterPoint();
//			return TRUE;
//		}
//		else if (PtInRect(RectArr[i].output, point)) {
//			in = RectArr[i].output.CenterPoint();
//			return TRUE;
//		}
//	}
//	return NULL;
//}

//
//void LogicEngine::SetOutput(Gdiplus::REAL angle,int i)
//{
//	CString name;
//	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
//	name = pFrame->m_pLogisimView->gatename;
//	if (name == "NOT") {
//		switch ((int)angle/360) {
//		case 0:
//			RectArr[i].output = CRect();
//			RectArr[i].input1 = CRect((rect.left + rect.right) / 2 - 5, rect.bottom + 5, (rect.left + rect.right) / 2 + 5, rect.bottom + 15);
//			RectArr[i].input2 = CRect();
//			break;
//		case 90:
//			this->out = CRect();
//			this->in1 = CRect(rect.left - 15, (rect.top + rect.bottom) / 2 - 5, rect.left - 5, (rect.top + rect.bottom) / 2 + 5);
//			this->in2 = CRect();
//			break;
//		case 180:
//			this->out = CRect();
//			this->in1 = CRect((rect.left + rect.right) / 2 - 5, rect.top - 15, (rect.left + rect.right) / 2 + 5, rect.top - 5);
//			this->in2 = CRect();
//		case 270:
//			this->out = CRect();
//			this->in1 = CRect(rect.right + 5, (rect.top + rect.bottom) / 2 - 5, rect.right + 15, (rect.top + rect.bottom) / 2 + 5);
//			this->in2 = CRect();
//			break;
//		}
//		OutputPoint.x = MPoint.x + 24;
//		OutputPoint.y = MPoint.y + 12;
//	}
//	else {
//		OutputPoint.x = MPoint.x + 48;
//		OutputPoint.y = MPoint.y + 24;
//	}
//}

void LogicEngine::SetInput()
{
	CString name;
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	name = pFrame->m_pLogisimView->gatename;
	if (name == "NOT") {
		input[0].pointState.x = MPoint.x;
		input[0].pointState.y = MPoint.y + 12;
	}
	else {
		input[0].pointState.x = MPoint.x;
		input[0].pointState.y = MPoint.y + 16;
		input[1].pointState.x = MPoint.x;
		input[1].pointState.y = MPoint.y + 16 * 2;
	}
}