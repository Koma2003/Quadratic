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

int     sum_complex_num (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp); // sum complex numbers

int     sub_complex_num (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp); // subtraction complex numbers

int     mult_comp_num   (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp); // multiplication complex numbers

int     divis_comp_num  (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp); // dividing complex numbers

int     Sq_root_comp_num (struct complex_num comp, struct complex_num * comp1, struct complex_num * comp2); // the square root of a complex number

#endif