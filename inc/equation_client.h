/**
* \file
* \brief Equation client file
* \author Maslov Artem
* \version 1.0.0.0
* \date 20 August 2021
*
* QuadraticEquation is the programm, which solves quadratic equations :)
*
* Input rules:
* Entered numbers could contain only 6 digit after separator, else the programm prints warning.
* To increase digits after separator change `MinCompareValue` constant in `config.h`.
* The dot '.' and comma ',' could be the decimal separator.
* Multiplication '*' and division '/' symbols are not allowed in the input string.
* Input `2*x-1=0` is not correct, but `2x-1=0` is correct.
* Each coefficient of quadratic equation can occur only once,
* otherwise the last one will be use in the calculatios.
* For example, in the input `2x^2-3x+10x-13=0` member `-3x` will be ignored and this input qual to `2x^2+10x-13=0`.
*/
#ifndef EQUATION_CLIENT_H_
#define EQUATION_CLIENT_H_

/**
* \brief Client function
*
* This function suggests the user to enter quadratic eqution and solves it.
*/
void EquationClient();

#endif // !EQUATION_CLIENT_H_

