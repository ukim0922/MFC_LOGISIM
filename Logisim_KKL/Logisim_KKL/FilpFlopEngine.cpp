#include "stdafx.h"
#include "FilpFlopEngine.h"


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

void FilpFlopEngine::FilpFlop(FlipFlopSelect Select)
{
	switch (Select)
	{
	case T_FF:
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
		break;

	case D_FF: //입력 그대로 출력
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
		break;
	case JK_FF:
		if (h_ck == TRUE) //상승 에지 트리거
		{


		}
		else //하강 에지 트리거
		{

		}
		break;
	default:
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate 인 경우
		break;
	}

}

