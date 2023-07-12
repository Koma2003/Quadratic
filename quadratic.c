#include "quadratic.h"

int     read            (double * a_ptr, double * b_ptr, double * c_ptr, double * eps_ptr)
{
    printf("Enter coefficients of the equation a, b, c:\n"); // Ввод коэффициентов уравнения

    int y = scanf("%lf%lf%lf", a_ptr, b_ptr, c_ptr);

    printf("Enter comparison error:\n"); // Ввод погрешности сравнения

    int z = scanf("%lf", eps_ptr);

    if ((y != 3) || (z != 1)) // Проверка на то, что коэффициенты и погрешность являются числами
    {
    return BAD_READ; // Что-то пошло не так
    }
    else
    {
    return OK_READ; // Ок
    }
}

int     solve           (const double a, const double b, const double c, double eps, double * x1_ptr, double * x2_ptr)
{
    if (compr_double (a, 0, eps) == EQUAL)
    {
        return solveLinearEq(b, c, eps, x1_ptr); // Уравнение линейное
    }
    else
    {
        return solveQuadroEq(a, b, c, eps, x1_ptr, x2_ptr); // Уравнение квадратное
    }
}

int     solveLinearEq   (const double a, const double b, double eps, double * x_ptr) // Решение линейного уравнения ax+b=0
{
    if (compr_double (a, 0, eps) == MORE || compr_double (a, 0, eps) == LESS) // Линейное уравнение имеет одно решение
    {
        *x_ptr = -b/a;

        return LINEAR_ONE_ROOT;
    }
    else
    {
        if (compr_double (b, 0, eps) == MORE || compr_double (b, 0, eps) == LESS) // Линейное уравнение не имеет решений
        {
            return LINEAR_NO_ROOT;
        }
        else // Линейное уравнение имеет бесконечное множество решений
        {
            return LINEAR_INF_ROOTS;
        }    
    }
}

int     solveQuadroEq   (const double a, const double b, const double c, double eps, double * x1, double * x2) // Решение квадратного уравнения ax^2+bx+c=0
{
    double d;
    d = (b*b)-4*a*c; // Подсчёт дискриминанта

    if (compr_double (d, 0, eps) == LESS) // Квадратное уравнение не имеет корней
    {
        return QUADRO_NO_ROOTS;
    }
        else if (compr_double (d, 0, eps) == EQUAL) // Квадратное уравнение имеет один корень
    {
        *x1 = -b/(2*a); 

        return QUADRO_ONE_ROOT;
    }
    else // Квадратное уравнение имеет два корня
    {
        *x1 = (-b + sqrt(d))/(2*a);
        *x2 = (-b -sqrt(d))/(2*a);

        return QUADRO_TWO_ROOTS;
    }

}

int     write           (const double x1, const double x2, const int flag) // Вывод ответа
{
    
    switch (flag)
  
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

    case QUADRO_NO_ROOTS:

    {
        printf ("The quadro equation has no roots.\n");

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
    
int     compr_double    (const double a, const double b, const double eps) // Сравнение 
{
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
