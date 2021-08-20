/*!
    \author ������ ����
    \version 1.0.0.0
    \date 20 ������� 2021

    ���������, �������� ���������� ��������� � ���������� ����.
*/

#ifndef MAIN_H_
#define MAIN_H_


// �����������������, ���� ����� �������� ����� �������.
#define UNIT_TESTS


/// \brief ������ ������ �����
const int MaxLength = 1000;

/// \brief ��������� ��� ��������� ����� double. ���� �������� ���� ����� double ������ epsilon, �� ��� ����������� �������.
const double epsilon = 1e-6;

/**
* \brief ������������ ����������� ��������� ax^2+bx+c.
*/
typedef struct coefficients
{
    double a, b, c;
} Coefficients;

/// \brief ����� ���������� ���������� �� �� ����� � ������ ����������� �����������.
typedef struct parse_flags
{
    bool aInited : 1;
    bool bInited : 1;
    bool cInited : 1;
} ParseFlags;

/// \brief ��� ���������
typedef enum param_type
{
    X_0 = 0, ///< ��������� ����
    X_1 = 1, ///< ���������� �  ������ ������� (x)
    X_2 = 2  ///< ���������� �� ������ ������� (x^2)
} ParamType;

/// ��� ������ (������� ���, ���� ������, ��� �����, ���������� ����� ������).
typedef enum solutions
{
    NO_SOLUTIONS  = 0,///< ������� ���
    ONE_SOLUTION  = 1,///< ���� ������
    TWO_SOLUTIONS = 2,///< ��� �����
    INF_SOLUTIONS = -1///< ���������� ����� ������
} Solutions;

#endif // !PARSE_H_
