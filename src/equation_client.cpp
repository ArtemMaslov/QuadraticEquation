#include <stdio.h>

#include "..\inc\parse.h"
#include "..\inc\io.h"
#include "..\inc\solve.h"

void EquationClient()
{
    char   buffer[MaxLength];
    Coefficients  params = { 0,0,0 };
    Coefficients* pparams = &params;

    puts("Программа решает квадратные уравнения. Пример ввода:"
        "\n\t10x^2-20x+30=0."
        "\nКаждый член нужно вводить один раз. Следующий ввод является ошибочным:"
        "\n\tx^2+2x^2-x+3=0."
        "\n\nВведите квадратное уравнение в привидённом виде (ax^2+bx+c=0). Пустая строка для завершения:");

    while (GetString(buffer, MaxLength, stdin))
    {
        params = { 0,0,0 };
        pparams = ParseString(buffer, &params);

        if (pparams)
        {
            Coefficients roots = SolveTask(pparams);
            PrintSolution(&roots);
        }

        puts("Введите следующее квадратное уравнение в привидённом виде (ax^2+bx+c=0). Пустая строка для завершения:");
    }
}