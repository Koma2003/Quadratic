#include "quadratic.h"

int main()
{
    int type_of_solution = DEFAULT;

    struct complex_num coef_a, coef_b, coef_c, comp_x1, comp_x2;
   
    if (read_coef(&coef_a, &coef_b, &coef_c) < 0) // one or more of the coefficients are not numbers
    {
        printf ("Incorrect response\n");

        return -1;
    }

    type_of_solution = solveEq(coef_a, coef_b, coef_c, &comp_x1, &comp_x2);

    write_ans (type_of_solution, comp_x1, comp_x2); // response output

    return 0;
}