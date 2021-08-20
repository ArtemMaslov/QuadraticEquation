#ifndef TEST_H_
#define TEST_H_

const int TestMaxLength = 100;

/**
* \brief Тестирование SolveTask().
* 
* Набор тестов для функции SolveTask().
* 
* Использование:
* \code
* int main(void)
* {
*     SetConsoleCP(1251);
*     SetConsoleOutputCP(1251);
* 
*     TestSolveTask();
*     return 0;
* }
* \endcode
*/
void TestSolveTask();


/**
* \brief Функция проверяет совпадают ли корни
*
* \param[in] r1, r2 Корни уравнения
* \return Возвращает true, если корни равны.
*/
bool CompareRoots(Coefficients r1, Coefficients r2);

/// \brief Устанавливает зелёный цвет в консоли
void SetGreenColor();

/// \brief Устанавливает красный цвет в консоли
void SetRedColor();

/// \brief Устанавливает белый цвет в консоли
void ResetColor();

#endif // !TEST_H_

