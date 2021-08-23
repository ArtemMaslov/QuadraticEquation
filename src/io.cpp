#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>
#include <cmath>

#include "..\inc\io.h"
#include "..\inc\solve.h"

char* GetString(char* buffer, const int length, FILE* stream)
{
    assert(buffer);
    assert(stream);

    char* result = nullptr;
    char* index  = nullptr;

    result = fgets(buffer, length, stream);

    if (result)
    {
        if (strcmp(buffer, "\n") == 0)//Empty string, programm must be closed
            return nullptr;

        index = strchr(buffer, '\n');

        if (index)
            *index = '\0';
        else
        {
            SetColor(RED, BLACK);
            puts("\nEntered string is too big, part of it will be ignored. Correctly readed:");
            printf("%s\n\n", buffer);
            SetColor(WHITE, BLACK);

            while (getchar() != '\n')
                continue;
        }
    }
    return result;
}


void PrintSolution(const Solution* solution)
{
    assert(solution);

    SetColor(GREEN, BLACK);
    switch (solution->type)
    {
    case NO_SOLUTIONS:
        printf(NO_SLN);
        break;
    case ONE_SOLUTION:
        printf(ONE_SLN(solution->x1));
        break;
    case TWO_SOLUTIONS:
        printf(TWO_SLN(solution->x1, solution->x2));
        break;
    case INF_SOLUTIONS:
        printf(INF_SLN);
        break;
    }
    SetColor(WHITE, BLACK);
}

void SetColor(const int text, const int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, ((background & 0xf) << 4) | (text & 0xf));
}