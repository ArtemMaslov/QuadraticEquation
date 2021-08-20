#include <stdio.h>
#include <string.h>

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
    char answer[testsCount][TestMaxLength];

    // Для TWO_SLN корни нужно писать в порядке убывания

    sprintf(answer[0], INF_SLN);
    sprintf(answer[1], NO_SLN);

    sprintf(answer[2], ONE_SLN(0.0));
    sprintf(answer[3], ONE_SLN(-1.0));

    sprintf(answer[4], ONE_SLN(0.0));
    sprintf(answer[5], NO_SLN);

    sprintf(answer[6], TWO_SLN(0.0, -1.0));
    sprintf(answer[7], TWO_SLN(1.0, -2.0));

    for (int st = 0; st < testsCount; st++)
    {
        char* index = strchr(answer[st], '\n');
        if (index)
            *index = '\0';
    }

    FILE* testFileOut = freopen("D:\\TestSolveTask.txt", "w", stdout);
    if(testFileOut)
    {
        for (size_t st = 0; st < testsCount; st++)
        {
            SolveTask(arr+st);
        }
        fclose(testFileOut);

        FILE* stdoutStream = freopen("CON", "w", stdout);
        if (stdoutStream)
        {
            FILE* testFileIn = fopen("D:\\TestSolveTask.txt", "r");
            char buffer[TestMaxLength];

            for (size_t st = 0; st< testsCount; st++)
            {
                if (GetString(buffer, TestMaxLength, testFileIn))
                {
                    if (strcmp(buffer, answer[st]) != 0)
                    {
                        printf("\nТест №%d провален.\n"
                               "Правильный ответ %s.\n"
                               "Програама выдала %s.\n"
                               "Коэффициенты a = %lg, b = %lg, c = %lg.\n\n", st + 1, answer[st], buffer, arr[st].a, arr[st].b, arr[st].c);
                    }
                    else
                        printf("Тест №%d пройден.\n", st+1);
                }
                else
                    printf("Тест №%d провален. Ошибка чтения строки из файла. Коэффициенты a = %lg, b = %lg, c = %lg.\n", st+1, arr[st].a, arr[st].b, arr[st].c);

                GetString(buffer, TestMaxLength, testFileIn);//Чтение пустой строки
            }
            fclose(testFileIn);
        }
        else
            fputs("Ошибка перенаправления потока вывода обратно в консоль.\n", stderr);

        remove("D:\\TestSolveTask.txt");
    }
    else
        fputs("Ошибка перенаправления потока вывода в файл.\n", stderr);
}