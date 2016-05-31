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
	LogicEngine();
	virtual ~LogicEngine();
	int Px, Py; //클릭 좌표값 받음


	void Gate(GateSelect Select, bool& input1, bool& input2); // gate 기능 구현
	void Gate(GateSelect Select, bool& input1);
	bool Output;


	void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1);	//FF기능 구현
	void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1, bool & input2);
	bool Output_Q1 = TRUE;		//플립플롭용 output 변수
	bool Output_Q2 = FALSE;


private:
	
	CString Label;
	
};

