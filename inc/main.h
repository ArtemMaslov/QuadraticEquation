/*!
    \author Маслов Артём
    \version 1.0.0.0
    \date 20 Августа 2021

    Программа, решующая квадратные уравнения в приведённом виде.
*/

#ifndef MAIN_H_
#define MAIN_H_


// Раскомментировать, если нужно провести тесты функций.
#define UNIT_TESTS


/// \brief Размер буфера ввода
const int MaxLength = 1000;

/// \brief Константа для сравнения чисел double. Если разность двух чисел double меньше epsilon, то они принимаются равными.
const double epsilon = 1e-6;

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

/// Тип корней (решений нет, один корень, два корня, бесконечно много корней).
typedef enum solutions
{
    NO_SOLUTIONS  = 0,///< Решений нет
    ONE_SOLUTION  = 1,///< Один корень
    TWO_SOLUTIONS = 2,///< Два корня
    INF_SOLUTIONS = -1///< Бесконечно много корней
} Solutions;

#endif // !PARSE_H_
