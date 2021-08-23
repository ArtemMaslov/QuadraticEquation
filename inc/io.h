/**
* \file
* \brief Input, output functions file
* \author Maslov Artem
* \version 1.0.0.0
* \date 20 August 2021
*/
#ifndef IO_H_
#define IO_H_

#include "config.h"

/**
* \brief Input reading function.
*
* The function reads the following line from the input buffer.
* 
* \warning If input line bigger than buffer length, function will ignore input line ending.
* 
* \param[in]  length Maximum line length (buffer size).
* \param[in]  stream Input stream.
* 
* \param[out] buffer Input line.
* 
* \return nullptr in case of error, else pointer to readed string
*/
char* GetString(char* buffer, const int length, FILE* stream);


/**
* \brief The function outputs the roots of the equation.
*
* \param[in] params Coefficients of the quadratic equation.
*/
void PrintSolution(const Solution* params);

/**
* \brief Set color for text and background in console
*
* Full list of colors avaliable in config.h
*
* \param[in] text Text color
* \param[in] background Background color
*/
void SetColor(const int text, const int background);

#endif // !IO_H_
