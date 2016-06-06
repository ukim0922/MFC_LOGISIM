#pragma once
#include "InOutValues.h"
enum Facing {
	NORTH=270, SOUTH=90, WEST=180, EAST=0
};

enum GateSelect {
	AND, OR , NOT, NAND, NOR, XOR, D_FF, JK_FF, T_FF, CLK, BITIN, LAMP
};

//enum FlipFlopSelect {
//	D_FF, JK_FF, T_FF
//};


class LogicEngine
{
public:
	//클릭 좌표값 받음
	CPoint MPoint;
	//비트맵ID 가지고옴
	UINT BITMAPID;
	//방향 설정
	Gdiplus::REAL angle;
	//전체 영역 지정
	CRect MRect;
	//게이트별 정보
	int gatenumber;


	void SetRect();
	//입출력 좌표 지정
	void SetInOutValues(Gdiplus::REAL angle);

	InOutValues input[2];
	InOutValues output[2];


	//출력
	void Paint(CClientDC &dc);
	void SmallPaint(CClientDC &dc); //not, input, clock signal, ouputlamp

	//회전
	void Rotate(CClientDC &dc, Gdiplus::REAL angle);
	void SmallRotate(CClientDC &dc, Gdiplus::REAL angle); //not
	
	//라벨
	void PrintLabel(CClientDC &dc, CString Label);
	void SetLabel(CString Label) { this->Label = Label; }
	CString GetLabel() { return Label; }

	LogicEngine();
	LogicEngine(CPoint MPoint,UINT BITMAPID) {
		this->MPoint = MPoint;
		this->BITMAPID = BITMAPID;
		this->angle = 0;
	}
	virtual ~LogicEngine();

	//게이트 기능 구현
	void GateLogic() {};


	virtual void serialize(CArchive& ar) {
		ar << MPoint << BITMAPID << MPoint << angle << MRect << gatenumber;
	}
	virtual void deserialize(CArchive& ar) {
		ar >> MPoint >> BITMAPID >> MPoint >> angle >> MRect >> gatenumber;
	}
private:
	
	CString Label;
};

//게이트
class ANDGATE : public LogicEngine {
public :
	ANDGATE() {};
	~ANDGATE() {};
	ANDGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
		this->gatenumber = AND;
		SetRect();
		SetInOutValues(0);
	}
	void GateLogic();
};

class ORGATE : public LogicEngine {
public:
	ORGATE() {};
	~ORGATE() {};
	ORGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
		this->gatenumber = OR;
		SetRect();
		SetInOutValues(0);
	}
	void GateLogic();
};

class NOTGATE : public LogicEngine {
public:
	NOTGATE() {};
	~NOTGATE() {};
	NOTGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
		this->gatenumber = NOT;
		SetRect();
		SetInOutValues(0);
	}
	void GateLogic();

};

class NANDGATE : public LogicEngine {
public:
	NANDGATE() {};
	~NANDGATE() {};
	NANDGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
		this->gatenumber = NAND;
		SetRect();
		SetInOutValues(0);
	}
	void GateLogic();

};

class NORGATE : public LogicEngine {
public:
	NORGATE() {};
	~NORGATE() {};
	NORGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
		this->gatenumber = NOR;
		SetRect();
		SetInOutValues(0);
	}
	void GateLogic();

};
class XORGATE : public LogicEngine {
public:
	XORGATE() {};
	~XORGATE() {};
	XORGATE(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
		this->gatenumber = XOR;
		SetRect();
		SetInOutValues(0);
	}
	void GateLogic();

};




//1비트출력램프
class BITLAMP : public LogicEngine {
public:
	BITLAMP() {};
	~BITLAMP() {};
	BITLAMP(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
		this->gatenumber = LAMP;
		SetRect();
		SetInOutValues(0);
	}
};

class BITINPUT : public LogicEngine
{
public:
	BITINPUT() {};
	BITINPUT(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
		this->gatenumber = BITIN;
		SetRect();
		SetInOutValues(0);
	};
	~BITINPUT() {};

private:

};

class CLOCK_SIGNAL :public LogicEngine
{
public:
	bool pre_clk; //이전 클럭값

	CLOCK_SIGNAL() {};
	CLOCK_SIGNAL(CPoint MPoint, UINT BITMAPID) : LogicEngine(MPoint, BITMAPID) {
		this->gatenumber = CLK;
		SetRect();
		SetInOutValues(0);
	};
	~CLOCK_SIGNAL() {};


private:

};



//7 세그먼트
class Seven {
public:
	CPoint point;
	CRect rect[7];
	void Set_7Rect();
	bool input_a=true, input_b = true, input_c = true, input_d = true, input_e = true, input_f = true, input_g = true;
	Seven(CPoint &point);
	void Paint(CClientDC &dc, int num);
	void Print_7_segment(CClientDC &dc);
};

class FilpFlopEngine : public LogicEngine
{
public:
	InOutValues clk;

	//CMainFrame *pFrame_clock_pre = (CMainFrame *)AfxGetMainWnd();
	//CMainFrame *pFrame_clock_cur = (CMainFrame *)AfxGetMainWnd();
	//CMainFrame *pFrame_h_ck = (CMainFrame *)AfxGetMainWnd();


	bool clock_pre /*= pFrame_clock_pre->m_pLogisimView->clock_pre;*/;
	bool clock_cur /*= pFrame_clock_cur->m_pLogisimView->clock_cur;*/;
	bool h_ck /*= pFrame_h_ck->m_pLogisimView->h_ck;*/;

	//CLogisim_KKLView*  m_pLogisimView;
	//CGateTreeView*	   m_pTreeView;

	void SetInOutValues(Gdiplus::REAL angle);
	//플립플롭 기능 구현
	void FlipFlopLogic();

	FilpFlopEngine();
	FilpFlopEngine(CPoint MPoint, UINT BITMAPID) {
		this->MPoint = MPoint;
		this->BITMAPID = BITMAPID;
		this->angle = 0;
	}
	~FilpFlopEngine();
	void Paint(CClientDC & dc);
	void Rotate(CClientDC & dc, Gdiplus::REAL angle);
};


//플립플롭
class DFF : public FilpFlopEngine {
public:
	DFF() {}
	~DFF() {}
	DFF(CPoint MPoint, UINT BITMAPID) : FilpFlopEngine(MPoint, BITMAPID) {
		this->gatenumber = D_FF;
		SetRect();
		SetInOutValues(0);
	}
	void FlipFlopLogic();

};

class TFF : public FilpFlopEngine {
public:
	TFF() {}
	~TFF() {}
	TFF(CPoint MPoint, UINT BITMAPID) : FilpFlopEngine(MPoint, BITMAPID) {
		this->gatenumber = T_FF;
		SetRect();
		SetInOutValues(0);
	}
	void FlipFlopLogic();
};

class JKFF : public FilpFlopEngine {
public:
	JKFF() {}
	~JKFF() {}
	JKFF(CPoint MPoint, UINT BITMAPID) : FilpFlopEngine(MPoint, BITMAPID) {
		this->gatenumber = JK_FF;
		SetRect();
		SetInOutValues(0);
	}
	void FlipFlopLogic();
};