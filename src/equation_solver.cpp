#include <stdio.h>
#include <cmath>
#include <assert.h>


#include "..\inc\io.h"
#include "..\inc\data_model.h"
#include "..\inc\equation_solver.h"
#include "..\inc\utility_functions.h"

void SolveTask(const Coefficients* params, Solution* solution)
{
    assert(params);
    assert(solution);

    solution->SolutionsCount = SimpleSolveQuadraticEquation(params->coeff[2], params->coeff[1], params->coeff[0],
                                                            solution->solutions, solution->solutions+1);
}

int SolveLinearEquation(double a, double b, double* sln)
{
    if (CompareNumbers(a, 0.0) == false)
    {
        *sln = (-b)/(a);
        return ONE_SOLUTION;
    }
    else
    {
        if(CompareNumbers(b, 0.0))
            return INF_SOLUTIONS;
        else
            return NO_SOLUTIONS;
    }
}

int SimpleSolveQuadraticEquation(double a, double b, double c, double* sln1, double* sln2)
{
    if (CompareNumbers(a, 0.0) == false)
    {
        if (CompareNumbers(c, 0.0))
        {
            if (CompareNumbers(b, 0.0))
            {
                *sln1 = 0;
                return ONE_SOLUTION;
            }
            else
            {
                if(b<0)
                {
                    *sln1 = 0;
                    *sln2 = -b;
                }
                else
                {
                    *sln1 = -b;
                    *sln2 = 0;
                }
                return TWO_SOLUTIONS;
            }
        }
        else
        {
            double disc = CalculateDiscriminant(a, b, c);
            if (CompareNumbers(disc, 0.0))
            {
                *sln1 = (-b) / (2 * a);

                if (IsZero(*sln1))
                    *sln1 = 0.0;

                return ONE_SOLUTION;
            }
            else if (disc < 0)
            {
                return 0;
            }
            else
            {
                disc = sqrt(disc);
                *sln1 = (-b + disc) / (2 * a);
                *sln2 = (-b - disc) / (2 * a);

                if (IsZero(*sln1))
                    *sln1 = 0.0;
                if (IsZero(*sln2))
                    *sln2 = 0.0;

                return TWO_SOLUTIONS;
            }
        }
    }
    else
        return SolveLinearEquation(b, c, sln1);
}

double CalculateDiscriminant(const double a, const double b, const double c)
{
    return (b * b) - (4 * a * c);
}

void PrintSolution(const Solution* solution)
{
    assert(solution);

    SetColor(GREEN, BLACK);
    switch (solution->SolutionsCount)
    {
        case NO_SOLUTIONS:
            printf("No solutions.\n\n");
            break;
        case ONE_SOLUTION:
            printf("Equation has one solution: x = %lg\n\n", solution->solutions[0]);
            break;
        case TWO_SOLUTIONS:
            printf("Equation has two solutions: x1 = %lg, x2 = %lg\n\n", solution->solutions[0], solution->solutions[1]);
            break;
        case INF_SOLUTIONS:
            printf("Equation has an infinit number of solutions.\n\n");
            break;
    }
    SetColor(WHITE, BLACK);
}