/*
** EPITECH PROJECT, 2022
** flag_unsigned
** File description:
** print unsigned number
*/

#include <stdarg.h>
#include "../../my_printf.h"

int flag_unsigned(va_list ap, int precis)
{
    unsigned number = 0;
    int length = 0;

    number = va_arg(ap, unsigned);
    length = my_putnbr_unsigned(number);
    return (length);
}
