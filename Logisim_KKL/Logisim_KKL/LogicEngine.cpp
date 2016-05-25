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

//LogicEngine a;
//a.gate(and, );
