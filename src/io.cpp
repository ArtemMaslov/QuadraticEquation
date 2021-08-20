#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "..\inc\io.h"

char* GetString(char* buffer, int length, FILE* stream)
{
    assert(buffer);
    assert(stream);

    char* result = nullptr;
    char* index  = nullptr;

    result = fgets(buffer, length, stream);

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