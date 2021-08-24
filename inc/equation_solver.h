/**
* \file
* \brief Equation solver functions file
* \author Maslov Artem
* \version 1.0.0.0
* \date 20 August 2021
*/
#ifndef SOLVE_H_
#define SOLVE_H_

#include "data_model.h"

#define NO_SLN              "No solutions.\n\n"
#define ONE_SLN(ans)        "Equation has one solution: x = %lg\n\n", ans
#define TWO_SLN(ans1, ans2) "Equation has two solutions: x1 = %lg, x2 = %lg\n\n", ans1, ans2
#define INF_SLN             "Equation has an infinit number of solutions.\n\n"

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
* 
* \return A structure with the roots of the equation.
*/
void SolveTask(const Coefficients* params, Solution* solution);

/**
 * \brief Function calculates discriminant of the quadratic equation.
 * 
 * \param[in] a,b,c Coefficients of the quadratic equation.
 * 
 * \return Discriminant of the quadratic equation.
*/
double CalculateDiscriminant(const double a, const double b, const double c);

/**
* \brief The function outputs the roots of the equation.
*
* \param[in] params Coefficients of the quadratic equation.
*/
void PrintSolution(const Solution* params);

int SolveLinearEquation(double a, double b, double* sln);

int SimpleSolveQuadraticEquation(double a, double b, double c, double* sln1, double* sln2);

#endif // !SOLVE_H_
