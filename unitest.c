#include "quadratic.h"

int unitest()
{
struct coef
{
   const double a;
   const double b;
   const double c;
};
struct root
{
    double x1;
     double x2;
};

struct root first_r, second_r, third_r, fourth_r, fifth_r, sixth_r, seventh_r;

struct coef first = { 1, 2, 1 };
struct coef second = { 0, 1, 2 };
struct coef third = { 0, 0, 1};
struct coef fourth = { 0, 0, 0};
struct coef fifth = { 1, 3, -4 };
struct coef sixth = { 1, -7, 10 };
struct coef seventh = { 1, 4, 5 };


solveEq (first.a, first.b, first.c, 0, &first_r.x1, &first_r.x2, &comp_x);
if (first_r.x1 == -1)
    printf ("Test 1 was successful: The quadro equation x^2+2x+1=0 has one root, x=-1\n");
else 
    printf ("Test 1 failed\n");

solveEq (second.a, second.b, second.c, 0, &second_r.x1, &second_r.x2, &comp_x);
if (second_r.x1 == (-2))
    printf ("Test 2 was successful: The linear equation x+2=0 has one root, x=-2\n");
else
    printf ("Test 2 failed\n");

if (LINEAR_NO_ROOT == solveEq (third.a, third.b, third.c, 0, &third_r.x1, &third_r.x2, &comp_x))
    printf ("Test 3 was successful: 1=0, The identity is not true\n");
else
    printf ("Test 3 failed\n");

if (LINEAR_INF_ROOTS == solveEq (fourth.a, fourth.b, fourth.c, 0, &fourth_r.x1, &fourth_r.x2, &comp_x))
    printf ("Test 4 was successful: x=0, The linear equation has an infinite set of roots\n");
else
    printf ("Test 4 failed\n");

solveEq (fifth.a, fifth.b, fifth.c, 0, &fifth_r.x1, &fifth_r.x2, &comp_x);
if ((fifth_r.x1 == 1 && fifth_r.x2 == (-4)) || (fifth_r.x1 == (-4) && fifth_r.x2 == 1))
    printf ("Test 5 was successful: The quadro equation x^2+3x-4=0 has two roots, x1=1, x2=-4\n");
else
    printf ("Test 5 failed\n");

solveEq (sixth.a, sixth.b, sixth.c, 0, &sixth_r.x1, &sixth_r.x2, &comp_x);
if ((sixth_r.x1 == 5 && sixth_r.x2 == 2) || (sixth_r.x1 == 2 && sixth_r.x2 == 5))
    printf ("Test 6 was successful: The quadro equation x^2-7x+10=0 has two roots, x1=2, x2=5\n");
else
    printf ("Test 6 failed\n");

solveEq (seventh.a, seventh.b, seventh.c, 0, &seventh_r.x1, &seventh_r.x2, &comp_x);
if (comp_x.real == (-2) && comp_x.image == 1)
    printf ("Test 7 was successful: The quadro equation x^2+4x+5=0 has two complex roots, x1=-2-i, x2=-2+i\n");
else 
("Test 7 failed\n");

return 0;
}
