#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>
#include <math.h>
#include <assert.h>

struct complex_num
    {
        double real;
        double image;
    };

int     sum_complex_num         (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp); // sum complex numbers

int     sub_complex_num         (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp); // subtraction complex numbers

int     mult_comp_num           (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp); // multiplication complex numbers

int     div_comp_num            (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp); // dividing complex numbers

int     sq_root_comp_num        (struct complex_num comp, struct complex_num * comp1, struct complex_num * comp2); // the square root of a complex number

int     compr_complex_num_zero  (struct complex_num comp); // comparsion complex number with zero

#endif