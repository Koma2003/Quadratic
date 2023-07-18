#include "quadratic.h"

int read_coef (double * a_ptr, double * b_ptr, double * c_ptr, double * eps_ptr)
{
    printf("Enter coefficients of the equation a, b, c:\n"); // entering equation coefficients

    int y = scanf("%lf%lf%lf", a_ptr, b_ptr, c_ptr);

    printf("Enter comparison error:\n"); // input of comparison error

    int z = scanf("%lf", eps_ptr);

    if ((y != 3) || (z != 1)) // checking that the error and coefficients are numbers
    {
        return BAD_READ; // something went wrong
    }
    else
    {
        return OK_READ; // ok
    }
}

int write_ans (const double x1, const double x2, const int type_of_solution, struct complex_num comp_x) // response output
{
    switch (type_of_solution)
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

    case QUADRO_COMPLEX_ROOTS:

    {
        printf ("The roots of the quadro equation %.5lf+%.5lfi, %.5lf-%.5lfi.\n", comp_x.real, comp_x.image, comp_x.real, comp_x.image);
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
    
int compr_double (const double a, const double b, const double eps) // comparison
{   
    assert(a != NONE && a != PLUS_INF && a != MINUS_INf);
    
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
