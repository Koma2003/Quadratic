#include "quadratic.h"

int main()
{
    double a = 0, b = 0, c = 0, eps = 0;

    double x1 = 0, x2 = 0;
     
    int type_of_solution = DEFAULT;

    if (read_coef(&a, &b, &c, &eps) < 0) // one or more of the coefficients are not numbers
    {
        printf ("No nummbers\n");

        return -1;
    }

    if (compr_double(a, b, eps) < 0)
    {
        printf ("Error\n");

        return -1;
    }

    type_of_solution = solveEq(a, b, c, eps, &x1, &x2, &comp_x);

    write_ans(x1, x2, type_of_solution, comp_x); // response output

    return 0;
}