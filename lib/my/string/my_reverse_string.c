/*
** EPITECH PROJECT, 2023
** Day04AM
** File description:
** reverse_string.c
*/

#include "../my.h"
#include <stdlib.h>

char *my_reverse_string(char *str)
{
    char *new_str = my_strdup(str);
    int length = my_strlen(new_str);
    int start = 0;
    int end = length - 1;
    char temp = 0;

    while (start < end) {
        temp = new_str[start];
        new_str[start] = new_str[end];
        new_str[end] = temp;
        start++;
        end--;
    }
    return new_str;
}
