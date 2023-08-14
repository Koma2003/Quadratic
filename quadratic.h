#ifndef QUADRATIC_H
#define QUADRATIC_H

#include "complex.h"
#include "quadratic_eq.h"
#include "compare_double.h"

int     read_coef       (struct complex_num * coef_1, struct complex_num * coef_2, struct complex_num * coef_3); // reading input coefficients and rounding errors

int     write_ans       (const int type_of_solution, const struct complex_num compl_x1, const struct complex_num compl_x2); // response output

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

enum COMPR_WITH_ZERO 
{
    ZERO,
    NOT_ZERO
};

#endif
