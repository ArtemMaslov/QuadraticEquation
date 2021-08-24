#include "..\inc\config.h"

#ifdef UNIT_TESTS

#include <Windows.h>
#include <stdio.h>

#include "..\inc\equation_solver.h"
#include "..\inc\io.h"
#include "..\inc\test.h"

void TestSolveTask()
{
    for (int st = 0; st < TestsCount; st++)
    {
        Solution roots = {{0}, 0};
        SolveTask(SolveTaskInput + st, &roots);

        if (CompareRoots(roots, SolveTaskAnswers[st]) == false)
        {
            SetColor(RED, BLACK);
            printf("\nTest #%d failed.\n"
                "Correct answer x1 = %lg, x2 = %lg, type = %d.\n"
                "Program answered x1 = %lg, x2 = %lg, type = %d.\n",
                st + 1, 
                SolveTaskAnswers[st].solutions[0], SolveTaskAnswers[st].solutions[1], SolveTaskAnswers[st].SolutionsCount,
                roots.solutions[0],                roots.solutions[1],                roots.SolutionsCount);
        }
        else
        {
            SetColor(GREEN, BLACK);
            printf("Test #%d passed.\n", st + 1);
        }
    }
    SetColor(WHITE, BLACK);
}

bool CompareRoots(const Solution r1, const  Solution r2)
{
    bool res = true;
    if (r1.SolutionsCount == r2.SolutionsCount)
    {
        for (int st = 0; st < r1.SolutionsCount; st++)
            if (r1.solutions[st] != r2.solutions[st])
            {
                res = false;
                break;
            }
    }
    else
        res = false;
    return res;
}


#endif // UNIT_TESTS