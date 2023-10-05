/*
** EPITECH PROJECT, 2023
** C-Library
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../my.h"

int count_word(char *str, char const delim)
{
    int i = 0;
    int word = 1;

    for (; str[i] == delim; i++);
    for (; str[i] != '\0'; i++) {
        if (str[i + 1] == '\0')
            return word;
        if (str[i] == delim && str[i + 1] != delim)
            word++;
    }
    return word;
}

static char **fill_word_array(char *str, char const delim,
    char **tab, int const word)
{
    int j = 0;
    int c = 0;

    for (int i = 0; i < word; i++) {
        for (; str[c] == delim; c++);
        for (; str[c] != '\0' && str[c] != delim; j++) {
            tab[i][j] = str[c];
            c++;
        }
        tab[i][j] = '\0';
        j = 0;
    }
    return tab;
}

char **my_str_to_word_array(char *str, char const delim)
{
    int word = count_word(str, delim);
    char **tab = malloc(sizeof(char *) * (word + 1));

    if (tab == NULL)
        return NULL;
    for (int i = 0; i < word; i++) {
        tab[i] = malloc(sizeof(char) * my_strlen(str) + 1);
        if (tab[i] == NULL)
            return NULL;
    }
    tab = fill_word_array(str, delim, tab, word);
    tab[word] = NULL;
    return tab;
}
