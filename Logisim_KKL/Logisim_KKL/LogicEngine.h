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
	int Px, Py; //클릭 좌표값 받음


	void gate(GateSelect Select, bool& input1, bool& input2); // gate 기능 구현

	/*bool GetOutput() {
		return Output;
	}*/
	bool Output;
	//bool Set

private:
	
	CString Label;
	
};

