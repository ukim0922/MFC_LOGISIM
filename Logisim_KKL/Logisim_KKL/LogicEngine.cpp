#include "stdafx.h"
#include "LogicEngine.h"

bool clock_pre = TRUE; //Ŭ������
bool clock_cur = TRUE;
bool h_ck = TRUE; //����Ʈ���Ź�� (����̸�true, �ϰ��̸�false) Ŭ�����ι޾ƿÿ���

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

void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1) {		//d, t�ø��÷�
	switch(Select)
	{
	case T_FF:
		if (input1) {

			if (h_ck == TRUE) //��� ����Ʈ����
			{
				if (clock_pre == TRUE && clock_cur == FALSE)
				{
					bool temp;
					temp = Output_Q1;
					Output_Q1 = Output_Q2;
					Output_Q2 = temp;
				}
			}
			else //�ϰ� ����Ʈ����
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
			//������ ����.
		}
		break;

	case D_FF: //�Է� �״�� ���
		if (h_ck == TRUE) //��� ����Ʈ����
		{
			if (clock_pre == TRUE && clock_cur == FALSE)
			{
				Output_Q1 = input1;
			}
		}
		else //�ϰ� ����Ʈ����
		{
			if (clock_pre == FALSE && clock_cur == TRUE)
			{
				Output_Q1 = input1;
			}
		}
		break;
	default:
		AfxMessageBox(_T("Overloding ERROR"), MB_OKCANCEL); //NOT gate �ƴ� ���
		break;

	}
}

void LogicEngine::FlipFlop(FlipFlopSelect Select, bool & input1, bool & input2) {		//jk�ø��÷�

}

