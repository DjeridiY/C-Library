/*
** EPITECH PROJECT, 2023
** C-Library
** File description:
** my_strncpy.c
*/

int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return (i);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int lengh = my_strlen2(src);

    if (n > lengh) {
        while (i < lengh) {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    if (n < lengh) {
        while (i < n) {
            dest[i] = src[i];
            i++;
        }
    }
    dest[i] = '\0';
    return (dest);
}
