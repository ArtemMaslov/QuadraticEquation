#include "..\inc\config.h"

#ifdef UNIT_TESTS

#include <Windows.h>
#include <stdio.h>

#include "..\inc\solve.h"
#include "..\inc\io.h"
#include "..\inc\test.h"

void TestSolveTask()
{
    for (size_t st = 0; st < TestsCount; st++)
    {
        Solution roots = SolveTask(SolveTaskInput + st);

        if (CompareRoots(roots, SolveTaskAnswers[st]) == false)
        {
            SetColor(RED, BLACK);
            printf("\nТест №%d провален.\n"
                "Правильный ответ x1 = %lg, x2 = %lg, type = %d.\n"
                "Программа выдала x1 = %lg, x2 = %lg, type = %d.\n",
                st + 1, 
                SolveTaskAnswers[st].x1, SolveTaskAnswers[st].x2, SolveTaskAnswers[st].type,
                roots.x1,                roots.x2,                roots.type);
        }
        else
        {
            SetColor(GREEN, BLACK);
            printf("Тест №%d пройден.\n", st + 1);
        }
    }
    SetColor(WHITE, BLACK);
}

bool CompareRoots(Solution r1, Solution r2)
{
    return (r1.type == r2.type && (r1.x1 == r2.x1 && r1.x2 == r2.x2 || r1.x1 == r2.x2 && r1.x2 == r2.x1));
}

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, ((background & 0xf)<<4) | (text & 0xf) );
}

#endif