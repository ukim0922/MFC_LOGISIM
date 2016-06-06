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

void LogicEngine::SmallPaint(CClientDC & dc)
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

void LogicEngine::SmallRotate(CClientDC & dc, Gdiplus::REAL angle)
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
	graphics.DrawImage(&tempbmp, MPoint.x, MPoint.y, (pBitmap->GetWidth()) / 2, (pBitmap->GetHeight()) / 2);
}

void LogicEngine::PrintLabel(CClientDC &dc,CString Label) {
	SetLabel(Label);
	dc.TextOutW(MRect.BottomRight().x, MRect.BottomRight().y - 20, GetLabel());

}

void LogicEngine::SetInOutValues(Gdiplus::REAL angle)
{
	CString name;
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	name = pFrame->m_pLogisimView->gatename;
	//NOT게이트일 때
	if (name == "NOT") {
		switch ((int)angle % 360) {
		case 0:
			//사각형 영역 지정
			input[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
			output[0].rectState = CRect(MPoint.x + 20, MPoint.y + 8, MPoint.x + 28, MPoint.y + 16);
			//좌표 영역 지정
			input[0].pointState.x = MPoint.x;
			input[0].pointState.y = MPoint.y + 12;
			output[0].pointState.x = MPoint.x + 24;
			output[0].pointState.y = MPoint.y + 12;
			break;
		case 90:
			//사각형 영역 지정
			input[0].rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
			output[0].rectState = CRect(MPoint.x + 8, MPoint.y + 20, MPoint.x + 16, MPoint.y + 28);
			//좌표 영역 지정
			input[0].pointState.x = MPoint.x + 12;
			input[0].pointState.y = MPoint.y;
			output[0].pointState.x = MPoint.x + 12;
			output[0].pointState.y = MPoint.y + 24;
			break;
		case 180:
			//사각형 영역 지정
			input[0].rectState = CRect(MPoint.x + 20, MPoint.y + 8, MPoint.x + 28, MPoint.y + 16);
			output[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
			//좌표 영역 지정
			input[0].pointState.x = MPoint.x + 24;
			input[0].pointState.y = MPoint.y + 12;
			output[0].pointState.x = MPoint.x;
			output[0].pointState.y = MPoint.y + 12;
		case 270:
			//사각형 영역 지정
			input[0].rectState = CRect(MPoint.x + 8, MPoint.y + 20, MPoint.x + 16, MPoint.y + 28);
			output[0].rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
			//좌표 영역 지정
			input[0].pointState.x = MPoint.x + 12;
			input[0].pointState.y = MPoint.y + 24;
			output[0].pointState.x = MPoint.x + 12;
			output[0].pointState.y = MPoint.y;
			break;
		}
	}
	//출력 램프일 때
	else if (name == "BITLAMP") {
		switch ((int)angle % 360) {
		case 0:
			//사각형 영역 지정
			input[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
			//좌표 영역 지정
			input[0].pointState.x = MPoint.x;
			input[0].pointState.y = MPoint.y + 12;
		case 90:
			//사각형 영역 지정
			input[0].rectState = CRect(MPoint.x + 8, MPoint.y + 20, MPoint.x + 16, MPoint.y + 28);
			//좌표 영역 지정
			input[0].pointState.x = MPoint.x + 12;
			input[0].pointState.y = MPoint.y + 24;
		case 180:
			//사각형 영역 지정
			input[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
			//좌표 영역 지정
			input[0].pointState.x = MPoint.x;
			input[0].pointState.y = MPoint.y + 12;
		case 270:
			//사각형 영역 지정
			input[0].rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
			//좌표 영역 지정
			input[0].pointState.x = MPoint.x + 12;
			input[0].pointState.y = MPoint.y;
			break;
		}
	}
	//클럭, 입력일 때
	if (name == "CLK" || name == "입력") {
		switch ((int)angle % 360) {
		case 0:
			//사각형 영역 지정
			output[0].rectState = CRect(MPoint.x + 20, MPoint.y + 8, MPoint.x + 28, MPoint.y + 16);
			//좌표 영역 지정
			output[0].pointState.x = MPoint.x + 24;
			output[0].pointState.y = MPoint.y + 12;
			break;
		case 90:
			//사각형 영역 지정
			output[0].rectState = CRect(MPoint.x + 8, MPoint.y + 20, MPoint.x + 16, MPoint.y + 28);
			//좌표 영역 지정
			output[0].pointState.x = MPoint.x + 12;
			output[0].pointState.y = MPoint.y + 24;
			break;
		case 180:
			//사각형 영역 지정
			output[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
			//좌표 영역 지정
			output[0].pointState.x = MPoint.x;
			output[0].pointState.y = MPoint.y + 12;
		case 270:
			//사각형 영역 지정
			output[0].rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
			//좌표 영역 지정
			output[0].pointState.x = MPoint.x + 12;
			output[0].pointState.y = MPoint.y;
			break;
		}
	}
	//나머지 게이트들
	else {
		switch ((int)angle % 360) {
		case 0:
			//사각형 영역 지정
			input[0].rectState = CRect(MPoint.x - 4, MPoint.y + 12, MPoint.x + 4, MPoint.y + 20);
			input[1].rectState = CRect(MPoint.x - 4, MPoint.y + 28, MPoint.x + 4, MPoint.y + 36);
			output[0].rectState = CRect(MPoint.x + 44, MPoint.y + 20, MPoint.x + 52, MPoint.y + 28);
			//좌표 영역 지정
			input[0].pointState.x = MPoint.x;
			input[0].pointState.y = MPoint.y + 16;
			input[1].pointState.x = MPoint.x;
			input[1].pointState.y = MPoint.y + 32;
			output[0].pointState.x = MPoint.x + 48;
			output[0].pointState.y = MPoint.y + 24;
			break;
		case 90:
			//사각형 영역 지정
			input[0].rectState = CRect(MPoint.x + 12, MPoint.y - 4, MPoint.x + 20, MPoint.y + 4);
			input[1].rectState = CRect(MPoint.x + 28, MPoint.y - 4, MPoint.x + 36, MPoint.y + 4);
			output[0].rectState = CRect(MPoint.x + 20, MPoint.y + 44, MPoint.x + 28, MPoint.y + 52);
			//좌표 영역 지정
			input[0].pointState.x = MPoint.x + 16;
			input[0].pointState.y = MPoint.y;
			input[1].pointState.x = MPoint.x + 32;
			input[1].pointState.y = MPoint.y;
			output[0].pointState.x = MPoint.x + 24;
			output[0].pointState.y = MPoint.y + 48;
			break;
		case 180:
			//사각형 영역 지정
			input[0].rectState = CRect(MPoint.x + 44, MPoint.y + 12, MPoint.x + 52, MPoint.y + 20);
			input[1].rectState = CRect(MPoint.x + 44, MPoint.y + 28, MPoint.x + 52, MPoint.y + 36);
			output[0].rectState = CRect(MPoint.x - 4, MPoint.y + 20, MPoint.x + 4, MPoint.y + 28);
			//좌표 영역 지정
			input[0].pointState.x = MPoint.x + 48;
			input[0].pointState.y = MPoint.y + 16;
			input[1].pointState.x = MPoint.x + 48;
			input[1].pointState.y = MPoint.y + 32;
			output[0].pointState.x = MPoint.x;
			output[0].pointState.y = MPoint.y + 24;
		case 270:
			//사각형 영역 지정
			input[0].rectState = CRect(MPoint.x + 12, MPoint.y + 44, MPoint.x + 20, MPoint.y + 52);
			input[1].rectState = CRect(MPoint.x + 28, MPoint.y + 44, MPoint.x + 36, MPoint.y + 52);
			output[0].rectState = CRect(MPoint.x + 20, MPoint.y - 4, MPoint.x + 28, MPoint.y + 4);
			//좌표 영역 지정
			input[0].pointState.x = MPoint.x + 16;
			input[0].pointState.y = MPoint.y + 48;
			input[1].pointState.x = MPoint.x + 32;
			input[1].pointState.y = MPoint.y + 48;
			output[0].pointState.x = MPoint.x + 24;
			output[0].pointState.y = MPoint.y;
			break;
		}
	}
}

LogicEngine::~LogicEngine()
{
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
			dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);  //w
			dc.BitBlt(point.x - bmpinfo_h.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x - bmpinfo_w.bmWidth, point.y + 3 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);//h
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + 3 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);//h
			dc.BitBlt(point.x, point.y + 4 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			break;
		case 1:
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + 3 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);//h
			break;
		case 2:
			dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);  //w
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x, point.y + 2 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			dc.BitBlt(point.x - bmpinfo_w.bmWidth, point.y + 3 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);//h
			dc.BitBlt(point.x, point.y + 4 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			break;
		case 3:
			dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);  //w
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x, point.y + 2 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + 3 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);//h
			dc.BitBlt(point.x, point.y + 4 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			break;
		case 4:
			dc.BitBlt(point.x - bmpinfo_h.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x, point.y + 2 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + 3 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);//h
			break;
		case 5:
			dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);  //w
			dc.BitBlt(point.x - bmpinfo_h.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x, point.y + 2 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + 3 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);//h
			dc.BitBlt(point.x, point.y + 4 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			break;
		case 6:
			dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);  //w
			dc.BitBlt(point.x - bmpinfo_h.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x, point.y + 2 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			dc.BitBlt(point.x - bmpinfo_w.bmWidth, point.y + 3 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);//h
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + 3 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);//h
			dc.BitBlt(point.x, point.y + 4 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			break;
		case 7:
			dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);  //w
			dc.BitBlt(point.x - bmpinfo_h.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + 3 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);//h
			break;
		case 8:
			dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);  //w
			dc.BitBlt(point.x - bmpinfo_h.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x, point.y + 2 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			dc.BitBlt(point.x - bmpinfo_w.bmWidth, point.y + 3 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);//h
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + 3 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);//h
			dc.BitBlt(point.x, point.y + 4 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			break;
		case 9:
			dc.BitBlt(point.x, point.y, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);  //w
			dc.BitBlt(point.x - bmpinfo_h.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY); //h
			dc.BitBlt(point.x, point.y + 2 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			dc.BitBlt(point.x + bmpinfo_w.bmWidth, point.y + 3 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_h, 0, 0, SRCCOPY);//h
			dc.BitBlt(point.x, point.y + 4 * bmpinfo_w.bmHeight, bmpinfo_w.bmWidth, bmpinfo_w.bmHeight, &dcmem_w, 0, 0, SRCCOPY);//w
			break;
		default:
			break;
	}
}


void LogicEngine::SetRect()
{
	CString name;
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	name = pFrame->m_pLogisimView->gatename;
	//NOT게이트, 출력 램프일 때
	if (name == "NOT" || name == "BITLAMP" || name == "입력" || name == "CLK") {
		MRect = CRect(MPoint.x, MPoint.y, MPoint.x + 24, MPoint.y + 24);
	}
	//나머지 게이트들
	else {
		MRect = CRect(MPoint.x, MPoint.y, MPoint.x + 48, MPoint.y + 48);
	}
}
void NOTGATE::GateLogic()
{
	if (input[0].boolState)
		output[0].boolState = FALSE;
	else
		output[0].boolState = TRUE;
}

void ANDGATE::GateLogic()
{
	if ((input[0].boolState&&input[1].boolState) == TRUE) {
		output[0].boolState = TRUE;
	}
	else {
		output[0].boolState = FALSE;
	}
}

void ORGATE::GateLogic()
{
	if ((input[0].boolState == TRUE) || (input[1].boolState == TRUE)) {
		output[0].boolState = TRUE;
	}
	else
	{
		output[0].boolState = FALSE;
	}
}

void NANDGATE::GateLogic()
{
	if (input[0].boolState && input[1].boolState)
		output[0].boolState = FALSE;
	else
		output[0].boolState = TRUE;
}

void NORGATE::GateLogic()
{
	if (input[0].boolState || input[1].boolState)
		output[0].boolState = FALSE;
	else
		output[0].boolState = TRUE;
}

void XORGATE::GateLogic()
{
	if (input[0].boolState == input[1].boolState)
		output[0].boolState = FALSE;
	else
		output[0].boolState = TRUE;
}
