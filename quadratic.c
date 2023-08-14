#include "quadratic.h"

int read_coef (struct complex_num * coef_1, struct complex_num * coef_2, struct complex_num * coef_3) // reading input coefficients and rounding errors
{
    printf ("Write 1) The real part of the first coefficient;\n");
    printf ("2) The imaganary part of the first coefficient (if the coefficient is real, specify the imaginary part is 0)\n");
    printf ("3) The real part of the second coefficient\n");
    printf ("4) The imaganary part of the second coefficient (if the coefficient is real, specify the imaginary part is 0)\n");
    printf ("5) The real part of the third coefficient\n");
    printf ("6) The imaganary part of the third coefficient (if the coefficient is real, specify the imaginary part is 0)\n");
    int n = scanf ("%lf%lf%lf%lf%lf%lf", &coef_1->real, &coef_1->image, &coef_2->real, &coef_2->image, &coef_3->real, &coef_3->image);

    if (n != 6)
    {
        return BAD_READ;
    }
    else
    {
        return OK_READ;
    }
}

int write_ans (const int type_of_solution, struct complex_num compl_x1, struct complex_num compl_x2) // response output
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
        printf ("The root of the linear equation: %.5lf.\n", compl_x1.real);
        break;
    }
    case QUADRO_TWO_ROOTS:
    {
         printf ("The roots of the quadro equation: %.5lf, %.5lf.\n", compl_x1.real, compl_x2.real);
         break;
    }
    case QUADRO_ONE_ROOT:
    {
        printf ("The root of the quadro equation: %.5lf.\n", compl_x1.real);
        break;
    }
    case QUADRO_COMPLEX_ROOTS:
    {
        printf ("The roots of the quadro equation %.5lf+%.5lfi, %.5lf-%.5lfi.\n", compl_x1.real, compl_x1.image, compl_x1.real, compl_x1.image);
        break;
    }
    case LINEAR_COMPLEX_ONE_ROOT:
    {
        printf ("The roots of the linear equation %.5lf+(%.5lfi).\n", compl_x1.real, compl_x1.image);
        break;
    }
    case QUADRO_COMPLEX_TWO_ROOTS:
    {
        printf ("The roots of the quadro equation %.5lf+(%.5lf)i, %.5lf+(%.5lf)i.\n", compl_x1.real, compl_x1.image, compl_x2.real, compl_x2.image);
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