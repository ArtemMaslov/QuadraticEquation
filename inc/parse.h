/**
* \file
* \brief Parser functions file
* \author Maslov Artem
* \version 1.0.0.0
* \date 20 August 2021
*/
#ifndef PARSE_H_
#define PARSE_H_

#include "config.h"

/**
* \brief String parsing function.
*
* The function anlyzes the string and calculates the coefficients. The equation should be written as ax^2+bx+c=0.
* 
* \warning Function will notify user if input was incorrect.
* 
* \param[in]  buffer Input string.
* \param[out] params Pointer to the structure of the coefficients of a quadratic equation.
* 
* \return Pointer to the structer. `nullptr` in case of an error.
*/
Coefficients* ParseString(const char* buffer, Coefficients* params);

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
bool ParseNextNumber(const char** buffer, double* number);

/**
* \brief The function searches a next parameter in the string.
*
* The function searches in the line the first parameter from the left and 
* sets the buffer pointer to the next symbol in the line.
* 
* \param[in] paramName Parameter symbol (a, b, x, ...), met before in the line. '\0' if the function is called for the first time.
* \param[in] buffer Input string.
* 
* \return Pointer to the parameter type (x^2, x or free member), `nullptr` in case of an error.
*/
ParamType* ParseNextParam(const char** buffer, char* paramName);

/**
* \brief Function for processing the end of a line.
*
* The function processes characters after the '=' sign. Issues a warning if the input does not end with "=0".
* 
* \param[in] buffer Input string.
* 
* \return false in case of an error, true in case of correct exit.
*/
bool ParseEnding(const char** buffer);

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
double ConvertToDouble(const char* start, const char* end);

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
void ParamWarning(const ParamType paramType, const double oldNumber, const double newNumber);

/**
* \brief Function that determines wheter a character is a separator.
* 
* \param[in] c The checked character.
* 
* \return true, if the character is a dot or comma.
*/
bool IsSeparator(const char c);

/**
* \brief Function that compare numbers
* 
* The function uses `Epsilon` to determine equal numbers.
* 
* \param[in] a,b The compared numbers.
* 
* \return true, is numbers are equal.
*/
bool CompareNumbers(const double a, const double b);

/**
* \brief Function that determines wheter the character is '+' or '-'.
* 
* \param[in] c The checked character.
* 
* \return true, if the character is '+' or '-'.
*/
bool IsSign(const char c);

#endif // !PARSE_H_
