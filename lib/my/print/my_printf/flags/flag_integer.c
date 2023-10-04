/*
** EPITECH PROJECT, 2022
** flag_integer
** File description:
** print integer
*/

#include <stdarg.h>
#include "../../my_printf.h"

int flag_integer(va_list ap, int precis)
{
    int number = 0;
    int length = 0;

    number = va_arg(ap, int);
    my_putnbr(number);
    length = count(number);
    return (length);
}
