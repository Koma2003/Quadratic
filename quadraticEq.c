#include "quadratic.h"

int solveEq (const double eps, struct complex_num coef_a, struct complex_num coef_b, struct complex_num coef_c, struct complex_num * comp_x1_ptr, struct complex_num * comp_x2_ptr) // solution of equation
{
    if ((compr_double(coef_a.real, 0, eps) == EQUAL) && (compr_double (coef_a.image, 0, eps) == EQUAL))
    {
        return solveLinearEq (eps, coef_b, coef_c, comp_x1_ptr); // linear equation
    }
    else 
    {
        return solveQuadroEq(eps, coef_a, coef_b, coef_c, comp_x1_ptr, comp_x2_ptr); // quadratic equation
    }
}

int solveLinearEq (const double eps, struct complex_num coef_b, struct complex_num coef_c, struct complex_num * comp_x_ptr) // solutions of a linear equation bx+c=0
{
    {
        if (((compr_double (coef_b.real, 0, eps) == MORE) || compr_double (coef_b.real, 0, eps) == LESS) || ((compr_double (coef_b.image, 0, eps) == MORE) || compr_double (coef_b.image, 0, eps) == LESS)) // linear equation has one solution
        {
            divis_comp_num (coef_c, coef_b, comp_x_ptr);
            
            comp_x_ptr->real = -(comp_x_ptr->real);
            comp_x_ptr->image = -(comp_x_ptr->image);
            
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
            if ((compr_double (coef_c.real, 0, eps) != EQUAL) || (compr_double (coef_c.image, 0, eps) != EQUAL)) // linear equation has no solutions
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

int solveQuadroEq (double eps, struct complex_num coef_a, struct complex_num coef_b, struct complex_num coef_c, struct complex_num * comp_x1_ptr, struct complex_num * comp_x2_ptr) // solution of a quadratic equation ax^2+bx+c=0
{
    if ((coef_a.image == 0) && (coef_b.image == 0) && (coef_c.image == 0))
    {
            double d;
            d = (coef_b.real*coef_b.real)-4*coef_a.real*coef_c.real; // discriminant count

        if (compr_double (d, 0, eps) == LESS) // quadratic equation has complex roots
            {   
                comp_x1_ptr->real = (-coef_b.real/(2*coef_a.real));
                comp_x1_ptr->image = (sqrt(-d)/(2*coef_a.real));
        
                return QUADRO_COMPLEX_ROOTS;
            }
                else if (compr_double (d, 0, eps) == EQUAL) // quadratic equation has one root
            { 
                comp_x1_ptr->real = (-coef_b.real)/(2*coef_a.real);
                comp_x1_ptr->image = 0;
                
                return QUADRO_ONE_ROOT;
            }
        else // quadratic equation has two roots
            {   
                comp_x1_ptr->real = ((-coef_b.real + sqrt(d))/(2*coef_a.real));
                comp_x1_ptr->image = 0;
                comp_x2_ptr->real = ((-coef_b.real - sqrt(d))/(2*coef_a.real));
                comp_x2_ptr->image = 0;

                return QUADRO_TWO_ROOTS;
            }
    }
        else
        {   
            struct complex_num comp_d, comp_eq_d1, comp_eq_d2, sum1, sum2;
            
            comp_d.real = (coef_b.real*coef_b.real - coef_b.image*coef_b.image - 4*coef_a.real*coef_c.real + 4*coef_a.image*coef_c.image);
            comp_d.image = (2*coef_b.real*coef_b.image - 4*coef_a.real*coef_c.image - 4*coef_c.real*coef_a.image);

            Sq_root_comp_num (comp_d, &comp_eq_d1, &comp_eq_d2);

            sub_complex_num (comp_eq_d1, coef_b, &sum1);
            sub_complex_num (comp_eq_d2, coef_b, &sum2);

            divis_comp_num (sum1, coef_a, comp_x1_ptr);
            divis_comp_num (sum2, coef_a, comp_x2_ptr);

            comp_x1_ptr->real = ((comp_x1_ptr->real)/2);
            comp_x1_ptr->image = ((comp_x1_ptr->image)/2);

            comp_x2_ptr->real = ((comp_x2_ptr->real)/2);
            comp_x2_ptr->image = ((comp_x2_ptr->image)/2);

            return QUADRO_COMPLEX_TWO_ROOTS;
        }
}