/**
* \file
* \brief Configuration file
*/
#ifndef CONFIG_H_
#define CONFIG_H_

// Uncomment to enable unit tests.
//#define UNIT_TESTS


/// \brief Size of input buffer.
const int MaxLength = 1000;

/** \brief The constant for comparing double numbers. 
* 
* If the difference between two double numbers is less than `MinCompareValue`, then they are assumed to be equal.
* The number, which is less than `MinCompareValue`, is assumed to be equal zero.
*/
const double MinCompareValue = 1e-6;

/// Black color for console
#define BLACK       0
/// DARK_BLUE color for console
#define DARK_BLUE   1
/// DARK_GREEN color for console
#define DARK_GREEN  2
/// DARK_CYAN color for console
#define DARK_CYAN   3
/// DARK_RED color for console
#define DARK_RED    4
/// DARK_VIOLET color for console
#define DARK_VIOLET 5
/// DARK_YELLOW color for console
#define DARK_YELLOW 6
/// DARK_WHITE color for console
#define DARK_WHITE  7
/// GREY color for console
#define GREY        8
/// BLUE color for console
#define BLUE        9
/// GREEN color for console
#define GREEN       10
/// CYAN color for console
#define CYAN        11
/// RED color for console
#define RED         12
/// VIOLET color for console
#define VIOLET      13
/// YELLOW color for console
#define YELLOW      14
/// WHITE color for console
#define WHITE       15


/// \brief Coefficients of the quadratic equation ax^2+bx+c.
struct Coefficients
{
    double a; ///< Coefficient at x^2
    double b; ///< Coefficient at x
    double c; ///< Coefficient without x
};

/// \brief The flags, which shows whether a certain coefficient has been encountered in the parsing line before.
struct ParseFlags
{
    bool aInited : 1; ///< Coefficient at x^2 occured in the line
    bool bInited : 1; ///< Coefficient at x occured in the line
    bool cInited : 1; ///< Coefficient without x occured in the line
};

/// \brief Coefficient's type.
enum ParamType
{
    X_0 = 0, ///< Free term.
    X_1 = 1, ///< Variable in the first degree (x).
    X_2 = 2  ///< Variable in the second degree (x^2).
};

/// Solution type (no solutions, one solution, two solutions, an infinit number of solutions).
enum SolutionType
{
    NO_SOLUTIONS  = 0, ///< No solutions.
    ONE_SOLUTION  = 1, ///< One solution.
    TWO_SOLUTIONS = 2, ///< Two solutions.
    INF_SOLUTIONS = -1 ///< An infinit number of solutions.
};

/// Solution structure
struct Solution
{
    double x1;         ///< The biggest root
    double x2;         ///< The smallest root
    SolutionType type; ///< Solution type
};

#endif // !CONFIG_H_
