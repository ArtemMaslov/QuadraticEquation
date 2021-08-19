/**
* \file
* \brief Заголовочный файл с описанием структур данных
* 
* Данный файл содержит описание структур, перечислений, используемых программой
*/

#ifndef MAIN_H_
#define MAIN_H_

/// \brief Размер буфера ввода
const int MaxLength = 1000;

/**
* \brief Коэффициенты квадратного уравнения ax^2+bx+c.
*/
typedef struct coefficients
{
    double a, b, c;
} Coefficients;

/// \brief Флаги показывают встречался ли до этого в строке определённый коэффициент.
typedef struct parse_flags
{
    bool aInited : 1;
    bool bInited : 1;
    bool cInited : 1;
} ParseFlags;

/// \brief Тип параметра
typedef enum param_type
{
    X_0 = 0, ///< Свободный член
    X_1 = 1, ///< Переменная в  первой степени (x)
    X_2 = 2  ///< Переменная во второй степени (x^2)
} ParamType;

#endif // !PARSE_H_
