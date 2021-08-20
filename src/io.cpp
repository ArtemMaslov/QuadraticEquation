#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <cmath>

#include "..\inc\io.h"
#include "..\inc\solve.h"

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


void PrintSolution(Coefficients* params)
{
    if (params->a == NAN && params->b == NAN && params->c == NAN)
        printf(NO_SLN);
    else if (params->c == 1.0)
        printf(ONE_SLN(params->a));
    else if (params->c == 2.0)
        printf(TWO_SLN(params->a, params->b));
    else
        printf(INF_SLN);
}