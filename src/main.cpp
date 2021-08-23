#include <Windows.h>

#include "..\inc\config.h"
#include "..\inc\equation_client.h"

#ifdef UNIT_TESTS

#include "..\inc\test.h"

#endif // UNIT_TESTS

int main(void)
{

    #ifdef UNIT_TESTS
    
    TestSolveTask();

    #else

    EquationClient();

    #endif // UNIT_TESTS
    return 0;
}
