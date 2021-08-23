#include <stdio.h>
#include <cmath>
#include <assert.h>

#include "..\inc\solve.h"
#include "..\inc\parse.h"

Solution SolveTask(const Coefficients* params)
{
    assert(params);

    Solution result = { 0, 0, NO_SOLUTIONS};

    double a = params->a;
    double b = params->b;
    double c = params->c;

    if (CompareNumbers(a, 0.0) == false)
    {
        double disc = CalculateDiscriminant(a, b, c);

        if (CompareNumbers(disc, 0.0))
        {
            result.x1 = (-b) / (2 * a);

            if (IsZero(result.x1))
                result.x1 = 0.0;

            result.type = ONE_SOLUTION;
        }
        else if (disc < 0)
        {
            result.x1 = NO_SOLUTIONS;
        }
        else
        {
            disc      = sqrt(disc);
            result.x1 = (-b + disc) / (2 * a);
            result.x2 = (-b - disc) / (2 * a);

            if (IsZero(result.x1))
                result.x1 = 0.0;
            if (IsZero(result.x2))
                result.x2 = 0.0;

            result.type = TWO_SOLUTIONS;
        }
    }
    else if (CompareNumbers(b, 0.0) == false)
    {
        result.x1 = (-c) / b;

        if (result.x1 == -0.0)
            result.x1 = 0.0;

        result.type = ONE_SOLUTION;
    }
    else
    {
        if (CompareNumbers(c, 0.0) == true)
            result.type = INF_SOLUTIONS;
        else
            result.type = NO_SOLUTIONS;
    }

    return result;
}

double CalculateDiscriminant(double a, double b, double c)
{
    return (b * b) - (4 * a * c);
}

double IsZero(double number)
{
    return (fabs(number) < MinCompareValue);
}