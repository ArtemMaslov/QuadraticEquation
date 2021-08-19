/**
* \file
* \brief ������������ ���� ������� �����
*
* ������ ���� �������� �������� �������, ������������ ���������� ��� ��������������� �������������� ������� ������.
* ��� ������� ���������� ���������� �������.
*/
#ifndef PARSE_H_
#define PARSE_H_


#include "main.h"

/**
* \brief ������� ������� �������� ������
*
* ������� ����������� ������ � ��������� ������������. ��������� ������ ���� �������� � ���� ax^2+bx+c=0.
* ������� ��������� '*' � ������� '/' � ������� ������ �� �����������. 
* ���� 2*x^2-1=0 �������� �� ����������, ����� ������ 2x^2-1=0.
* ������ �������� ����� ����������� ������ ���� ���, ����� � ����������� ����� ����������� ���������.
* � ������� 2x^2+x^2-1=0, 2x^2 ����� ����������������, ��������� ������� ����� -1; 1.
* 
* \param[in,out] params ��������� ��������� ������������� ����������� ���������.
* \param[in]     buffer ������� ������
* 
* \return ���������� ��������� �� ���������. nullptr � ������ ������.
*/
Coefficients* ParseString(const char* buffer, Coefficients* params);

/**
* \brief ������� ������ ����� � ������
*
* ������� ���� � ������ ������ ����� ����� � ������, � ������������� ��������� buffer �� ��������� �� ������ ������.
* 
* \param[out] number ��������� �� ��������� � ������ �����
* \param[in]  buffer ������� ������
* 
* \return false � ������ ������, true � ������ ��������� ����������
*/
bool ParseNextNumber(const char** buffer, double* number);

/**
* \brief ������� ������ ��������� � ������
*
* ������� ����� ������ ����� �������� � ������, � ������������� ��������� buffer �� ��������� �� ���������� ������.
* 
* \param[in] paramName ������ ��������� (a, b, x, ...), ������������� �� ����� � ������. '\0' ���� ������� ���������� �������.
* \param[in] buffer ������� ������
* 
* \return ��������� �� ��� ��������� (x^2, x ��� ��������� ����)
*/
ParamType* ParseNextParam(const char** buffer, char* paramName);

/**
* \brief ������� ��������� ��������� ������
*
* ������� ������������ ������� ����� ����� '='. ����� ��������������, ���� ���� �� ������������ �� "= 0".
* 
* \param[in] buffer  ������� ������
*/
bool ParseEnding(const char** buffer);

/**
* \brief ������� �������� ������ ���� � double
*
* ������� ��������� ������ ���� � double.
* 
* \param[in] start ��������� �� ������ ������ �����
* \param[in] end ��������� �� �������� ������ �����
* 
* \return ���������� ���������� �����
*/
double ConvertToDouble(const char* start, const char* end);

/**
* \brief ������� ������� �������������� � ������� ������������� ����������
*
* ������� ������� ��������������, ��� ������� ��� ���������. �������� 2x+10x-1=0. ������� �������, ��� �������� 2x ����� ����������������.
* 
* \param[in] paramType ��� ��������� (x^2, x, ��������� ����)
* \param[in] oldNumber ������ �������� ���������
* \param[in] newNumber ����� �������� ���������
*/
void ParamWarning(ParamType paramType, double oldNumber, double newNumber);

/**
* \brief �������, ������������ �������� �� ������ ������ ��� �������
* 
* \param[in] c ����������� ������
* 
* \return true, ���� ������ ����� ��� �������
*/
bool IsSeparator(char c);

/**
* \brief �������, ������������ ��� �����
* 
* \param[in] a,b ������������ �����
* 
* \return true, ���� ����� �����
*/
bool CompareNumbers(double a, double b);

/**
* \brief �������, ������������ �������� �� ������ '+' ��� '-'
* 
* \param[in] c ����������� ������
* 
* \return true, ���� ������ '+' ��� '-'
*/
bool IsSign(char c);

#endif // !PARESE_H_
