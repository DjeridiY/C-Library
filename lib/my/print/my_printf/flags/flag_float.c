/*
** EPITECH PROJECT, 2022
** float
** File description:
** float
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../my_printf.h"

int calculs_float(double f, long long int nd, int precis)
{
    double fi = f - f;
    int cpy = 0;

    nd = f;
    if (f < 0) {
        f = -f;
        my_putchar('-');
    }
    my_putnbr(nd);
    my_putchar('.');
    for (int o = 0; o < precis; o++)
        fi = fi * 10;
    cpy = fi;
    cpy = cpy % 10;
    if (cpy >= 5)
        fi = fi + 10;
    fi = fi / 10;
    my_putnbr(fi);
    return count(fi) + count(nd) + 1;
}

int flag_float(va_list ap, int precis)
{
    double f = va_arg(ap, double);
    long long int nd = f;
    int length;

    precis++;
    length = calculs_float(f, nd, precis);
    return (length);
}
