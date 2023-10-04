/*
** EPITECH PROJECT, 2022
** expo
** File description:
** expo
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../my_printf.h"

char putexpo(int negoupos, int compt)
{
    my_putchar('e');
    if (negoupos == 1)
        my_putchar('+');
    if (negoupos == 2)
        my_putchar('-');
    if (compt < 10)
        my_putchar('0');
    my_putnbr(compt);
}

int printfloat(double exp, int precis)
{
    long long int nd = exp;
    double fi = exp - nd;
    int length;
    int cpy;

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
    length = count(fi) + count(nd) + 1;
    return (length);
}

int multioudivis(double exp, long long int nds, int precis)
{
    int length;
    int compt = 0;
    int negoupos;

    if (nds >= 10) {
        for (; exp >= 10; compt++) {
            exp /= 10;
        }
        negoupos = 1;
    }
    if (nds <= 0) {
        for (; exp < 1; compt++) {
            exp *= 10;
        }
        negoupos = 2;
    }
    length = printfloat(exp, precis) + 4;
    putexpo(negoupos, compt);
    return (length);
}

int flag_expo_min(va_list ap, int precis)
{
    int deci = 1;
    double exp = va_arg(ap, double);
    long long int nds = 0;

    precis++;
    if (exp < 0) {
        exp = -exp;
        my_putchar('-');
    }
    nds = exp;
    return multioudivis(exp, nds, precis);
}
