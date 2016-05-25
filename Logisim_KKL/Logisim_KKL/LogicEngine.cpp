#include "stdafx.h"
#include "LogicEngine.h"


LogicEngine::LogicEngine()
{
}


LogicEngine::~LogicEngine()
{
}

void LogicEngine::gate(GateSelect Select, bool & Input1, bool & Input2)
{
	switch (Select)
	{
	case AND:

		break;
	case OR:
		LOR(Input1,Input2);
		break;
	case NOT:
		break;
	case NAND:
		break;
	case NOR:
		break;
	case XOR:
		break;
	default:
		break;
	}

}

void LogicEngine::LOR(bool Input1, bool Input2)  // OR게이트 함수구현
{
	if ((Input1 == TRUE) || (Input2 == TRUE)) {
		Output = TRUE;
	}
	else
	{
		Output = FALSE;
	}
}

//LogicEngine a;
//a.gate(and, );
