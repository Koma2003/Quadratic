#include "quadratic.h"

int main()
{
    double a = 0, b = 0, c = 0, eps = 0;

    double x1 = 0, x2 = 0;

    int flag = DEFAULT;

    if (read(&a, &b, &c, &eps) < 0) // Один или более из коэффициентов или погрешность не являются числом
    {
        printf ("No nummbers\n");

        return -1;
    }

    flag = solve(a, b, c, eps, &x1, &x2);

    write(x1, x2, flag); // Вывод ответа

    return 0;
}