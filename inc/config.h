/**
* \file
* \brief Configuration file
* \author Maslov Artem
* \version 1.0.0.0
* \date 20 August 2021
*/
#ifndef CONFIG_H_
#define CONFIG_H_

// Uncomment to enable unit tests.
//#define UNIT_TESTS

/// \brief Size of input buffer.
const int MaxLength = 1000;

/// \brief Maximum degree of a polynomial
const unsigned int MaxCoefficientsCount = 3;

/** \brief The constant for comparing double numbers. 
* 
* If the difference between two double numbers is less than `MinCompareValue`, then they are assumed to be equal.
* The number, which is less than `MinCompareValue`, is assumed to be equal zero.
*/
const double MinCompareValue = 1e-6;

#endif // !CONFIG_H_
