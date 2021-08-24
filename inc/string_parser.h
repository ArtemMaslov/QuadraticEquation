/**
* \file
* \brief Parser functions file
* \author Maslov Artem
* \version 1.0.0.0
* \date 20 August 2021
*/
#ifndef STRING_PARSER_H_
#define STRING_PARSER_H_

#include "config.h"
#include "data_model.h"

/**
* \brief String parsing function.
*
* The function anlyzes the string and calculates the coefficients. The equation should be written as ax^2+bx+c=0.
* Examples of correct input:
*   x^2-2x+3=0
*   x^2-4=0
*   543x-12x^2+812=0
*   9341-12x=0
* 
* \warning Function will notify user if input was incorrect.
* 
* \param[in]  buffer Input string.
* \param[out] params Pointer to the structure of the coefficients of a quadratic equation.
* 
* \return false in case of an error.
*/
bool ParseString(const char* buffer, Coefficients* params);

#endif // !PARSE_H_
