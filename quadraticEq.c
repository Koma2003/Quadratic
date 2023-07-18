#include "quadratic.h"

int solveEq (const double a, const double b, const double c, double eps, double * x1_ptr, double * x2_ptr, struct complex_num * comp_x_ptr)
{
    if (compr_double (a, 0, eps) == EQUAL)
    {
        return solveLinearEq(b, c, eps, x1_ptr); // linear equation
    }
    else 
    {
        return solveQuadroEq(a, b, c, eps, x1_ptr, x2_ptr, comp_x_ptr); // quadratic equation
    }
}

int solveLinearEq (const double a, const double b, double eps, double * x_ptr) // solutions of a linear equation ax+b=0
{
    if (compr_double (a, 0, eps) == MORE || compr_double (a, 0, eps) == LESS) // linear equation has one solution
    {
        *x_ptr = -b/a;

        return LINEAR_ONE_ROOT;
    }
    else
    {
        if (compr_double (b, 0, eps) == MORE || compr_double (b, 0, eps) == LESS) // linear equation has no solutions
        {
            return LINEAR_NO_ROOT;
        }
        else // a linear equation has an infinite number of solutions
        {
            return LINEAR_INF_ROOTS;
        }    
    }
}

int solveQuadroEq (const double a, const double b, const double c, double eps, double * x1, double * x2, struct complex_num * comp_x) // solution of a quadratic equation ax^2+bx+c=0
{
    double d;
    d = (b*b)-4*a*c; // discriminant count

if (compr_double (d, 0, eps) == LESS) // quadratic equation has no roots
    {   
        comp_x->real = (-b/(2*a));
        comp_x->image = (sqrt(-d)/(2*a));
        
        return QUADRO_COMPLEX_ROOTS;
    }
        else if (compr_double (d, 0, eps) == EQUAL) // quadratic equation has one root
    {
        *x1 = -b/(2*a); 

        return QUADRO_ONE_ROOT;
    }
else // quadratic equation has two roots
    {
        *x1 = (-b + sqrt(d))/(2*a);
        *x2 = (-b -sqrt(d))/(2*a);

        return QUADRO_TWO_ROOTS;
    }

}