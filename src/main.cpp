#include <Windows.h>

#include "..\inc\equation_client.h"
//#include "..\inc\test.h"

int main(void)
{
    SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    EquationClient();
    //TestSolveTask();
    return 0;
}
