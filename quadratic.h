#ifndef QUADRATIC_H
#define QUADRATIC_H

#include <stdio.h>
#include <math.h>

int     read            (double * a_ptr, double * b_ptr, double * c_ptr, double * eps_ptr); // Чтение вводимых коэффициентов и погрешности округления

int     solve           (const double a, const double b, const double c, const double eps, double * x1_ptr, double * x2_ptr); // Решение уравнения

int     solveLinearEq   (const double a, const double b, const double eps, double * x_ptr); // Решение линейного уравнения

int     solveQuadroEq   (const double a, const double b, const double c, const double eps, double * x1_ptr, double * x2_ptr); // Решение квадратного уравнения

int     write           (const double x1, const double x2, const int flag); //Вывод ответа

int     compr_double    (const double a, const double b, const double eps); // Сравнение 

enum TYPE_OF_SOLUTION // Виды решений уравнения
{
    DEFAULT = 0,
    LINEAR_ONE_ROOT,
    LINEAR_NO_ROOT,
    LINEAR_INF_ROOTS,
    QUADRO_ONE_ROOT,
    QUADRO_TWO_ROOTS,
    QUADRO_NO_ROOTS

};

enum TYPE_OF_COMPR // Виды сравнения
{
    EQUAL,
    MORE,
    LESS
};

enum TYPE_OF_READ // Результаты считывания коэффициентов и погрешности
{
    BAD_READ = -1,
    OK_READ = 1
};

#endif
