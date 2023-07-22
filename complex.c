#include "quadratic.h"

int     sum_complex_num (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp) // sum of complex numbers
{
    comp->real = comp1.real + comp2.real;
    comp->image = comp1.image + comp2.image;

    return 0;
}

int     sub_complex_num (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp) // subtraction of complex numbers
{
    comp->real = comp1.real - comp2.real;
    comp->image = comp1.image - comp2.image;

    return 0;
}

int     mult_comp_num   (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp_ptr) // multiplication of complex numbers
{
    comp_ptr->real = (comp1.real*comp2.real - comp1.image*comp2.image);
    comp_ptr->image = (comp1.real*comp2.image + comp1.image*comp2.real);
    
    return 0;
}

int divis_comp_num (struct complex_num comp1, struct complex_num comp2, struct  complex_num * comp_ptr) // division of complex numbers
{
    comp_ptr->real = ((comp1.real*comp2.real + comp1.image*comp2.image)/(comp2.real*comp2.real + comp2.image*comp2.image));
    comp_ptr->image = (((-comp1.real*comp2.image) + comp1.image*comp2.real)/(comp2.real*comp2.real + comp2.image*comp2.image));
    
    return 0;
}

int     Sq_root_comp_num (struct complex_num comp, struct complex_num * comp1_ptr, struct complex_num * comp2_ptr) // multiplication of complex numbers
{
    comp1_ptr->real = (sqrt((sqrt(comp.real*comp.real + comp.image*comp.image) + comp.real)/2));
    comp1_ptr->image = ((fabs(comp.image))/(comp.image))*(sqrt((sqrt(comp.real*comp.real + comp.image*comp.image) - comp.real)/2));

    comp2_ptr->real = -(sqrt((sqrt(comp.real*comp.real + comp.image*comp.image) + comp.real)/2));
    comp2_ptr->image = -((fabs(comp.image))/(comp.image))*(sqrt((sqrt(comp.real*comp.real + comp.image*comp.image) - comp.real)/2));

    return 0;
}

