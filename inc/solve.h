#ifndef SOLVE_H_
#define SOLVE_H_

#include "main.h"

/**
* \brief Функция решения квадратного уравнения
* 
* Функция получает коэффициенты квадратного уравнения и находит его корни.
* Решений нет: Coefficients.c == NO_SOLUTIONS.
* Один корень: Coefficients.a равно корню уравнения, Coefficients.c == ONE_SOLUTION.
* Два корня: Coefficients.a, Coefficients.b - корни уравнения, Coefficients.c == TWO_SOLUTIONS.
* Бескночено много корней: Coefficients.c == INF_SOLUTIONS
* 
* \param[in] params Коэффициенты квадратного уравнения.
* \return Возвращает структуру с корнями уравнения.
*/
Coefficients SolveTask(const Coefficients* params);

#define NO_SLN              "Корней нет.\n"
#define ONE_SLN(ans)        "Уравнение имеет один корень: x = %lg\n\n", ans
#define TWO_SLN(ans1, ans2) "Уравнение имеет два кореня: x1 = %lg, x2 = %lg\n\n", ans1, ans2
#define INF_SLN             "Уравнение имеет бесконечно много корней.\n"

#endif // !SOLVE_H_
