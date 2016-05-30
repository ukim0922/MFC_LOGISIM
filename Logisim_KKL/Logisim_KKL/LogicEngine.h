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
	int Px, Py; //Ŭ�� ��ǥ�� ����


	void Gate(GateSelect Select, bool& input1, bool& input2); // gate ��� ����
	void Gate(GateSelect Select, bool& input1);

	void LOR(bool Input, bool Input2);   // OR����Ʈ ����
	bool Output;


	void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1);	//FF��� ����
	void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1, bool & input2);
	bool Output_Q1;		//�ø��÷ӿ� output ����
	bool Output_Q2;


private:
	
	CString Label;
	
};

