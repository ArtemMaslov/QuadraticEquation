#include <stdio.h>

#include "..\inc\parse.h"
#include "..\inc\io.h"
#include "..\inc\solve.h"

void EquationClient()
{

    char          buffer[MaxLength] = { 0 };
    Coefficients  params  = { 0, 0, 0 };
    Coefficients* pparams = &params;

    SetColor(YELLOW, BLACK);

    puts("Input rules:\n\n"
        "* The equation must be entered if the form 'ax^2 + bx + c = 0'.\n\n"
        "* Entered numbers could contain only 6 digit after separator, else the programm prints warning."
        " To increase digits after separator change Epsilon constant.\n\n"
        "* The dot '.'and comma ',' could be the decimal separator.\n\n"
        "* Multiplication '*' and division '/' symbols are not allowed in the input string."
        "Input '2*x - 1 = 0' is not correct, but '2x-1 = 0' is correct.\n\n"
        "* Each coefficient of quadratic equation can occur only once, otherwise the last one will be use in the calculatios."
        " For example, in the input '2x^2 - 3x + 10x - 13 = 0' member '-3x' will be ignored and this input qual to '2x^2 + 10x - 13 = 0'.\n\n" );

    SetColor(WHITE, BLACK);

    puts("Enter quadratic equation in the form 'ax^2 + bx + c = 0'. Empty line to exit programm:");

    while (GetString(buffer, MaxLength, stdin))
    {
        params = { 0, 0, 0 };
        pparams = ParseString(buffer, &params);

        if (pparams)
        {
            Solution roots = SolveTask(pparams);
            PrintSolution(&roots);
        }

        puts("Enter next quadratic equation in the form 'ax^2 + bx + c = 0'. Empty line to exit programm:");
    }
}