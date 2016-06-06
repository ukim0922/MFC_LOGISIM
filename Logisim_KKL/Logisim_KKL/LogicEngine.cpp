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
	dc.TextOutW(MRect.TopLeft().x +MRect.Width(), MRect.TopLeft().y - 5, GetLabel());

}

void LogicEngine::SetInOutValues(Gdiplus::REAL angle)
{
	CString name;
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	name = pFrame->m_pLogisimView->gatename;
	//NOT����Ʈ�� ��
	if (name == "NOT") {
		switch ((int)angle % 360) {
		case 0:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
			output[0].rectState = CRect(MPoint.x + 20, MPoint.y + 8, MPoint.x + 28, MPoint.y + 16);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x;
			input[0].pointState.y = MPoint.y + 12;
			output[0].pointState.x = MPoint.x + 24;
			output[0].pointState.y = MPoint.y + 12;
			break;
		case 90:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
			output[0].rectState = CRect(MPoint.x + 8, MPoint.y + 20, MPoint.x + 16, MPoint.y + 28);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x + 12;
			input[0].pointState.y = MPoint.y;
			output[0].pointState.x = MPoint.x + 12;
			output[0].pointState.y = MPoint.y + 24;
			break;
		case 180:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 20, MPoint.y + 8, MPoint.x + 28, MPoint.y + 16);
			output[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x + 24;
			input[0].pointState.y = MPoint.y + 12;
			output[0].pointState.x = MPoint.x;
			output[0].pointState.y = MPoint.y + 12;
		case 270:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 8, MPoint.y + 20, MPoint.x + 16, MPoint.y + 28);
			output[0].rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x + 12;
			input[0].pointState.y = MPoint.y + 24;
			output[0].pointState.x = MPoint.x + 12;
			output[0].pointState.y = MPoint.y;
			break;
		}
	}
	//��� ������ ��
	else if (name == "BITLAMP") {
		switch ((int)angle % 360) {
		case 0:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x;
			input[0].pointState.y = MPoint.y + 12;
		case 90:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 8, MPoint.y + 20, MPoint.x + 16, MPoint.y + 28);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x + 12;
			input[0].pointState.y = MPoint.y + 24;
		case 180:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x;
			input[0].pointState.y = MPoint.y + 12;
		case 270:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x + 12;
			input[0].pointState.y = MPoint.y;
			break;
		}
	}
	//Ŭ��, �Է��� ��
	if (name == "CLK" || name == "Input") {
		switch ((int)angle % 360) {
		case 0:
			//�簢�� ���� ����
			output[0].rectState = CRect(MPoint.x + 20, MPoint.y + 8, MPoint.x + 28, MPoint.y + 16);
			//��ǥ ���� ����
			output[0].pointState.x = MPoint.x + 24;
			output[0].pointState.y = MPoint.y + 12;
			break;
		case 90:
			//�簢�� ���� ����
			output[0].rectState = CRect(MPoint.x + 8, MPoint.y + 20, MPoint.x + 16, MPoint.y + 28);
			//��ǥ ���� ����
			output[0].pointState.x = MPoint.x + 12;
			output[0].pointState.y = MPoint.y + 24;
			break;
		case 180:
			//�簢�� ���� ����
			output[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
			//��ǥ ���� ����
			output[0].pointState.x = MPoint.x;
			output[0].pointState.y = MPoint.y + 12;
		case 270:
			//�簢�� ���� ����
			output[0].rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
			//��ǥ ���� ����
			output[0].pointState.x = MPoint.x + 12;
			output[0].pointState.y = MPoint.y;
			break;
		}
	}
	//������ ����Ʈ��
	else {
		switch ((int)angle % 360) {
		case 0:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x - 4, MPoint.y + 12, MPoint.x + 4, MPoint.y + 20);
			input[1].rectState = CRect(MPoint.x - 4, MPoint.y + 28, MPoint.x + 4, MPoint.y + 36);
			output[0].rectState = CRect(MPoint.x + 44, MPoint.y + 20, MPoint.x + 52, MPoint.y + 28);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x;
			input[0].pointState.y = MPoint.y + 16;
			input[1].pointState.x = MPoint.x;
			input[1].pointState.y = MPoint.y + 32;
			output[0].pointState.x = MPoint.x + 48;
			output[0].pointState.y = MPoint.y + 24;
			break;
		case 90:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 12, MPoint.y - 4, MPoint.x + 20, MPoint.y + 4);
			input[1].rectState = CRect(MPoint.x + 28, MPoint.y - 4, MPoint.x + 36, MPoint.y + 4);
			output[0].rectState = CRect(MPoint.x + 20, MPoint.y + 44, MPoint.x + 28, MPoint.y + 52);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x + 16;
			input[0].pointState.y = MPoint.y;
			input[1].pointState.x = MPoint.x + 32;
			input[1].pointState.y = MPoint.y;
			output[0].pointState.x = MPoint.x + 24;
			output[0].pointState.y = MPoint.y + 48;
			break;
		case 180:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 44, MPoint.y + 12, MPoint.x + 52, MPoint.y + 20);
			input[1].rectState = CRect(MPoint.x + 44, MPoint.y + 28, MPoint.x + 52, MPoint.y + 36);
			output[0].rectState = CRect(MPoint.x - 4, MPoint.y + 20, MPoint.x + 4, MPoint.y + 28);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x + 48;
			input[0].pointState.y = MPoint.y + 16;
			input[1].pointState.x = MPoint.x + 48;
			input[1].pointState.y = MPoint.y + 32;
			output[0].pointState.x = MPoint.x;
			output[0].pointState.y = MPoint.y + 24;
		case 270:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 12, MPoint.y + 44, MPoint.x + 20, MPoint.y + 52);
			input[1].rectState = CRect(MPoint.x + 28, MPoint.y + 44, MPoint.x + 36, MPoint.y + 52);
			output[0].rectState = CRect(MPoint.x + 20, MPoint.y - 4, MPoint.x + 28, MPoint.y + 4);
			//��ǥ ���� ����
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


//7-segment ����Լ�(�Ϸ�)
void Seven::Print_7_segment( CClientDC &dc)
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


void Seven::Set_7Rect()
{
	rect[0].SetRect(point.x-20, point.y, point.x+10, point.y+10);
	rect[1].SetRect(point.x-20, point.y+10, point.x+10, point.y+20);
	rect[2].SetRect(point.x-20, point.y+20, point.x+10, point.y+30);
	rect[3].SetRect(point.x-20, point.y+30, point.x+10, point.y+40);
	rect[4].SetRect(point.x-20, point.y+40, point.x + 10, point.y+50);
	rect[5].SetRect(point.x-20, point.y+50, point.x + 10, point.y+60);
	rect[6].SetRect(point.x-20, point.y+60, point.x + 10, point.y+70);

}

Seven::Seven(CPoint &point) {
	this->point = point;
}

//7-segment ���ں� ����Լ�(������)
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
	//NOT����Ʈ, ��� ������ ��
	if (name == "NOT" || name == "LAMP" || name == "Input" || name == "CLK") {
		MRect = CRect(MPoint.x, MPoint.y, MPoint.x + 24, MPoint.y + 24);
	}
	//������ ����Ʈ��
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


void FilpFlopEngine::FlipFlopLogic()
{
}

FilpFlopEngine::FilpFlopEngine()
{
}


FilpFlopEngine::~FilpFlopEngine()
{
}


void  FilpFlopEngine::Paint(CClientDC &dc) {
	CBitmap bitmap;
	bitmap.LoadBitmap(BITMAPID);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CDC dcmem;

	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	dc.BitBlt(MPoint.x, MPoint.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
}
void  FilpFlopEngine::Rotate(CClientDC &dc, Gdiplus::REAL angle) {
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


void DFF::FlipFlopLogic()
{
	if (h_ck == TRUE) //��� ����Ʈ����
	{
		if (clock_pre == TRUE && clock_cur == FALSE)
		{
			output[0].boolState = input[0].boolState;
		}
	}
	else //�ϰ� ����Ʈ����
	{
		if (clock_pre == FALSE && clock_cur == TRUE)
		{
			output[0].boolState = input[0].boolState;
		}
	}
}

void TFF::FlipFlopLogic()
{
	if (input[0].boolState) {

		if (h_ck == TRUE) //��� ����Ʈ����
		{
			if (clock_pre == TRUE && clock_cur == FALSE)
			{
				bool temp;
				temp = output[0].boolState;
				output[0].boolState = output[1].boolState;
				output[0].boolState = temp;
			}
		}
		else //�ϰ� ����Ʈ����
		{
			if (clock_pre == FALSE && clock_cur == TRUE)
			{
				bool temp;
				temp = output[0].boolState;
				output[0].boolState = output[1].boolState;
				output[0].boolState = temp;
			}
		}
	}
	else {
		//������ ����.
	}
}

void JKFF::FlipFlopLogic()
{
	if (h_ck == TRUE) //��� ���� Ʈ����
	{
		if (clock_pre == TRUE && clock_cur == FALSE)
		{
			if ((input[0].boolState == FALSE) && (input[1].boolState == FALSE)) {
				// ��ȭ ����
			}
			else if ((input[0].boolState == FALSE) && (input[1].boolState == TRUE))
			{	// 0���� ����
				output[0].boolState = FALSE;
			}
			else if ((input[0].boolState == TRUE) && (input[1].boolState == FALSE))
			{	// 1�� ��Ʈ
				output[0].boolState = TRUE;
			}
			else if ((input[0].boolState == TRUE) && (input[1].boolState == TRUE))
			{	// ���
				if (output[0].boolState)
					output[0].boolState = FALSE;
				else
					output[0].boolState = TRUE;
			}
			else
			{
				AfxMessageBox(_T("JK FilpFilop �� ����"), MB_OKCANCEL);
			}

			if (output[0].boolState) //Q�� T�̸�
				output[1].boolState = FALSE; //Q'�� F
			else // Q�� F��
				output[1].boolState = TRUE; // Q'�� T

		}
	}
	else //�ϰ� ���� Ʈ����
	{
		if (clock_pre == FALSE && clock_cur == TRUE)
		{
			if ((input[0].boolState == FALSE) && (input[1].boolState == FALSE)) {
				// ��ȭ ����
			}
			else if ((input[0].boolState == FALSE) && (input[1].boolState == TRUE))
			{	// 0���� ����
				output[0].boolState = FALSE;
			}
			else if ((input[0].boolState == TRUE) && (input[1].boolState == FALSE))
			{	// 1�� ��Ʈ
				output[0].boolState = TRUE;
			}
			else if ((input[0].boolState == TRUE) && (input[1].boolState == TRUE))
			{	// ���
				if (output[0].boolState)
					output[0].boolState = FALSE;
				else
					output[0].boolState = TRUE;
			}
			else
			{
				AfxMessageBox(_T("JK FilpFilop �� ����"), MB_OKCANCEL);
			}

			if (output[0].boolState) //Q�� T�̸�
				output[1].boolState = FALSE; //Q'�� F
			else // Q�� F��
				output[1].boolState = TRUE; // Q'�� T
		}
	}
}


void FilpFlopEngine::SetInOutValues(Gdiplus::REAL angle)
{
	CString name;
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	name = pFrame->m_pLogisimView->gatename;
	if (name == "D-FF") {
		switch ((int)angle % 360) {
		case 0:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x - 4, MPoint.y + 12, MPoint.x + 4, MPoint.y + 20);
			clk.rectState = CRect(MPoint.x - 4, MPoint.y + 32, MPoint.x + 4, MPoint.y + 40);
			output[0].rectState = CRect(MPoint.x + 44, MPoint.y + 4, MPoint.x + 52, MPoint.y + 12);
			output[1].rectState = CRect(MPoint.x + 44, MPoint.y + 32, MPoint.x + 52, MPoint.y + 40);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x;
			input[0].pointState.y = MPoint.y + 16;
			clk.pointState.x = MPoint.x;
			clk.pointState.y = MPoint.y + 36;
			output[0].pointState.x = MPoint.x + 48;
			output[0].pointState.y = MPoint.y + 8;
			output[1].pointState.x = MPoint.x + 48;
			output[1].pointState.y = MPoint.y + 36;
			break;
		case 90:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 28, MPoint.y - 4, MPoint.x + 36, MPoint.y + 4);
			clk.rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
			output[0].rectState = CRect(MPoint.x + 36, MPoint.y + 44, MPoint.x + 44, MPoint.y + 52);
			output[1].rectState = CRect(MPoint.x + 8, MPoint.y + 44, MPoint.x + 16, MPoint.y + 52);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x + 32;
			input[0].pointState.y = MPoint.y;
			clk.pointState.x = MPoint.x + 12;
			clk.pointState.y = MPoint.y;
			output[0].pointState.x = MPoint.x + 40;
			output[0].pointState.y = MPoint.y + 48;
			output[1].pointState.x = MPoint.x + 12;
			output[1].pointState.y = MPoint.y + 48;
			break;
		case 180:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 44, MPoint.y + 28, MPoint.x + 52, MPoint.y + 36);
			clk.rectState = CRect(MPoint.x + 44, MPoint.y + 8, MPoint.x + 52, MPoint.y + 16);
			output[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
			output[1].rectState = CRect(MPoint.x - 4, MPoint.y + 36, MPoint.x + 4, MPoint.y + 44);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x + 48;
			input[0].pointState.y = MPoint.y + 32;
			clk.pointState.x = MPoint.x + 48;
			clk.pointState.y = MPoint.y + 12;
			output[0].pointState.x = MPoint.x;
			output[0].pointState.y = MPoint.y + 12;
			output[1].pointState.x = MPoint.x;
			output[1].pointState.y = MPoint.y + 40;
			break;
		case 270:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 4, MPoint.y - 4, MPoint.x + 12, MPoint.y + 4);
			clk.rectState = CRect(MPoint.x + 32, MPoint.y - 4, MPoint.x + 40, MPoint.y + 4);
			output[0].rectState = CRect(MPoint.x + 12, MPoint.y + 44, MPoint.x + 20, MPoint.y + 52);
			output[1].rectState = CRect(MPoint.x + 44, MPoint.y + 44, MPoint.x + 52, MPoint.y + 52);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x + 8;
			input[0].pointState.y = MPoint.y;
			clk.pointState.x = MPoint.x + 36;
			clk.pointState.y = MPoint.y;
			output[0].pointState.x = MPoint.x + 16;
			output[0].pointState.y = MPoint.y + 48;
			output[1].pointState.x = MPoint.x + 36;
			output[1].pointState.y = MPoint.y + 48;
			break;
		}
	}
	else if (name == "T-FF") {
		switch ((int)angle % 360) {
		case 0:
			//�簢�� ���� ����
			input[1].rectState = CRect(MPoint.x - 4, MPoint.y + 12, MPoint.x + 4, MPoint.y + 20);
			clk.rectState = CRect(MPoint.x - 4, MPoint.y + 32, MPoint.x + 4, MPoint.y + 40);
			output[0].rectState = CRect(MPoint.x + 44, MPoint.y + 4, MPoint.x + 52, MPoint.y + 12);
			output[1].rectState = CRect(MPoint.x + 44, MPoint.y + 32, MPoint.x + 52, MPoint.y + 40);
			//��ǥ ���� ����
			input[1].pointState.x = MPoint.x;
			input[1].pointState.y = MPoint.y + 16;
			clk.pointState.x = MPoint.x;
			clk.pointState.y = MPoint.y + 36;
			output[0].pointState.x = MPoint.x + 48;
			output[0].pointState.y = MPoint.y + 8;
			output[1].pointState.x = MPoint.x + 48;
			output[1].pointState.y = MPoint.y + 36;
			break;
		case 90:
			//�簢�� ���� ����
			input[1].rectState = CRect(MPoint.x + 28, MPoint.y - 4, MPoint.x + 36, MPoint.y + 4);
			clk.rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
			output[0].rectState = CRect(MPoint.x + 36, MPoint.y + 44, MPoint.x + 44, MPoint.y + 52);
			output[1].rectState = CRect(MPoint.x + 8, MPoint.y + 44, MPoint.x + 16, MPoint.y + 52);
			//��ǥ ���� ����
			input[1].pointState.x = MPoint.x + 32;
			input[1].pointState.y = MPoint.y;
			clk.pointState.x = MPoint.x + 12;
			clk.pointState.y = MPoint.y;
			output[0].pointState.x = MPoint.x + 40;
			output[0].pointState.y = MPoint.y + 48;
			output[1].pointState.x = MPoint.x + 12;
			output[1].pointState.y = MPoint.y + 48;
			break;
		case 180:
			//�簢�� ���� ����
			input[1].rectState = CRect(MPoint.x + 44, MPoint.y + 28, MPoint.x + 52, MPoint.y + 36);
			clk.rectState = CRect(MPoint.x + 44, MPoint.y + 8, MPoint.x + 52, MPoint.y + 16);
			output[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
			output[1].rectState = CRect(MPoint.x - 4, MPoint.y + 36, MPoint.x + 4, MPoint.y + 44);
			//��ǥ ���� ����
			input[1].pointState.x = MPoint.x + 48;
			input[1].pointState.y = MPoint.y + 32;
			clk.pointState.x = MPoint.x + 48;
			clk.pointState.y = MPoint.y + 12;
			output[0].pointState.x = MPoint.x;
			output[0].pointState.y = MPoint.y + 12;
			output[1].pointState.x = MPoint.x;
			output[1].pointState.y = MPoint.y + 40;
			break;
		case 270:
			//�簢�� ���� ����
			input[1].rectState = CRect(MPoint.x + 4, MPoint.y - 4, MPoint.x + 12, MPoint.y + 4);
			clk.rectState = CRect(MPoint.x + 32, MPoint.y - 4, MPoint.x + 40, MPoint.y + 4);
			output[0].rectState = CRect(MPoint.x + 12, MPoint.y + 44, MPoint.x + 20, MPoint.y + 52);
			output[1].rectState = CRect(MPoint.x + 44, MPoint.y + 44, MPoint.x + 52, MPoint.y + 52);
			//��ǥ ���� ����
			input[1].pointState.x = MPoint.x + 8;
			input[1].pointState.y = MPoint.y;
			clk.pointState.x = MPoint.x + 36;
			clk.pointState.y = MPoint.y;
			output[0].pointState.x = MPoint.x + 16;
			output[0].pointState.y = MPoint.y + 48;
			output[1].pointState.x = MPoint.x + 36;
			output[1].pointState.y = MPoint.y + 48;
			break;
		}
	}
	else if (name == "JK-FF") {
		switch ((int)angle % 360) {
		case 0:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x - 4, MPoint.y + 4, MPoint.x + 4, MPoint.y + 12);
			input[1].rectState = CRect(MPoint.x - 4, MPoint.y + 20, MPoint.x + 4, MPoint.y + 28);
			clk.rectState = CRect(MPoint.x - 4, MPoint.y + 32, MPoint.x + 4, MPoint.y + 40);
			output[0].rectState = CRect(MPoint.x + 44, MPoint.y + 4, MPoint.x + 52, MPoint.y + 12);
			output[1].rectState = CRect(MPoint.x + 44, MPoint.y + 32, MPoint.x + 52, MPoint.y + 40);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x;
			input[0].pointState.y = MPoint.y + 8;
			input[1].pointState.x = MPoint.x;
			input[1].pointState.y = MPoint.y + 24;
			clk.pointState.x = MPoint.x;
			clk.pointState.y = MPoint.y + 36;
			output[0].pointState.x = MPoint.x + 48;
			output[0].pointState.y = MPoint.y + 8;
			output[1].pointState.x = MPoint.x + 48;
			output[1].pointState.y = MPoint.y + 36;
			break;
		case 90:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 36, MPoint.y - 4, MPoint.x + 44, MPoint.y + 4);
			input[1].rectState = CRect(MPoint.x + 8, MPoint.y - 4, MPoint.x + 16, MPoint.y + 4);
			clk.rectState = CRect(MPoint.x + 20, MPoint.y - 4, MPoint.x + 28, MPoint.y + 4);
			output[0].rectState = CRect(MPoint.x + 36, MPoint.y + 44, MPoint.x + 44, MPoint.y + 52);
			output[1].rectState = CRect(MPoint.x + 8, MPoint.y + 44, MPoint.x + 16, MPoint.y + 52);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x + 40;
			input[0].pointState.y = MPoint.y;
			input[1].pointState.x = MPoint.x + 12;
			input[1].pointState.y = MPoint.y;
			clk.pointState.x = MPoint.x + 24;
			clk.pointState.y = MPoint.y;
			output[0].pointState.x = MPoint.x + 40;
			output[0].pointState.y = MPoint.y + 48;
			output[1].pointState.x = MPoint.x + 12;
			output[1].pointState.y = MPoint.y + 48;
			break;
		case 180:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 44, MPoint.y + 36, MPoint.x + 52, MPoint.y + 44);
			input[1].rectState = CRect(MPoint.x + 44, MPoint.y + 8, MPoint.x + 52, MPoint.y + 16);
			clk.rectState = CRect(MPoint.x + 44, MPoint.y + 20, MPoint.x + 52, MPoint.y + 28);
			output[0].rectState = CRect(MPoint.x - 4, MPoint.y + 8, MPoint.x + 4, MPoint.y + 16);
			output[1].rectState = CRect(MPoint.x - 4, MPoint.y + 36, MPoint.x + 4, MPoint.y + 44);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x + 48;
			input[0].pointState.y = MPoint.y + 40;
			input[1].pointState.x = MPoint.x + 48;
			input[1].pointState.y = MPoint.y + 12;
			clk.pointState.x = MPoint.x + 48;
			clk.pointState.y = MPoint.y + 24;
			output[0].pointState.x = MPoint.x;
			output[0].pointState.y = MPoint.y + 12;
			output[1].pointState.x = MPoint.x;
			output[1].pointState.y = MPoint.y + 40;
			break;
		case 270:
			//�簢�� ���� ����
			input[0].rectState = CRect(MPoint.x + 4, MPoint.y + 44, MPoint.x + 12, MPoint.y + 52);
			input[1].rectState = CRect(MPoint.x + 32, MPoint.y + 44, MPoint.x + 40, MPoint.y + 52);
			clk.rectState = CRect(MPoint.x + 20, MPoint.y + 44, MPoint.x + 28, MPoint.y + 52);
			output[0].rectState = CRect(MPoint.x + 4, MPoint.y - 4, MPoint.x + 12, MPoint.y + 4);
			output[1].rectState = CRect(MPoint.x + 32, MPoint.y - 4, MPoint.x + 40, MPoint.y + 4);
			//��ǥ ���� ����
			input[0].pointState.x = MPoint.x + 8;
			input[0].pointState.y = MPoint.y + 48;
			input[1].pointState.x = MPoint.x + 36;
			input[1].pointState.y = MPoint.y + 48;
			clk.pointState.x = MPoint.x + 24;
			clk.pointState.y = MPoint.y + 48;
			output[0].pointState.x = MPoint.x + 8;
			output[0].pointState.y = MPoint.y;
			output[1].pointState.x = MPoint.x + 36;
			output[1].pointState.y = MPoint.y;
			break;
		}
	}
}