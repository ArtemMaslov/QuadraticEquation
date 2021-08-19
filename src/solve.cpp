#include <stdio.h>
#include <cmath>

#include "..\inc\solve.h"

void SolveTask(const Coefficients* params)
{
    double x1 = 0;
    double x2 = 0;

    if (params->a != 0)
    {
        double D = (params->b * params->b) - (4 * params->a * params->c);

        if (D < 0)
        {
            puts("Корней нет.\n");
        }
        else if (D == 0)
        {
            x1 = (-params->b) / (2 * params->a);
            printf("Уравнение имеет один корень: x = %.6f\n\n", x1);
        }
        else
        {
            D  = sqrt(D);
            x1 = (-params->b + D) / (2 * params->a);
            x2 = (-params->b - D) / (2 * params->a);
            printf("Уравнение имеет два кореня: x1 = %.6f, x2 = %.6f\n\n", x1, x2);
        }
    }
    else if (params->b != 0)
    {
        x1 = (-params->c) / params->b;
        printf("Уравнение имеет один корень: x = %.6f\n\n", x1);
    }
    else
    {
        if (params->c == 0)
            puts("Уравнение имеет бесконечно много корней.\n");
        else
            puts("Корней нет.\n");
    }
}
