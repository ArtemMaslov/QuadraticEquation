#include <stdio.h>
#include <cmath>
#include <assert.h>

#include "..\inc\solve.h"

void SolveTask(const Coefficients* params)
{
    assert(params);

    double x1 = 0;
    double x2 = 0;

    if (params->a != 0)
    {
        double D = (params->b * params->b) - (4 * params->a * params->c);

        if (D < 0)
        {
            puts(NO_SLN);
        }
        else if (D == 0)
        {
            x1 = (-params->b) / (2 * params->a);

            if (x1 == -0.0)
                x1 = 0.0;

            printf( ONE_SLN(x1) );
        }
        else
        {
            D  = sqrt(D);
            x1 = (-params->b + D) / (2 * params->a);
            x2 = (-params->b - D) / (2 * params->a);

            if (x1 == -0.0)
                x1 = 0.0;
            if (x2 == -0.0)
                x2 = 0.0;

            printf( TWO_SLN(x1, x2) );
        }
    }
    else if (params->b != 0)
    {
        x1 = (-params->c) / params->b;

        if (x1 == -0.0)
            x1 = 0.0;

        printf( ONE_SLN(x1) );
    }
    else
    {
        if (params->c == 0)
            puts(INF_SLN);
        else
            puts(NO_SLN);
    }
}
