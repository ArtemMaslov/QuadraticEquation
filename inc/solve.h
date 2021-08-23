/**
* \file
* \brief Solver functions file
*/
#ifndef SOLVE_H_
#define SOLVE_H_

#include "config.h"

#define NO_SLN              "Корней нет.\n"
#define ONE_SLN(ans)        "Уравнение имеет один корень: x = %lg\n\n", ans
#define TWO_SLN(ans1, ans2) "Уравнение имеет два кореня: x1 = %lg, x2 = %lg\n\n", ans1, ans2
#define INF_SLN             "Уравнение имеет бесконечно много корней.\n"

/**
* \brief Function solves the quadratic equation.
* 
* The function gets coefficients of a quadratic equation and finds it's roots.
* There are no  solutions:  Coefficients.c == NO_SOLUTIONS.
* There is  one solution:   Coefficients.a equal to the root of the quation, Coefficients.c == ONE_SOLUTION.
* There are two solutions:  Coefficients.a, Coefficients.b - the roots of the equation, Coefficients.c == TWO_SOLUTIONS.
* There are infinit number of solution: Coefficients.c == INF_SOLUTIONS
* 
* \param[in] params Coefficients of the quadratic equation.
* \return A structure with the roots of the equation.
*/
Solution SolveTask(const Coefficients* params);

/**
 * \brief Function calculates discriminant of the quadratic equation.
 * \param a,b,c Coefficients of the quadratic equation.
 * \return Discriminant of the quadratic equation.
*/
double CalculateDiscriminant(double a, double b, double c);


/**
* \brief Function determines wheter the number is zero.
*
* \return true if number is zero.
*/
double IsZero(double number);

#endif // !SOLVE_H_
