/**
* \file
* \brief Заголовочный файл ввода-вывода
*
* Данный файл содержит описание функций для работы с вводом-выводом
*/
#ifndef IO_H_
#define IO_H_

#include "main.h"

/**
* \brief Функция чтения строки
*
* Функция читает строку в buffer.
* \param[out] buffer Входная строка
* \param[in]  length Максимальная длина строки (размер буфера)
*/
char* GetString(char* buffer, int length);

#endif // !PARESE_H_
