#pragma once
#include "LogicEngine.h"

class FilpFlopEngine : public LogicEngine
{
public:

	bool clock_pre = TRUE; //Ŭ������
	bool clock_cur = TRUE;
	bool h_ck = TRUE; //����Ʈ���Ź�� (����̸�true, �ϰ��̸�false) Ŭ�����ι޾ƿÿ���

	//�ø��÷� ��� ����
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


//�ø��÷�
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