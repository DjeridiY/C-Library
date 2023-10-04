/*
** EPITECH PROJECT, 2022
** flag decimal
** File description:
** print decimal number
*/

#include <stdarg.h>
#include "../../my_printf.h"

int flag_decimal(va_list ap, int precis)
{
    int number = 0;
    int length = 0;

    number = va_arg(ap, int);
    my_putnbr(number);
    length = count(number);
    return (length);
}
