/**
* \file
* \brief Equation client file
* \author Maslov Artem
* \version 1.0.0.0
* \date 20 August 2021
*
* QuadraticEquation is the program, which solves quadratic equations :)
*
* Input rules:
* Entered numbers could contain only 6 digit after separator, else the program prints warning.
* To increase digits after separator change `MinCompareValue` constant in `config.h`.
* The dot '.' and comma ',' could be the decimal separator.
* Multiplication '*' and division '/' symbols are not allowed in the input string.
* Input `2*x-1=0` is not correct, but `2x-1=0` is correct.
* Each coefficient of quadratic equation can occur only once,
* otherwise the last one will be use in the calculatios.
* For example, in the input `2x^2-3x+10x-13=0` member `-3x` will be ignored and this input qual to `2x^2+10x-13=0`.
*/

#include <Windows.h>
#include <stdio.h>

#include "..\inc\config.h"
#include "..\inc\string_parser.h"
#include "..\inc\equation_solver.h"
#include "..\inc\io.h"

#ifdef UNIT_TESTS

#include "..\inc\test.h"

#endif // UNIT_TESTS

int main(void)
{
    #ifdef UNIT_TESTS
    
    TestSolveTask();

    #else

    SetColor(YELLOW, BLACK);

    puts("Input rules:\n\n"
        "* The equation must be entered if the form 'ax^2 + bx + c = 0'.\n\n"
        "* Entered numbers could contain only 6 digit after separator, else the program prints warning."
        " To increase digits after separator change Epsilon constant.\n\n"
        "* The dot '.'and comma ',' could be the decimal separator.\n\n"
        "* Multiplication '*' and division '/' symbols are not allowed in the input string."
        "Input '2*x - 1 = 0' is not correct, but '2x-1 = 0' is correct.\n\n"
        "* Each coefficient of quadratic equation can occur only once, otherwise the last one will be use in the calculatios."
        " For example, in the input '2x^2 - 3x + 10x - 13 = 0' member '-3x' will be ignored and this input qual to '2x^2 + 10x - 13 = 0'.\n\n");

    SetColor(WHITE, BLACK);

    puts("Enter quadratic equation in the form 'ax^2 + bx + c = 0'. Empty line to exit program:");

    char          buffer[MaxLength] = { 0 };
    Coefficients  params = { 0 };

    while (GetString(buffer, MaxLength, stdin))
    {
        if (ParseString(buffer, &params))
        {
            Solution roots = {{0}, 0};
            SolveTask(&params, &roots);
            PrintSolution(&roots);
        }
        
        params = { 0 };
        puts("Enter next quadratic equation in the form 'ax^2 + bx + c = 0'. Empty line to exit program:");
    }

    #endif // UNIT_TESTS
    return 0;
}
