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
	CPoint MPoint;			//Ŭ�� ��ǥ�� ����
	UINT BITMAPID;
	bool Output;
	bool Output_Q1 = TRUE;	//�ø��÷ӿ� output ����
	bool Output_Q2 = FALSE;

	void Paint(CClientDC &dc);
	void Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle);
	
	LogicEngine();
	LogicEngine(CPoint MPoint,UINT BITMAPID) {
		this->MPoint = MPoint;
		this->BITMAPID = BITMAPID;
	}
	virtual ~LogicEngine();


	void Gate(GateSelect Select, bool& input1, bool& input2); // gate ��� ����
	void Gate(GateSelect Select, bool& input1);
	//bool Output;


	void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1);	//FF��� ����
	void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1, bool & input2);


private:
	
	CString Label;
};


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


class Seven {
public:
	CPoint point;
	Seven(CPoint &point);
	void Paint(CClientDC &dc, int num);
	void Print_7_segment(CClientDC &dc, bool input_a, bool input_b, bool input_c, bool input_d, bool input_e, bool input_f, bool input_g);

};