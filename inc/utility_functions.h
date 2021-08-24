/**
* \file
* \brief Utility functions file
* \author Maslov Artem
* \version 1.0.0.0
* \date 20 August 2021
*/
#ifndef UTILITY_FUNCTIONS_H_
#define UTILITY_FUNCTIONS_H_

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
* \brief Function determines wheter the number is zero.
*
* \params[in] number The number being checked
* 
* \return true if number is zero.
*/
double IsZero(const double number);

#endif // !UTILITY_FUNCTIONS_H_