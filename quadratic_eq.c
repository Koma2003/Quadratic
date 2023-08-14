#include "quadratic.h"

int solve_eq (const struct complex_num coef_1, const struct complex_num coef_2, const struct complex_num coef_3, struct complex_num * comp_x1_ptr, struct complex_num * comp_x2_ptr) // solution of equation
{
    if (compr_complex_num_zero(coef_1) == ZERO)
    {
        return solve_linear_eq (coef_2, coef_3, comp_x1_ptr); // linear equation
    }
    else 
    {
        return solve_quadro_eq (coef_1, coef_2, coef_3, comp_x1_ptr, comp_x2_ptr); // quadratic equation
    }
}

int solve_linear_eq (const struct complex_num coef_2, const struct complex_num coef_3, struct complex_num * comp_x_ptr) // solutions of a linear equation bx+c=0
{
    {
        if (compr_complex_num_zero(coef_2) == NOT_ZERO) // linear equation has one solution
        {
            solve_linear_eq_one_sol (coef_2, coef_3, comp_x_ptr);
            
            if (comp_x_ptr->image == 0)
            {
                return LINEAR_ONE_ROOT;
            }
            else
            {
                return LINEAR_COMPLEX_ONE_ROOT;
            }
        }
        
        else
        {
            if (compr_complex_num_zero(coef_3) == NOT_ZERO) // linear equation has no solutions
            {
                return LINEAR_NO_ROOT;
            }
            else // a linear equation has an infinite number of solutions
            {
                return LINEAR_INF_ROOTS;
            }    
        }
    }
}

int solve_quadro_eq (const struct complex_num coef_1, const struct complex_num coef_2, const struct complex_num coef_3, struct complex_num * comp_x1_ptr, struct complex_num * comp_x2_ptr) // solution of a quadratic equation ax^2+bx+c=0
{
    if ((coef_1.image == 0) && (coef_2.image == 0) && (coef_3.image == 0))
    {
        return solve_quadro_eq_real_coef (coef_1.real, coef_2.real, coef_3.real, comp_x1_ptr, comp_x2_ptr);
    }
    else
    {   
        return solve_quadro_eq_compl_coef (coef_1, coef_2, coef_3, comp_x1_ptr, comp_x2_ptr);
    }
}

int solve_linear_eq_one_sol (const struct complex_num coef_1, const struct complex_num coef_2, struct complex_num * compl_x_ptr)
{
    div_comp_num (coef_2, coef_1, compl_x_ptr);
            
    compl_x_ptr->real = -(compl_x_ptr->real);
    compl_x_ptr->image = -(compl_x_ptr->image);

    return 0;
}

int solve_quadro_eq_real_coef (const double coef_1, const double coef_2, const double coef_3, struct complex_num * compl_x1_ptr, struct complex_num * compl_x2_ptr)
{
     double D;
            D = (coef_2*coef_2)-4*coef_1*coef_3; // discriminant count

        if (compr_double (D, 0) == LESS) // quadratic equation has complex roots
            {   
                compl_x1_ptr->real = (-coef_2/(2*coef_1));
                compl_x1_ptr->image = (sqrt(-D)/(2*coef_1));
        
                return QUADRO_COMPLEX_ROOTS;
            }
                else if (compr_double (D, 0) == EQUAL) // quadratic equation has one root
            { 
                compl_x1_ptr->real = (-coef_2)/(2*coef_1);
                compl_x1_ptr->image = 0;
                
                return QUADRO_ONE_ROOT;
            }
        else // quadratic equation has two roots
            {   
                compl_x1_ptr->real = ((-coef_2 + sqrt(D))/(2*coef_1));
                compl_x1_ptr->image = 0;
                compl_x2_ptr->real = ((-coef_2 - sqrt(D))/(2*coef_1));
                compl_x2_ptr->image = 0;

                return QUADRO_TWO_ROOTS;
            }
}

int solve_quadro_eq_compl_coef (const struct complex_num coef_1, const struct complex_num coef_2, const struct complex_num coef_3, struct complex_num * comp_x1_ptr, struct complex_num * comp_x2_ptr) // solution of quadratic equation with complex coefficients
{
    struct complex_num comp_d, comp_eq_d1, comp_eq_d2, sum1, sum2;
            
            comp_d.real = (coef_2.real*coef_2.real - coef_2.image*coef_2.image - 4*coef_1.real*coef_3.real + 4*coef_1.image*coef_3.image);
            comp_d.image = (2*coef_2.real*coef_2.image - 4*coef_1.real*coef_3.image - 4*coef_3.real*coef_1.image);

            sq_root_comp_num (comp_d, &comp_eq_d1, &comp_eq_d2);

            sub_complex_num (comp_eq_d1, coef_2, &sum1);
            sub_complex_num (comp_eq_d2, coef_2, &sum2);

            div_comp_num (sum1, coef_1, comp_x1_ptr);
            div_comp_num (sum2, coef_1, comp_x2_ptr);

            comp_x1_ptr->real = ((comp_x1_ptr->real)/2);
            comp_x1_ptr->image = ((comp_x1_ptr->image)/2);

            comp_x2_ptr->real = ((comp_x2_ptr->real)/2);
            comp_x2_ptr->image = ((comp_x2_ptr->image)/2);

            return QUADRO_COMPLEX_TWO_ROOTS;
}