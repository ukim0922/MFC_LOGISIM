#pragma once
enum Facing {
	NORTH, SOUTH, WEST, EAST
};

enum GateSelect {
	AND, OR , NOT, NAND, NOR, XOR
};
class LogicEngine
{
public:
	LogicEngine();
	virtual ~LogicEngine();
	int Px, Py; //Ŭ�� ��ǥ�� ����


	void Gate(GateSelect Select, bool& input1, bool& input2); // gate ��� ����
	void Gate(GateSelect Select, bool& input1);

	bool Output;


private:
	
	CString Label;
	
};

