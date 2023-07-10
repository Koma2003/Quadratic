#ifndef QUADRATIC_H
#define QUADRATIC_H

#include <stdio.h>
#include <math.h>

int     read            (double * a, double * b, double * c);

int     solve           (const double a, const double b, const double c, double * x1, double * x2);

int     solveLinearEq   (const double a, const double b, double * x_ptr);//solve eq ax+b=0

int     solveQuadroEq   (const double a, const double b, const double c, double * x1, double * x2);

int     write           (const double x1, const double x2, const int flag);

int     compr_double    (const double a, const double b, const double eps);

enum TYPE_OF_SOLUTION
{
    DEFAULT = 0,
    LINEAR_ONE_ROOT,
    LINEAR_NO_ROOT,
    LINEAR_INF_ROOTS,
    QUADRO_ONE_ROOT,
    QUADRO_TWO_ROOTS,
    QUADRO_NO_ROOTS

};

enum TYPE_OF_COMPR
{
    EQUAL,
    MORE,
    LESS
};

enum TYPE_OF_READ
{
    BAD_READ = -1,
    OK_READ = 1
};

#endif
