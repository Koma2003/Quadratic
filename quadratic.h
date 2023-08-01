#ifndef QUADRATIC_H
#define QUADRATIC_H
#define NONE 0.0/0.0
#define PLUS_INF 1.0/0.0
#define MINUS_INf -1.0/0.0
#define EPS 0

#include "complex.h"

int     read_coef       (struct complex_num * coef_1, struct complex_num * coef_2, struct complex_num * coef_3); // reading input coefficients and rounding errors

int     solveEq         (struct complex_num coef_1, struct complex_num coef_2, struct complex_num coef_3, struct complex_num * compl_x1, struct complex_num * compl_x2); // solution of the equation

int     solveLinearEq   (struct complex_num coef_1, struct complex_num coef_2, struct complex_num * compl_x); // solution of a linear equation

int     solveQuadroEq   (struct complex_num coef_1, struct complex_num coef_2, struct complex_num coef_3, struct complex_num * compl_x1, struct complex_num * compl_x2); // quadratic equation solution

int     write_ans       (const int type_of_solution, struct complex_num compl_x1, struct complex_num compl_x2); // response output

int     compr_double    (const double a, const double b); // comparison

enum TYPE_OF_SOLUTION // types of solutions to equations
{
    DEFAULT = 0,
    LINEAR_ONE_ROOT,
    LINEAR_NO_ROOT,
    LINEAR_INF_ROOTS,
    QUADRO_ONE_ROOT,
    QUADRO_TWO_ROOTS,
    QUADRO_COMPLEX_ROOTS,
    LINEAR_COMPLEX_ONE_ROOT,
    QUADRO_COMPLEX_TWO_ROOTS
};

enum TYPE_OF_COMPR // types of comparison
{
    ERROR = -1,
    EQUAL,
    MORE,
    LESS
};

enum TYPE_OF_READ // coefficient reading results and errors
{
    BAD_READ = -1,
    OK_READ = 1
};

#endif
