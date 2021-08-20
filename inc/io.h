#ifndef IO_H_
#define IO_H_

#include "main.h"

/**
* \brief Функция чтения строки
*
* Функция читает строку в buffer.
* \param[out] buffer Входная строка
* \param[in]  length Максимальная длина строки (размер буфера)
* \param[in]  stream Поток, откуда функция читает данные
*/
char* GetString(char* buffer, int length, FILE* stream);

#endif // !PARESE_H_
