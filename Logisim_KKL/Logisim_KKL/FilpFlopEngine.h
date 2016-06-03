#pragma once
#include "LogicEngine.h"

class FilpFlopEngine : public LogicEngine
{
public:

	bool clock_pre = TRUE; //클럭변수
	bool clock_cur = TRUE;
	bool h_ck = TRUE; //에지트리거방식 (상승이면true, 하강이면false) 클릭으로받아올예정

	//플립플롭 기능 구현
	void FilpFlop(FlipFlopSelect Select);

	FilpFlopEngine();
	FilpFlopEngine(CPoint MPoint, UINT BITMAPID) {
		this->MPoint = MPoint;
		this->BITMAPID = BITMAPID;
	}
	~FilpFlopEngine();
	void Paint(CClientDC & dc);
	void Rotate(CClientDC & dc, Gdiplus::REAL angle);
};


//플립플롭
class DFF : public FilpFlopEngine {
public:
	DFF(CPoint MPoint, UINT BITMAPID) : FilpFlopEngine(MPoint, BITMAPID) {
	}
};

class TFF : public FilpFlopEngine {
public:
	TFF(CPoint MPoint, UINT BITMAPID) : FilpFlopEngine(MPoint, BITMAPID) {
	}
};

class JKFF : public FilpFlopEngine {
public:
	JKFF(CPoint MPoint, UINT BITMAPID) : FilpFlopEngine(MPoint, BITMAPID) {
	}
};