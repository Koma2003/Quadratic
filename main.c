#include "quadratic.h"

int main()
{
    double a = 0, b = 0, c = 0;

    double x1 = 0, x2 = 0;

    int flag = DEFAULT;

    if (read(&a, &b, &c) < 0)
    {
        printf ("no nummbers\n");

        return -1;
    }

    flag = solve(a, b, c, &x1, &x2);

    write(x1, x2, flag);

    return 0;
}