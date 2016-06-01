#pragma once
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
	CPoint MPoint;
	UINT BITMAPID;
	bool Output;
	bool Output_Q1 = TRUE;
	bool Output_Q2 = FALSE;

	void Paint(CClientDC &dc);
	void Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle);
	LogicEngine();
	LogicEngine(CPoint MPoint,UINT BITMAPID) {
		this->MPoint = MPoint;
		this->BITMAPID = BITMAPID;
	}
	virtual ~LogicEngine();
	//int Px, Py; //Ŭ�� ��ǥ�� ����


	void Gate(GateSelect Select, bool& input1, bool& input2); // gate ��� ����
	void Gate(GateSelect Select, bool& input1);
	//bool Output;


	void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1);	//FF��� ����
	void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1, bool & input2);
	//bool Output_Q1 = TRUE;		//�ø��÷ӿ� output ����
	//bool Output_Q2 = FALSE;


private:
	
	CString Label;
};

//����Ʈ
//class ANDGATE {
//public:
//	CPoint point;
//	ANDGATE(CPoint &point);
//	void Paint(CClientDC &dc);
//	void Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle);
//};

class ANDGATE : public LogicEngine {
//	ANDGATE();
//	ANDGATE(CPoint MPoint);
//	~ANDGATE();

};

class ORGATE {
public:
	CPoint point;
	ORGATE(CPoint &point);
	void Paint(CClientDC &dc);
	void Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle);
};
class XORGATE {
public:
	CPoint point;
	XORGATE(CPoint &point);
	void Paint(CClientDC &dc);
	void Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle);
};
class NANDGATE {
public:
	CPoint point;
	NANDGATE(CPoint &point);
	void Paint(CClientDC &dc);
	void Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle);
};
class NORGATE {
public:
	CPoint point;
	NORGATE(CPoint &point);
	void Paint(CClientDC &dc);
	void Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle);
};
class NOTGATE {
public:
	CPoint point;
	NOTGATE(CPoint &point);
	void Paint(CClientDC &dc);
	void Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle);
};


//�ø��÷�
class TFF {
public:
	CPoint point;
	TFF(CPoint &point);
	void Paint(CClientDC &dc);
	void Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle);
};


//1��Ʈ��·���
class BITLAMP {
public:
	CPoint point;
	BITLAMP(CPoint &point);
	void Paint(CClientDC &dc);
	void Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle);
};