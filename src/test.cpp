#include <Windows.h>
#include <stdio.h>

#include "..\inc\solve.h"
#include "..\inc\io.h"
#include "..\inc\test.h"

void TestSolveTask()
{
    Coefficients arr[] = 
    {
        {0.0, 0.0, 0.0},
        {0.0, 0.0, 1.0},

        {0.0, 1.0, 0.0},
        {0.0, 1.0, 1.0},

        {1.0, 0.0, 0.0},
        {1.0, 0.0, 1.0},

        {1.0, 1.0, 0.0},
        {1.0, 1.0, -2.0},
    };
    

    const size_t testsCount = sizeof(arr) / sizeof(Coefficients);
    Coefficients answer[testsCount] =
    {
        {0.0,  0.0, INF_SOLUTIONS},
        {0.0,  0.0, NO_SOLUTIONS},

        {0.0,  0.0, ONE_SOLUTION},
        {-1.0, 0.0, ONE_SOLUTION},

        {0.0,  0.0, ONE_SOLUTION},
        {0.0,  0.0, NO_SOLUTIONS},

        {0.0, -1.0, TWO_SOLUTIONS},
        {1.0, -2.0, TWO_SOLUTIONS},
    };

    for (size_t st = 0; st < testsCount; st++)
    {
        Coefficients roots = SolveTask(arr+st);

        if (CompareRoots(roots, answer[st]) == false)
        {
            SetRedColor();
            printf("\nТест №%d провален.\n"
                "Правильный ответ a = %lg, b = %lg, c = %lg.\n"
                "Программа выдала a = %lg, b = %lg, c = %lg.\n",
                st + 1, 
                answer[st].a, answer[st].b, answer[st].c,
                arr[st].a,    arr[st].b,    arr[st].c);
        }
        else
        {
            SetGreenColor();
            printf("Тест №%d пройден.\n", st + 1);
        }
    }
    ResetColor();
}

bool CompareRoots(Coefficients r1, Coefficients r2)
{
    return (r1.c == r2.c && (r1.a == r2.a && r1.b == r2.b || r1.a == r2.b && r1.b == r2.a));
}

void SetGreenColor()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void SetRedColor()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void ResetColor()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}