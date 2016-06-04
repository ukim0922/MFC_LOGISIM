#include "stdafx.h"
#include "FilpFlopEngine.h"


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
	if (h_ck == TRUE) //상승 에지트리거
	{
		if (clock_pre == TRUE && clock_cur == FALSE)
		{
			output[0].boolState = input[0].boolState;
		}
	}
	else //하강 에지트리거
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

		if (h_ck == TRUE) //상승 에지트리거
		{
			if (clock_pre == TRUE && clock_cur == FALSE)
			{
				bool temp;
				temp = output[0].boolState;
				output[0].boolState = output[1].boolState;
				output[0].boolState = temp;
			}
		}
		else //하강 에지트리거
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
		//변함이 없음.
	}
}

void JKFF::FlipFlopLogic()
{
	if (h_ck == TRUE) //상승 에지 트리거
	{
		if (clock_pre == TRUE && clock_cur == FALSE)
		{
			if ((input[0].boolState == FALSE) && (input[1].boolState == FALSE)) {
				// 변화 없음
			}
			else if ((input[0].boolState == FALSE) && (input[1].boolState == TRUE))
			{	// 0으로 리셋
				output[0].boolState = FALSE;
			}
			else if ((input[0].boolState == TRUE) && (input[1].boolState == FALSE))
			{	// 1로 세트
				output[0].boolState = TRUE;
			}
			else if ((input[0].boolState == TRUE) && (input[1].boolState == TRUE))
			{	// 토글
				if (output[0].boolState)
					output[0].boolState = FALSE;
				else
					output[0].boolState = TRUE;
			}
			else
			{
				AfxMessageBox(_T("JK FilpFilop 논리 에러"), MB_OKCANCEL);
			}

			if (output[0].boolState) //Q가 T이면
				output[1].boolState = FALSE; //Q'는 F
			else // Q가 F면
				output[1].boolState = TRUE; // Q'는 T

		}
	}
	else //하강 에지 트리거
	{
		if (clock_pre == FALSE && clock_cur == TRUE)
		{
			if ((input[0].boolState == FALSE) && (input[1].boolState == FALSE)) {
				// 변화 없음
			}
			else if ((input[0].boolState == FALSE) && (input[1].boolState == TRUE))
			{	// 0으로 리셋
				output[0].boolState = FALSE;
			}
			else if ((input[0].boolState == TRUE) && (input[1].boolState == FALSE))
			{	// 1로 세트
				output[0].boolState = TRUE;
			}
			else if ((input[0].boolState == TRUE) && (input[1].boolState == TRUE))
			{	// 토글
				if (output[0].boolState)
					output[0].boolState = FALSE;
				else
					output[0].boolState = TRUE;
			}
			else
			{
				AfxMessageBox(_T("JK FilpFilop 논리 에러"), MB_OKCANCEL);
			}

			if (output[0].boolState) //Q가 T이면
				output[1].boolState = FALSE; //Q'는 F
			else // Q가 F면
				output[1].boolState = TRUE; // Q'는 T
		}
	}
}
