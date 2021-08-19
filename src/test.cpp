#include <stdio.h>

#include "..\inc\solve.h"

void TestSolveTask()
{
    Coefficients arr[] = 
    {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0},
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 1},
    };

    //freopen("TestSolveTask.txt", "w+", stdout);
    for (size_t st = 0; st < sizeof(arr) / sizeof(Coefficients); st++)
    {
        SolveTask(arr+st);
    }
    fclose(stdout);

    //freopen("CON", "w", stdout);

}