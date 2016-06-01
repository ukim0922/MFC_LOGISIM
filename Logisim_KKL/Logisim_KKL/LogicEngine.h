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
	//int Px, Py; //클릭 좌표값 받음


	void Gate(GateSelect Select, bool& input1, bool& input2); // gate 기능 구현
	void Gate(GateSelect Select, bool& input1);
	//bool Output;


	void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1);	//FF기능 구현
	void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1, bool & input2);
	//bool Output_Q1 = TRUE;		//플립플롭용 output 변수
	//bool Output_Q2 = FALSE;


private:
	
	CString Label;
};

//게이트
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


//플립플롭
class TFF {
public:
	CPoint point;
	TFF(CPoint &point);
	void Paint(CClientDC &dc);
	void Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle);
};


//1비트출력램프
class BITLAMP {
public:
	CPoint point;
	BITLAMP(CPoint &point);
	void Paint(CClientDC &dc);
	void Rotate(CClientDC &dc, CPoint &point, Gdiplus::REAL angle);
};