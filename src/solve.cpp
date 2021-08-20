#include <stdio.h>
#include <cmath>
#include <assert.h>

#include "..\inc\solve.h"
#include "..\inc\parse.h"

Coefficients SolveTask(const Coefficients* params)
{
    assert(params);

    Coefficients result = { 0,0,0 };

    if (CompareNumbers(params->a, 0.0) == false)
    {
        double D = (params->b * params->b) - (4 * params->a * params->c);

        if (D < 0)
        {
            result.c = NO_SOLUTIONS;
        }
        else if (CompareNumbers(D, 0.0))
        {
            result.a = (-params->b) / (2 * params->a);

            if (result.a == -0.0)
                result.a = 0.0;

            result.c = ONE_SOLUTION;
        }
        else
        {
            D  = sqrt(D);
            result.a = (-params->b + D) / (2 * params->a);
            result.b = (-params->b - D) / (2 * params->a);

            if (result.a == -0.0)
                result.a = 0.0;
            if (result.b == -0.0)
                result.b = 0.0;

            result.c = TWO_SOLUTIONS;
        }
    }
    else if (CompareNumbers(params->b, 0.0) == false)
    {
        result.a = (-params->c) / params->b;

        if (result.a == -0.0)
            result.a = 0.0;

        result.c = ONE_SOLUTION;
    }
    else
    {
        if (CompareNumbers(params->c, 0.0) == true)
            result.c = INF_SOLUTIONS;
        else
            result.c = NO_SOLUTIONS;
    }

    return result;
}
