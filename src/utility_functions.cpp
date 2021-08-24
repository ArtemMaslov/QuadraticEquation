#include <cmath>

#include "..\inc\config.h"

bool CompareNumbers(const double a, const double b)
{
    return (fabs(a - b) < MinCompareValue);
}

double IsZero(const double number)
{
    return (fabs(number) < MinCompareValue);
}