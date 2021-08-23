/**
* \file
* \brief Test functions file
*/
#ifndef TEST_H_
#define TEST_H_

#include "config.h"

const int TestMaxLength = 100;

const size_t TestsCount = 8;

const Coefficients SolveTaskInput[TestsCount] =
{
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 1.0},

    {0.0, 1.0, 0.0},
    {0.0, 1.0, 1.0},

    {1.0, 0.0, 0.0},
    {1.0, 0.0, 1.0},

    {1.0, 1.0, 0.0},
    {1.0, 1.0, -2.0},
};

const Solution SolveTaskAnswers[TestsCount] =
{
    {0.0,  0.0, INF_SOLUTIONS},
    {0.0,  0.0, NO_SOLUTIONS},

    {0.0,  0.0, ONE_SOLUTION},
    {-1.0, 0.0, ONE_SOLUTION},

    {0.0,  0.0, ONE_SOLUTION},
    {0.0,  0.0, NO_SOLUTIONS},

    {0.0, -1.0, TWO_SOLUTIONS},
    {1.0, -2.0, TWO_SOLUTIONS},
};

/// \brief Unit test for SolveTask().
void TestSolveTask();


/**
* \brief Function determines wheter roots are equal.
*
* \param[in] r1, r2 Roots of the equation.
* \return true, if roots are equal.
*/
bool CompareRoots(Solution r1, Solution r2);

/**
* \brief Set color for text and background in console
*
* Full list of colors avaliable in config.h
* 
* \param[in] text Text color
* \param[in] background Background color
*/
void SetColor(int text, int background);

#endif // !TEST_H_

