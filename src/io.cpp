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


void PrintSolution(Solution* solution)
{
    assert(solution);

    SolutionType type = solution->type;

    if (type == NO_SOLUTIONS)
        printf(NO_SLN);
    else if (type == ONE_SOLUTION)
        printf(ONE_SLN(solution->x1));
    else if (type == TWO_SOLUTIONS)
        printf(TWO_SLN(solution->x1, solution->x2));
    else if (type == INF_SOLUTIONS)
        printf(INF_SLN);
}