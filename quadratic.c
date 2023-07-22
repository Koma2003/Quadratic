#include "quadratic.h"

int read_coef (double * eps_ptr, struct complex_num * coef_a, struct complex_num * coef_b, struct complex_num * coef_c) // reading input coefficients and rounding errors
{
    printf ("Enter comparison error:\n"); // input of comparison error

    int z = scanf("%lf", eps_ptr);
    
    if (z != 1)
    {
        return BAD_READ;
    }

    else
    printf ("Write the real part of the first coefficient\n");
    int n1 = scanf ("%lf", &coef_a->real);
    printf ("Write the imaganary part of the first coefficient (if the coefficient is real, specify the imaginary part is 0)\n");
    int n2 = scanf ("%lf", &coef_a->image);

    printf ("Write the real part of the second coefficient\n");
    int n3 = scanf ("%lf", &coef_b->real);
    printf ("Write the imaganary part of the second coefficient (if the coefficient is real, specify the imaginary part is 0)\n");
    int n4 = scanf ("%lf", &coef_b->image);

    printf ("Write the real part of the third coefficient\n");
    int n5 = scanf ("%lf", &coef_c->real);
    printf ("Write the imaganary part of the third coefficient (if the coefficient is real, specify the imaginary part is 0)\n");
    int n6 = scanf ("%lf", &coef_c->image);

    if ((n1 != 1) || (n2 != 1) || (n3 != 1) || (n4 != 1) || (n5 != 1) || (n6 != 1))
    {
        return BAD_READ;
    }
    else
    {
        return OK_READ;
    }
}

int write_ans (const int type_of_solution, struct complex_num comp_x1, struct complex_num comp_x2) // response output
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
        printf ("The root of the linear equation: %.5lf.\n", comp_x1.real);
        break;
    }

    case QUADRO_TWO_ROOTS:

    {
         printf ("The roots of the quadro equation: %.5lf, %.5lf.\n", comp_x1.real, comp_x2.real);
         break;
    }

    case QUADRO_ONE_ROOT:

    {
        printf ("The root of the quadro equation: %.5lf.\n", comp_x1.real);
        break;
    }

    case QUADRO_COMPLEX_ROOTS:

    {
        printf ("The roots of the quadro equation %.5lf+%.5lfi, %.5lf-%.5lfi.\n", comp_x1.real, comp_x1.image, comp_x1.real, comp_x1.image);
        break;
    }

    case LINEAR_COMPLEX_ONE_ROOT:

    {
        printf ("The roots of the linear equation %.5lf+(%.5lfi).\n", comp_x1.real, comp_x1.image);
        break;
    }
    case QUADRO_COMPLEX_TWO_ROOTS:

    {
        printf ("The roots of the quadro equation %.5lf+(%.5lf)i, %.5lf-(%.5lf)i.\n", comp_x1.real, comp_x1.image, comp_x2.real, comp_x2.image);
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
