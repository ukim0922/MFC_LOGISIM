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
	void SmallPaint(CClientDC &dc); //not, input, clock signal, ouputlamp
	//ȸ��
	void Rotate(CClientDC &dc, Gdiplus::REAL angle);
	void SmallRotate(CClientDC &dc, Gdiplus::REAL angle); //not
	
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
	void GateLogic() {};


private:
	
	CString Label;
};

//����Ʈ
class ANDGATE : public LogicEngine {
public :
	ANDGATE() {};
	~ANDGATE() {};
	ANDGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint,BITMAPID){
	}
	void GateLogic();
};

class ORGATE : public LogicEngine {
public:
	ORGATE() {};
	~ORGATE() {};
	ORGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
	}
	void GateLogic();
};

class NOTGATE : public LogicEngine {
public:
	NOTGATE() {};
	~NOTGATE() {};
	NOTGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
	}
	void GateLogic();
};

class NANDGATE : public LogicEngine {
public:
	NANDGATE() {};
	~NANDGATE() {};
	NANDGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
	}
	void GateLogic();
};

class NORGATE : public LogicEngine {
public:
	NORGATE() {};
	~NORGATE() {};
	NORGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
	}
	void GateLogic();
};
class XORGATE : public LogicEngine {
public:
	XORGATE() {};
	~XORGATE() {};
	XORGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
	}
	void GateLogic();
};




//1��Ʈ��·���
class BITLAMP : public LogicEngine {
public:
	BITLAMP() {};
	~BITLAMP() {};
	BITLAMP(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
	}
};

class BITINPUT : public LogicEngine
{
public:
	BITINPUT() {};
	BITINPUT(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {};
	~BITINPUT() {};

private:

};

class CLOCK_SIGNAL :public LogicEngine
{
public:
	CLOCK_SIGNAL() {};
	CLOCK_SIGNAL(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {};
	~CLOCK_SIGNAL() {};


private:

};



//7 ���׸�Ʈ
class Seven {
public:
	CPoint point;
	bool input_a, input_b, input_c, input_d, input_e, input_f, input_g;
	Seven(CPoint &point);
	void Paint(CClientDC &dc, int num);
	void Print_7_segment(CClientDC &dc, bool input_a, bool input_b, bool input_c, bool input_d, bool input_e, bool input_f, bool input_g);
};
