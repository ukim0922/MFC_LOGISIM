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


	void gate(GateSelect Select, bool& input1, bool& input2); // gate ��� ����

	/*bool GetOutput() {
		return Output;
	}*/
	bool Output;
	//bool Set

private:
	
	CString Label;
	
};

