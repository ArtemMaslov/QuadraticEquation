/**
* \file
* \brief ������������ ���� � ��������� �������� ������
* 
* ������ ���� �������� �������� ��������, ������������, ������������ ����������
*/

#ifndef MAIN_H_
#define MAIN_H_

/// \brief ������ ������ �����
const int MaxLength = 1000;

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

#endif // !PARSE_H_
