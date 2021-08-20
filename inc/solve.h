#ifndef SOLVE_H_
#define SOLVE_H_

#include "main.h"

/**
* \brief ������� ������� ����������� ���������
* 
* ������� �������� ������������ ����������� ��������� � ������� ��� �����.
* ������� ���: Coefficients.c == NO_SOLUTIONS.
* ���� ������: Coefficients.a ����� ����� ���������, Coefficients.c == ONE_SOLUTION.
* ��� �����: Coefficients.a, Coefficients.b - ����� ���������, Coefficients.c == TWO_SOLUTIONS.
* ���������� ����� ������: Coefficients.c == INF_SOLUTIONS
* 
* \param[in] params ������������ ����������� ���������.
* \return ���������� ��������� � ������� ���������.
*/
Coefficients SolveTask(const Coefficients* params);

#define NO_SLN              "������ ���.\n"
#define ONE_SLN(ans)        "��������� ����� ���� ������: x = %lg\n\n", ans
#define TWO_SLN(ans1, ans2) "��������� ����� ��� ������: x1 = %lg, x2 = %lg\n\n", ans1, ans2
#define INF_SLN             "��������� ����� ���������� ����� ������.\n"

#endif // !SOLVE_H_
