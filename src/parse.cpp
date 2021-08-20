#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <cmath>

#include "..\inc\parse.h"
//***\\---//***\\-----//***\\---//***\\

Coefficients* ParseString(const char* buffer, Coefficients* params)
{
    ParseFlags flags = { 0,0,0 };

    double     number    = 0;
    ParamType* paramType = nullptr;
    char       paramName = '\0';

    while (*buffer)
    {
        if (isspace(*buffer))//Пропускаем пробельные символы
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
    puts("Ошибка ввода. В введённой строке не было знака '='\n");
    return nullptr;
}

//***\\---//***\\-----//***\\---//***\\

bool ParseEnding(const char** buffer)
{
    bool warning    = false;
    bool zeroInText = false;

    while (**buffer)
    {
        if (isspace(**buffer))//Пропускаем пробельные символы
        {
            buffer++;
            continue;
        }

        if (**buffer != '0')
        {
            if (!warning)
            {
                puts("Квадратное уравнение должно быть записано в приведенном виде только в левой части от знака '='. Справа от '=' должен стоять 0. Следующие сиволы были проигнорированы:");
                warning = true;
            }
            putchar(**buffer);
        }
        else
            zeroInText = true;

        (*buffer)++;
    }

    if (warning)
        putchar('\n');
    else if (!zeroInText)
        puts("Справа от '=' должен стоять 0.");

    return true;
}

//***\\---//***\\-----//***\\---//***\\

ParamType* ParseNextParam(const char** buffer, char* paramName)
{
    ParamType paramType = X_0;

    while (**buffer)
    {
        if (isspace(**buffer))//Пропускаем пробельные символы
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
                printf("Вводите только один параметр, состоящий из одного символа латинского алфавита. Введены параметры '%c', '%c'.\n\n", *paramName, **buffer);
                return nullptr;
            }
            paramType = X_1;
        }
        else if (**buffer == '^')
        {
            (*buffer)++;
            double power = 0;
            int ipower   = 0;

            if (ParseNextNumber(buffer, &power) == false)
                power  = 0;
            else
                ipower = (int)power;//Обнуляем дробную часть

            if (CompareNumbers((double)ipower, power) == false)
            {
                printf("Вводите только целые степени параметров. Степень %lg является ошибочной.\n\n", power);
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
                printf("Программа умеет решать только квадратные уравнения. Степень %d является ошибочной.\n\n", ipower);
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
            printf("Ошибка ввода. Символ '%c' встречается не в том месте.\n\n", **buffer);
            return nullptr;
        }

        (*buffer)++;
    }

    return &paramType;
}

//***\\---//***\\-----//***\\---//***\\

bool ParseNextNumber(const char** buffer, double* number)
{
    const char* start         = nullptr;
    const char* end           = nullptr;
    double      sign          = 1.0;
    bool        numberStarted = false;

    while (**buffer)
    {
        if (isspace(**buffer))//Пропускаем пробельные символы
        {
            (*buffer)++;
            continue;
        }

        if (isdigit(**buffer) && !numberStarted)
        {
            start         = *buffer;
            numberStarted = true;
        }
        else if (isdigit(**buffer) == false && numberStarted)
        {
            end     = *buffer - 1;
            *number = ConvertToDouble(start, end) * sign;
            return true;
        }
        else if (IsSign(**buffer) && !numberStarted)
        {
            if (**buffer == '-')
                sign *= -1.0;
        }
        else if (isalpha(**buffer) && !numberStarted)
        {
            *number = 1.0;
            return true;
        }
        else if (isdigit(**buffer) == false)
        {
            printf("Ошибка ввода. Символ '%c' встречается не в том месте.\n\n", **buffer);
            return false;
        }

        (*buffer)++;
    }
    return false;
}

//***\\---//***\\-----//***\\---//***\\

double ConvertToDouble(const char* start, const char* end)
{
    double number                = 0;
    double numbersAfterSeparator = 1;
    bool   separator             = false;

    while (start <= end)
    {
        if (isdigit(*start))
        {
            if (separator)
                numbersAfterSeparator *= 10;
            number = 10 * number + *start - '0';
        }

        if (IsSeparator(*start))
            separator = true;

        start++;
    }

    return number / numbersAfterSeparator;
}

//***\\---//***\\-----//***\\---//***\\

void ParamWarning(ParamType paramType, double oldNumber, double newNumber)
{
    switch (paramType)
    {
    case X_0:
        printf("Вводите только один свободный член уравнения. Старое значение %lg было заменено на новое %lg\n", oldNumber, newNumber);
        break;
    case X_1:
        printf("Вводите x^1 только один раз. Старое значение %lg было заменено на новое %lg\n", oldNumber, newNumber);
        break;
    case X_2:
        printf("Вводите x^2 только один раз. Старое значение %lg было заменено на новое %lg\n", oldNumber, newNumber);
        break;
    }
}

//***\\---//***\\-----//***\\---//***\\

bool IsSeparator(char c)
{
    return (c == '.' || c == ',');
}

bool CompareNumbers(double a, double b)
{
    return (abs(a - b) <= 1.e-6);
}

bool IsSign(char c)
{
    return c == '-' || c == '+';// || c == '*' || c == '/'
}