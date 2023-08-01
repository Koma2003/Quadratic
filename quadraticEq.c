#include "quadratic.h"

int solveEq (struct complex_num coef_1, struct complex_num coef_2, struct complex_num coef_3, struct complex_num * comp_x1_ptr, struct complex_num * comp_x2_ptr) // solution of equation
{
    if ((compr_double(coef_1.real, 0 == EQUAL) && (compr_double (coef_1.image, 0) == EQUAL)))
    {
        return solveLinearEq (coef_2, coef_3, comp_x1_ptr); // linear equation
    }
    else 
    {
        return solveQuadroEq (coef_1, coef_2, coef_3, comp_x1_ptr, comp_x2_ptr); // quadratic equation
    }
}

int solveLinearEq (struct complex_num coef_2, struct complex_num coef_3, struct complex_num * comp_x_ptr) // solutions of a linear equation bx+c=0
{
    {
        if (((compr_double (coef_2.real, 0) == MORE) || compr_double (coef_2.real, 0) == LESS) || ((compr_double (coef_2.image, 0) == MORE) || compr_double (coef_2.image, 0) == LESS)) // linear equation has one solution
        {
            divis_comp_num (coef_3, coef_2, comp_x_ptr);
            
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
            if ((compr_double (coef_3.real, 0) != EQUAL) || (compr_double (coef_3.image, 0) != EQUAL)) // linear equation has no solutions
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

int solveQuadroEq (struct complex_num coef_1, struct complex_num coef_2, struct complex_num coef_3, struct complex_num * comp_x1_ptr, struct complex_num * comp_x2_ptr) // solution of a quadratic equation ax^2+bx+c=0
{
    if ((coef_1.image == 0) && (coef_2.image == 0) && (coef_3.image == 0))
    {
            double d;
            d = (coef_2.real*coef_2.real)-4*coef_1.real*coef_3.real; // discriminant count

        if (compr_double (d, 0) == LESS) // quadratic equation has complex roots
            {   
                comp_x1_ptr->real = (-coef_2.real/(2*coef_1.real));
                comp_x1_ptr->image = (sqrt(-d)/(2*coef_1.real));
        
                return QUADRO_COMPLEX_ROOTS;
            }
                else if (compr_double (d, 0) == EQUAL) // quadratic equation has one root
            { 
                comp_x1_ptr->real = (-coef_2.real)/(2*coef_1.real);
                comp_x1_ptr->image = 0;
                
                return QUADRO_ONE_ROOT;
            }
        else // quadratic equation has two roots
            {   
                comp_x1_ptr->real = ((-coef_2.real + sqrt(d))/(2*coef_1.real));
                comp_x1_ptr->image = 0;
                comp_x2_ptr->real = ((-coef_2.real - sqrt(d))/(2*coef_1.real));
                comp_x2_ptr->image = 0;

                return QUADRO_TWO_ROOTS;
            }
    }
        else
        {   
            struct complex_num comp_d, comp_eq_d1, comp_eq_d2, sum1, sum2;
            
            comp_d.real = (coef_2.real*coef_2.real - coef_2.image*coef_2.image - 4*coef_1.real*coef_3.real + 4*coef_1.image*coef_3.image);
            comp_d.image = (2*coef_2.real*coef_2.image - 4*coef_1.real*coef_3.image - 4*coef_3.real*coef_1.image);

            Sq_root_comp_num (comp_d, &comp_eq_d1, &comp_eq_d2);

            sub_complex_num (comp_eq_d1, coef_2, &sum1);
            sub_complex_num (comp_eq_d2, coef_2, &sum2);

            divis_comp_num (sum1, coef_1, comp_x1_ptr);
            divis_comp_num (sum2, coef_1, comp_x2_ptr);

            comp_x1_ptr->real = ((comp_x1_ptr->real)/2);
            comp_x1_ptr->image = ((comp_x1_ptr->image)/2);

            comp_x2_ptr->real = ((comp_x2_ptr->real)/2);
            comp_x2_ptr->image = ((comp_x2_ptr->image)/2);

            return QUADRO_COMPLEX_TWO_ROOTS;
        }
}