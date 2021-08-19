#include <string.h>
#include <stdio.h>

#include "..\inc\io.h"

char* GetString(char* buffer, int length)
{
    char* result = nullptr;
    char* index  = nullptr;

    result = fgets(buffer, length, stdin);

    if (result)
    {
        if (strcmp(buffer, "\n") == 0)//Пустая строка, завершаем программу
            return nullptr;

        index = strchr(buffer, '\n');

        if (index)
            *index = '\0';
        else
        {
            printf("\nСтрока слишком длинная, часть строки будет отброшена. Удалось считать:\n%s\n\n", buffer);

            while (getchar() != '\n')
                continue;
        }
    }
    return result;
}