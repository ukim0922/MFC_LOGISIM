#include "stdafx.h"
#include "LogicEngine.h"


LogicEngine::LogicEngine()
{
}


LogicEngine::~LogicEngine()
{
}

void LogicEngine::Gate(GateSelect Select, bool & Input1, bool & Input2)
{
	switch (Select)
	{
	case AND:
		if ((Input1&&Input2) == TRUE) {
			Output = TRUE;
		}
		else {
			Output = FALSE;
		}
		break;
	case OR:
		LOR(Input1, Input2);
		break;
	case NAND:
		if (Input1 && Input2)
			Output = FALSE;
		else
			Output = TRUE;
		break;
	case NOR:
		if (Input1 || Input2)
			Output = FALSE;
		else
			Output = TRUE;
		break;
	case XOR:
		if (Input1 == Input2)
			Output = FALSE;
		else
			Output = TRUE;
		break;
	default:
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate �� ���
		break;
	}

}

//NOT gate ����
void LogicEngine::Gate(GateSelect Select, bool & input1)
{
	switch (Select)
	{
	case NOT:
		if (input1)
			Output = FALSE;
		else
			Output = TRUE;
		break;
	default:
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate �ƴ� ���
		break;
		
	}

}
void LogicEngine::LOR(bool Input1, bool Input2)  // OR����Ʈ �Լ�����
{
	if ((Input1 == TRUE) || (Input2 == TRUE)) {
		Output = TRUE;
	}
	else
	{
		Output = FALSE;
	}
}