/*
** EPITECH PROJECT, 2023
** C-Library
** File description:
** my_printf.h
*/

#include <stdarg.h>

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

int count(int d);
int my_putnbr(long long int nbr);
void my_putchar(char c);
void flag_n(const char *format, int i, va_list ap);
int my_putnbr_unsigned(int nb);
int my_putnbr_base8_modif(int nbr);
int my_putstr(char const str);
int my_putnbr_base8(int nbr);
int my_putnbr_base_hexa_min(int nbr);
int my_putnbr_base_hexa_maj(int nbr);
int my_putnbr_binary(int nbr);

#endif /* MY_PRINTF_H_ */
