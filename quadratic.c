#include "quadratic.h"

int read (double * a_ptr, double * b_ptr, double * c_ptr)
{
    printf("Enter a, b, c:\n");

    int y = scanf("%lf%lf%lf", a_ptr, b_ptr, c_ptr);

    if (y != 3)
    {
    return BAD_READ;//что-то пошло не так
    }
    else
    {
    return OK_READ;//ok
    }
}

int solve (const double a, const double b, const double c, double * x1_ptr, double * x2_ptr)
{
    if (compr_double (a, 0, 10e-10) == EQUAL)
    {
        return solveLinearEq(b, c, x1_ptr);
    }
    else
    {
        return solveQuadroEq(a, b, c, x1_ptr, x2_ptr);
    }
}

int solveLinearEq(const double a, const double b, double * x_ptr)//solve ax+b=0
{
    if (compr_double (a, 0, 10e-10) == MORE || compr_double (a, 0, 10e-10) == LESS)
    {
        *x_ptr = -b/a;

        return LINEAR_ONE_ROOT;
    }
    else
    {
        if (compr_double (b, 0, 10e-10) == MORE || compr_double (b, 0, 10e-10) == LESS)
        {
            return LINEAR_NO_ROOT;
        }
        else
        {
            return LINEAR_INF_ROOTS;
        }    
    }
}

int solveQuadroEq(const double a, const double b, const double c, double * x1, double * x2)
{
    double d;
    d = (b*b)-4*a*c;

    if (compr_double (d, 0, 10e-10) == LESS)
    {
        return QUADRO_NO_ROOTS;
    }
        else if (compr_double (d, 0, 10e-10) == EQUAL)
    {
        *x1 = -b/(2*a);

        return QUADRO_ONE_ROOT;
    }
    else
    {
        *x1 = (-b + sqrt(d))/(2*a);
        *x2 = (-b -sqrt(d))/(2*a);

        return QUADRO_TWO_ROOTS;
    }

}

int write(const double x1, const double x2, const int flag)
{
    
    switch (flag)
  
{
   
    case LINEAR_INF_ROOTS:
    
    {
        printf("The linear equation has an infinite number of solutions.\n");

        break;
    }

    case LINEAR_NO_ROOT:

    {
        printf ("The linear equation has no roots.\n");

        break;
    }

    case LINEAR_ONE_ROOT:

    {
        printf ("The root of the linear equation: %.5lf.\n", x1);

        break;
    }

    case QUADRO_TWO_ROOTS:

    {
         printf ("The roots of the quadro equation: %.5lf, %.5lf.\n", x1, x2);

         break;
    }

    case QUADRO_ONE_ROOT:

    {
        printf ("The root of the quadro equation: %.5lf.\n", x1);

        break;
    }

    case QUADRO_NO_ROOTS:

    {
        printf ("The quadro equation has no roots.\n");

        break;
    }
   
    default:
      
      {
        printf ("Error");

        break;
        
      }
 
}
    return 0;
}
    
int compr_double (const double a, const double b, const double eps)
{
    if (fabs(a-b) <= eps)
    
    {
        return EQUAL;
    }
    
    else if ((a-b) > eps)
    
    {
        return MORE;
    }
    
    else
    
    {
        return LESS;
    }
}
