/**
* \file
* \brief Test functions file
* \author Maslov Artem
* \version 1.0.0.0
* \date 20 August 2021
*/
#ifndef TEST_H_
#define TEST_H_

#ifdef UNIT_TESTS

#include "config.h"
#include "data_model.h"

const int TestMaxLength = 100;

const size_t TestsCount = 8;

const Coefficients SolveTaskInput[TestsCount] =
{
    {0.0, 0.0, 0.0},
    {1.0, 0.0, 0.0},

    {0.0, 1.0, 0.0},
    {1.0, 1.0, 0.0},

    {0.0, 0.0, 1.0},
    {1.0, 0.0, 1.0},

    {0.0, 1.0, 1.0},
    {-2.0, 1.0, 1.0},
};

const Solution SolveTaskAnswers[TestsCount] =
{
    {0.0,  0.0, INF_SOLUTIONS},
    {0.0,  0.0, NO_SOLUTIONS},

    {0.0,  0.0, ONE_SOLUTION},
    {-1.0, 0.0, ONE_SOLUTION},

    {0.0,  0.0, ONE_SOLUTION},
    {0.0,  0.0, NO_SOLUTIONS},

    {-1.0, 0.0, TWO_SOLUTIONS},
    {1.0, -2.0, TWO_SOLUTIONS},
};

/// \brief Unit test for SolveTask().
void TestSolveTask();

/**
* \brief Function determines wheter roots are equal.
*
* \param[in] r1,r2 Roots of the equation.
* 
* \return true, if roots are equal.
*/
bool CompareRoots(const Solution r1, const Solution r2);

#endif // UNIT_TESTS

#endif // !TEST_H_

