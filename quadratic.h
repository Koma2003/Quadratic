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
    
    struct complex_num comp_x;

int     read_coef       (double * a, double * b, double * c, double * eps); // reading input coefficients and rounding errors

int     solveEq         (const double a, const double b, const double c, const double eps, double * x1, double * x2, struct complex_num * comp_x); // solution of the equation

int     solveLinearEq   (const double a, const double b, const double eps, double * x); // solution of a linear equation

int     solveQuadroEq   (const double a, const double b, const double c, const double eps, double * x1, double * x2, struct complex_num * comp_x); // quadratic equation solution

int     write_ans       (const double x1, const double x2, const int type_of_solution, struct complex_num comp_x); // response output

int     compr_double    (const double a, const double b, const double eps); // comparison

enum TYPE_OF_SOLUTION // types of solutions to equations
{
    DEFAULT = 0,
    LINEAR_ONE_ROOT,
    LINEAR_NO_ROOT,
    LINEAR_INF_ROOTS,
    QUADRO_ONE_ROOT,
    QUADRO_TWO_ROOTS,
    QUADRO_COMPLEX_ROOTS

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
