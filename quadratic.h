#ifndef QUADRATIC_H
#define QUADRATIC_H
#define NONE 0.0/0.0
#define PLUS_INF 1.0/0.0
#define MINUS_INf -1.0/0.0

#include <stdio.h>
#include <math.h>
#include <assert.h>

 struct complex_num
    {
        double real;
        double image;
    };
    
    struct complex_num comp_x1, comp_x2, coef_a, coef_b, coef_c, comp1, comp2, comp;

int     read_coef       (double * eps, struct complex_num * coef_a, struct complex_num * coef_b, struct complex_num * coef_c); // reading input coefficients and rounding errors

int     solveEq         (const double eps, struct complex_num coef_a, struct complex_num coef_b, struct complex_num coef_c, struct complex_num * comp_x1, struct complex_num * comp_x2); // solution of the equation

int     solveLinearEq   (const double eps, struct complex_num coef_a, struct complex_num coef_b, struct complex_num * comp_x); // solution of a linear equation

int     solveQuadroEq   (const double eps, struct complex_num coef_a, struct complex_num coef_b, struct complex_num coef_c, struct complex_num * comp_x1, struct complex_num * comp_x2); // quadratic equation solution

int     write_ans       (const int type_of_solution, struct complex_num comp_x1, struct complex_num comp_x2); // response output

int     compr_double    (const double a, const double b, const double eps); // comparison

int     sum_complex_num (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp); // sum complex numbers

int     sub_complex_num (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp); // subtraction complex numbers

int     mult_comp_num   (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp); // multiplication complex numbers

int     divis_comp_num  (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp); // dividing complex numbers

int     Sq_root_comp_num (struct complex_num comp, struct complex_num * comp1, struct complex_num * comp2); // the square root of a complex number

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
