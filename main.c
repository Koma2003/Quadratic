#include "quadratic.h"

int main()
{
    
    double eps = 0;
  
    int type_of_solution = DEFAULT;

    if (read_coef(&eps, &coef_a, &coef_b, &coef_c) < 0) // one or more of the coefficients are not numbers
    {
        printf ("Incorrect response\n");

        return -1;
    }

    type_of_solution = solveEq(eps, coef_a, coef_b, coef_c, &comp_x1, &comp_x2);

    write_ans (type_of_solution, comp_x1, comp_x2); // response output

    return 0;
}