#ifndef QUADRATIC_EQ_H
#define QUADRATIC_EQ_H

int     solve_eq                    (const struct complex_num coef_1, const struct complex_num coef_2, const struct complex_num coef_3, struct complex_num * compl_x1, struct complex_num * compl_x2); // solution of the equation

int     solve_linear_eq             (const struct complex_num coef_1, const struct complex_num coef_2, struct complex_num * compl_x); // solution of a linear equation

int     solve_quadro_eq             (const struct complex_num coef_1, const struct complex_num coef_2, const struct complex_num coef_3, struct complex_num * compl_x1, struct complex_num * compl_x2); // quadratic equation solution

int     solve_linear_eq_one_sol     (const struct complex_num coef_1, const struct complex_num coef_2, struct complex_num * compl_x); // linear equation with one solution

int     solve_quadro_eq_real_coef   (const double coef_1, const double coef_2, const double coef_3, struct complex_num * compl_x1, struct complex_num * compl_x2); // solution of a quadro equation with real coefficients

int     solve_quadro_eq_compl_coef  (const struct complex_num coef_1, const struct complex_num coef_2, const struct complex_num coef_3, struct complex_num * compl_x1, struct complex_num * compl_x2); // solution of quadratic equation with complex coefficients

#endif  

