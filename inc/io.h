/**
* \file
* \brief Input, output functions file
*/
#ifndef IO_H_
#define IO_H_

#include "config.h"

/**
* \brief Input reading function.
*
* The function reads the following line from the input buffer.
* \param[out] buffer Input line.
* \param[in]  length Maximum line length (buffer size).
* \param[in]  stream Input stream.
*/
char* GetString(char* buffer, int length, FILE* stream);


/**
* \brief The function outputs the roots of the equation.
*
* \param[in] params Coefficients of the quadratic equation.
*/
void PrintSolution(Solution* params);

#endif // !PARESE_H_
