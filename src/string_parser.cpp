#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <cmath>
#include <assert.h>

#include "..\inc\data_model.h"
#include "..\inc\io.h"
#include "..\inc\utility_functions.h"

static bool ParseEnding(const char** buffer);
static int ParseNextParam(const char** buffer, char* paramName);
static bool ParseNextNumber(const char** buffer, double* number);
static double ConvertToDouble(const char* start, const char* end);
static void ParamWarning(int paramType, double oldNumber, double newNumber);
static bool IsSeparator(const char c);
static bool IsSign(const char c);

//***\\---//***\\-----//***\\---//***\\

/*
* Examples of correct input:
*   x^2-2x+3=0
*   x^2-4=0
*   543x-12x^2+812=0
*   9341-12x=0
*/

bool ParseString(const char* buffer, Coefficients* params)
{
    assert(buffer);
    assert(params);

    bool flags[MaxCoefficientsCount] = { false };

    double number = 0;
    int paramType = 0;
    char paramName = '\0';

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
            return ParseEnding(&buffer);
        }

        bool numberParsed = ParseNextNumber(&buffer, &number);
        if (numberParsed == false)
            return false;

        paramType = ParseNextParam(&buffer, &paramName);
        if(paramType < 0)
            return false;

        if(flags[paramType])
            ParamWarning(paramType, params->coeff[paramType], number);
        params->coeff[paramType] = number;
        flags[paramType] = true;

        number = 0;
    }
    SetColor(RED, BLACK);
    puts("Input error. There is no '=' in the input string.\n");
    SetColor(WHITE, BLACK);
    return false;
}

//***\\---//***\\-----//***\\---//***\\

/**
* \brief Function for processing the end of a line.
*
* The function processes characters after the '=' sign. Issues a warning if the input does not end with "=0".
*
* \param[in] buffer Input string.
*
* \return false in case of an error, true in case of correct exit.
*/
static bool ParseEnding(const char** buffer)
{
    assert(buffer);
    assert(*buffer);

    bool warning = false;

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

/**
* \brief The function searches a next parameter in the string.
*
* The function searches in the line the first parameter from the left and
* sets the buffer pointer to the next symbol in the line.
*
* \param[in] paramName Parameter symbol (a, b, x, ...), met before in the line. '\0' if the function is called for the first time.
* \param[in] buffer Input string.
*
* \return Degree of parameter, -1 in case of an error.
*/
static int ParseNextParam(const char** buffer, char* paramName)
{
    assert(buffer);
    assert(*buffer);
    assert(paramName);

    int paramType = 0;

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
                return -1;
            }
            paramType = 1;
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
                return -1;
            }

            if (0 <= ipower && ipower <= 2)
            {
                return ipower;
            }
            else
            {
                SetColor(RED, BLACK);
                printf("Program can solve only quadratic equations. Power %lg is wrong.\n\n", power);
                SetColor(WHITE, BLACK);
                return -1;
            }
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
            return -1;
        }

        (*buffer)++;
    }

    return paramType;
}

//***\\---//***\\-----//***\\---//***\\

/**
* \brief The function searches a next number in the string.
*
* The function searches in the string the first number from the left and
* sets the buffer pointer to the next symbol in the string.
*
* \param[in]  buffer Input string.
* \param[out] number Pointer to a number in the string.
*
* \return false in case of an error, true in case of correct exit.
*/
static bool ParseNextNumber(const char** buffer, double* number)
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

/**
* \brief Function for converting a string of digits to double.
*
* The function converts a string of digits to a double.
*
* \param[in] start Pointer to the first character of the number.
* \param[in] end   Pointer to the last character of the number.
*
* \return The received number.
*/
static double ConvertToDouble(const char* start, const char* end)
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
                             number / k, digitsAfterSeparator);
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

/**
* \brief Function displays a warning about the double use of parameters.
*
* The function displays a warning that two parameters have been entered.
* For example, in input `2x+10x-1=0` function will output that the value `2x` will be ignored.
*
* \param[in] paramType Parameter type (x^2, x or free member).
* \param[in] oldNumber The old value of the parameter.
* \param[in] newNumber The new value of the parameter.
*/
static void ParamWarning(int paramType, double oldNumber, double newNumber)
{
    switch (paramType)
    {
    case 0:
        SetColor(YELLOW, BLACK);
        printf("Enter only one free member of equation. Old value of free member %lg replaced with new value %lg\n",
            oldNumber, newNumber);
        SetColor(WHITE, BLACK);
        break;
    case 1:
        SetColor(YELLOW, BLACK);
        printf("Enter only one 'x' member of equation. Old value of 'x' member %lg replaced with new value %lg\n",
            oldNumber, newNumber);
        SetColor(WHITE, BLACK);
        break;
    default:
        SetColor(YELLOW, BLACK);
        printf("Enter only one 'x^%d' member of equation. Old value of 'x^%d' member %lg replaced with new value %lg\n",
            paramType, paramType, oldNumber, newNumber);
        SetColor(WHITE, BLACK);
        break;
    }
}


/**
* \brief Function that determines wheter a character is a separator.
*
* \param[in] c The checked character.
*
* \return true, if the character is a dot or comma.
*/
static bool IsSeparator(const char c)
{
    return (c == '.' || c == ',');
}


/**
* \brief Function that determines wheter the character is '+' or '-'.
*
* \param[in] c The checked character.
*
* \return true, if the character is '+' or '-'.
*/
static bool IsSign(const char c)
{
    return c == '-' || c == '+';
}