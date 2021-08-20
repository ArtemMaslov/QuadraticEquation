#ifndef SOLVE_H_
#define SOLVE_H_

#include "main.h"

/**
* \brief ������� ������� ����������� ���������
* 
* ������� �������� ������������ ����������� ���������, ������� ��� ����� � ������� ��������� ������������.
* 
* \param[in] params ������������ ����������� ���������.
*/
void SolveTask(const Coefficients* params);

#define NO_SLN              "������ ���.\n"
#define ONE_SLN(ans)        "��������� ����� ���� ������: x = %lg\n\n", ans
#define TWO_SLN(ans1, ans2) "��������� ����� ��� ������: x1 = %lg, x2 = %lg\n\n", ans1, ans2
#define INF_SLN             "��������� ����� ���������� ����� ������.\n"

#endif // !PARESE_H_
