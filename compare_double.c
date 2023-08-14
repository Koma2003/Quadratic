#include "quadratic.h"

int compr_double (const double a, const double b) // comparison
{   
    assert(isfinite(a));
    
    if (fabs(a-b) <= 1e-5)
    {
        return EQUAL;
    }
    else if ((a-b) > 1e-5)
    {
        return MORE;
    }
    else
    {
        return LESS;
    }  
}