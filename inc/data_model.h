/**
* \file
* \brief Data model file
* \author Maslov Artem
* \version 1.0.0.0
* \date 20 August 2021
*/
#ifndef DATA_MODEL_H_
#define DATA_MODEL_H_

#include "config.h"

/// \brief Coefficients of the quadratic equation ax^2+bx+c.
struct Coefficients
{
    double coeff[MaxCoefficientsCount];
};

/// Solution type (no solutions, one solution, two solutions, an infinit number of solutions).
enum SolutionType
{
    INF_SOLUTIONS = -1, ///< An infinit number of solutions.
    NO_SOLUTIONS = 0, ///< No solutions.
    ONE_SOLUTION = 1, ///< One solution.
    TWO_SOLUTIONS = 2 ///< Two solutions.
};

/// Solution structure
struct Solution
{
    double solutions[MaxCoefficientsCount - 1];
    int SolutionsCount; ///< Solution type
};

#endif // !DATA_MODEL_H_
