#include "stdafx.h"
#include "LogicEngine.h"

bool clock_pre = TRUE; //클럭변수
bool clock_cur = TRUE;
bool h_ck = TRUE; //에지트리거방식 (상승이면true, 하강이면false) 클릭으로받아올예정

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
		if ((Input1 == TRUE) || (Input2 == TRUE)) {
			Output = TRUE;
		}
		else
		{
			Output = FALSE;
		}
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
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate 인 경우
		break;
	}

}

//NOT gate 구현
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
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate 아닌 경우
		break;
		
	}

}

void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1) {		//d, t플립플롭
	switch(Select)
	{
	case T_FF:
		if (input1) {

			if (h_ck == TRUE) //상승 에지트리거
			{
				if (clock_pre == TRUE && clock_cur == FALSE)
				{
					bool temp;
					temp = Output_Q1;
					Output_Q1 = Output_Q2;
					Output_Q2 = temp;
				}
			}
			else //하강 에지트리거
			{
				if (clock_pre == FALSE && clock_cur == TRUE)
				{
					bool temp;
					temp = Output_Q1;
					Output_Q1 = Output_Q2;
					Output_Q2 = temp;
				}
			}
		}
		else {
			//변함이 없음.
		}
		break;

	case D_FF: //입력 그대로 출력
		if (h_ck == TRUE) //상승 에지트리거
		{
			if (clock_pre == TRUE && clock_cur == FALSE)
			{
				Output_Q1 = input1;
			}
		}
		else //하강 에지트리거
		{
			if (clock_pre == FALSE && clock_cur == TRUE)
			{
				Output_Q1 = input1;
			}
		}
		break;
	default:
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate 아닌 경우
		break;

	}
}

void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1, bool & input2) {		//jk플립플롭

}

