#pragma once
#include "InOutValues.h"
enum Facing {
	NORTH, SOUTH, WEST, EAST
};

enum GateSelect {
	AND, OR , NOT, NAND, NOR, XOR
};

enum FlipFlopSelect {
	D_FF, JK_FF, T_FF
};


class LogicEngine
{
public:
	//Ŭ�� ��ǥ�� ����
	CPoint MPoint;
	//��Ʈ��ID �������
	UINT BITMAPID;
	//���� ����
	Gdiplus::REAL angle;
	//��ü ���� ����
	CRect MRect;
	void SetRect();
	//����� ��ǥ ����
	void SetInOutValues(Gdiplus::REAL angle);

	InOutValues input[2];
	InOutValues output[2];



	//���
	void Paint(CClientDC &dc);
	//ȸ��
	void Rotate(CClientDC &dc, Gdiplus::REAL angle);
	
	//��
	void PrintLabel(CClientDC &dc, CString Label);
	void SetLabel(CString Label) { this->Label = Label; }
	CString GetLabel() { return Label; }

	LogicEngine();
	LogicEngine(CPoint MPoint,UINT BITMAPID) {
		this->MPoint = MPoint;
		this->BITMAPID = BITMAPID;
	}
	virtual ~LogicEngine();

	//����Ʈ ��� ����
	void Gate(GateSelect Select);



private:
	
	CString Label;
};

//����Ʈ
class ANDGATE : public LogicEngine {
public :
	ANDGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint,BITMAPID){
	}
};

class ORGATE : public LogicEngine {
public:
	ORGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
	}
};

class NOTGATE : public LogicEngine {
public:
	NOTGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
	}
	void Paint(CClientDC& dc);
	void Rotate(CClientDC &dc, Gdiplus::REAL angle);
};

class NANDGATE : public LogicEngine {
public:
	NANDGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
	}
};

class NORGATE : public LogicEngine {
public:
	NORGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
	}
};
class XORGATE : public LogicEngine {
public:
	XORGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
	}
};




//1��Ʈ��·���
class BITLAMP : public LogicEngine {
public:
	BITLAMP(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
	}
	void Paint(CClientDC& dc);
	//void Rotate(CClientDC &dc, Gdiplus::REAL angle);
};

//7 ���׸�Ʈ
class Seven {
public:
	CPoint point;
	Seven(CPoint &point);
	void Paint(CClientDC &dc, int num);
	void Print_7_segment(CClientDC &dc, bool input_a, bool input_b, bool input_c, bool input_d, bool input_e, bool input_f, bool input_g);

};
