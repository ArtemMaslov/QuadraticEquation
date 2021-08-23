#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <cmath>
#include <assert.h>

#include "..\inc\parse.h"
#include "..\inc\io.h"
//***\\---//***\\-----//***\\---//***\\

Coefficients* ParseString(const char* buffer, Coefficients* params)
{
    assert(buffer);
    assert(params);

    ParseFlags flags = { 0, 0, 0 };

    double     number    = 0;
    ParamType* paramType = nullptr;
    char       paramName = '\0';

    while (*buffer)
    {
        if (isspace(*buffer))//Skip space symbols
        {
            buffer++;
            continue;
        }

        if (*buffer == '=')
        {
            (buffer)++;
            ParseEnding(&buffer);
            return params;
        }

        bool numberParsed = ParseNextNumber(&buffer, &number);
        if (numberParsed == false)
            return nullptr;

        paramType = ParseNextParam(&buffer, &paramName);
        if (paramType == nullptr)
            return nullptr;

        switch (*paramType)
        {
        case X_0:
            if (flags.cInited)
                ParamWarning(*paramType, params->c, number);
            params->c     = number;
            flags.cInited = true;
            break;
        case X_1:
            if (flags.bInited)
                ParamWarning(*paramType, params->b, number);
            params->b     = number;
            flags.bInited = true;
            break;
        case X_2:
            if (flags.aInited)
                ParamWarning(*paramType, params->a, number);
            params->a     = number;
            flags.aInited = true;
            break;
        default:
            return nullptr;
        }

        number = 0;
    }
    SetColor(RED, BLACK);
    puts("Input error. There is no '=' in the input string.\n");
    SetColor(WHITE, BLACK);
    return nullptr;
}

//***\\---//***\\-----//***\\---//***\\

bool ParseEnding(const char** buffer)
{
    assert(buffer);
    assert(*buffer);

    bool warning    = false;

    while (**buffer)
    {
        if (isspace(**buffer))//Skip space symbols
        {
            buffer++;
            continue;
        }

        if (**buffer != '0')
        {
            if (!warning)
            {
                SetColor(RED, BLACK);
                puts("Equation must be entered in the form 'ax^2 + bx + c = 0'."
                    "This symbols were ignored:");
                SetColor(YELLOW, BLACK);
                warning = true;
            }
            putchar(**buffer);
        }

        (*buffer)++;
    }

    if (warning)
    {
        putchar('\n');
        SetColor(WHITE, BLACK);
    }

    return true;
}

//***\\---//***\\-----//***\\---//***\\

ParamType* ParseNextParam(const char** buffer, char* paramName)
{
    assert(buffer);
    assert(*buffer);
    assert(paramName);

    ParamType paramType = X_0;

    while (**buffer)
    {
        if (isspace(**buffer))//Skip space symbols
        {
            (*buffer)++;
            continue;
        }

        if (isalpha(**buffer))
        {
            if (*paramName == '\0')
                *paramName = **buffer;
            if (*paramName != **buffer)
            {
                SetColor(RED, BLACK);
                printf("Enter only single-symbol parameter. Entered parameter '%c' is wrong, use '%c' instead.\n\n", **buffer, * paramName);
                SetColor(WHITE, BLACK);
                return nullptr;
            }
            paramType = X_1;
        }
        else if (**buffer == '^')
        {
            (*buffer)++;
            double power  = 0;
            int    ipower = 0;

            if (ParseNextNumber(buffer, &power) == false)
                power  = 0;
            else
                ipower = (int)power;//Remove fractional part

            if (CompareNumbers((double)ipower, power) == false)
            {
                SetColor(RED, BLACK);
                printf("Enter only decimal numbers for parameter power. Power %lg is wrong.\n\n", power);
                SetColor(WHITE, BLACK);
                return nullptr;
            }

            switch (ipower)
            {
            case 0:
                paramType = X_0;
                break;
            case 1:
                paramType = X_1;
                break;
            case 2:
                paramType = X_2;
                break;
            default:
                SetColor(RED, BLACK);
                printf("Programm can solve only quadratic equations. Power %lg is wrong.\n\n", power);
                SetColor(WHITE, BLACK);
                return nullptr;
            }
            break;
        }
        else if (IsSign(**buffer) || **buffer == '=')
        {
            break;
        }
        else
        {
            SetColor(RED, BLACK);
            printf("Input error. Incorrect symbol '%c'.\n\n", **buffer);
            SetColor(WHITE, BLACK);
            return nullptr;
        }

        (*buffer)++;
    }

    return &paramType;
}

//***\\---//***\\-----//***\\---//***\\

bool ParseNextNumber(const char** buffer, double* number)
{
    assert(buffer);
    assert(*buffer);
    assert(number);

    const char* start         = nullptr;
    const char* end           = nullptr;
    double      sign          = 1.0;
    bool        numberStarted = false;

    while (**buffer)
    {
        if (isspace(**buffer))//Skip space symbols
        {
            (*buffer)++;
            continue;
        }

        if (numberStarted)
        {

            if (isdigit(**buffer))
                ;
            else if (IsSeparator(**buffer))
                ;
            else if (IsSeparator(**buffer) == false && isdigit(**buffer) == false)
            {
                end = *buffer - 1;
                *number = ConvertToDouble(start, end) * sign;
                return true;
            }
            else
            {
                SetColor(RED, BLACK);
                printf("Input error. Incorrect symbol '%c'.\n\n", **buffer);
                SetColor(WHITE, BLACK);
                return false;
            }
        }
        else
        {
            if (isdigit(**buffer))
            {
                start = *buffer;
                numberStarted = true;
            }
            else if (IsSign(**buffer))
            {
                if (**buffer == '-')
                    sign *= -1.0;
            }
            else if (isalpha(**buffer))
            {
                *number = sign;
                return true;
            }
            else
            {
                SetColor(RED, BLACK);
                printf("Input error. Incorrect symbol '%c'.\n\n", **buffer);
                SetColor(WHITE, BLACK);
                return false;
            }
        }

        (*buffer)++;
    }
    return false;
}

//***\\---//***\\-----//***\\---//***\\

double ConvertToDouble(const char* start, const char* end)
{
    assert(start);
    assert(end);

    double number = 0;
    double k      = 1; // coefficient, which equal 10 to power of digitsAfterSeparator.
    bool   separator = false;
    int    digitsAfterSeparator = 0;

    while (start <= end)
    {
        if (isdigit(*start))
        {
            if (separator)
            {
                if (0.1/k < MinCompareValue)
                {
                    char* snumber = (char*)calloc(end - start + 1, sizeof(char));

                    if(snumber)
                        snumber = (char*)memcpy(snumber, start, end - start + 1);
                    if(snumber)
                    {
                        SetColor(RED, BLACK);
                        printf("The number %s entered with too high accuracy, it will be shorten to %lg. It's possible to enter only %d digits after separator.\n\n", 
                            snumber, number / k, digitsAfterSeparator);
                        SetColor(WHITE, BLACK);
                    }
                    else
                    {
                        SetColor(RED, BLACK);
                        printf("The number entered with too high accuracy, it will be shorten to %lg. It's possible to enter only %d digits after separator.\n\n",
                            snumber, number / k, digitsAfterSeparator);
                        SetColor(WHITE, BLACK);
                    }
                    break;
                }

                digitsAfterSeparator++;
                k *= 10;
            }
            number = 10 * number + *start - '0';
        }

        if (IsSeparator(*start))
            separator = true;

        start++;
    }

    return number / k;
}

//***\\---//***\\-----//***\\---//***\\

void ParamWarning(const ParamType paramType, const double oldNumber, const double newNumber)
{
    switch (paramType)
    {
    case X_0:
        SetColor(YELLOW, BLACK);
        printf("Enter only one free member of equation. Old value of free member %lg replaced with new value %lg\n",
            oldNumber, newNumber);
        SetColor(WHITE, BLACK);
        break;
    case X_1:
        SetColor(YELLOW, BLACK);
        printf("Enter only one 'x' member of equation. Old value of 'x' member %lg replaced with new value %lg\n",
            oldNumber, newNumber);
        SetColor(WHITE, BLACK);
        break;
    case X_2:
        SetColor(YELLOW, BLACK);
        printf("Enter only one 'x^2' member of equation. Old value of 'x^2' member %lg replaced with new value %lg\n",
            oldNumber, newNumber);
        SetColor(WHITE, BLACK);
        break;
    }
}

//***\\---//***\\-----//***\\---//***\\

bool IsSeparator(const char c)
{
    return (c == '.' || c == ',');
}

bool CompareNumbers(const double a, const double b)
{
    return (fabs(a - b) < MinCompareValue);
}

bool IsSign(const char c)
{
    return c == '-' || c == '+';
}