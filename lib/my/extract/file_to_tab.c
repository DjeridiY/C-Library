/*
** EPITECH PROJECT, 2022
** c-library
** File description:
** file_to_tab.c
*/

#include "../my.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

static char **to_file(char *str, int const fd, struct stat *sb)
{
    int size = 0;
    char **tab = NULL;

    size = read(fd, str, (sb->st_size));
    if (size == -1)
        return NULL;
    str[size] = '\0';
    tab = my_str_to_word_array(str, '\n');
    free(str);
    return tab;
}

char **file_to_tab(char *file)
{
    struct stat sb;
    int fd = open(file, O_RDONLY);
    char *str = NULL;
    char **tab = NULL;

    if (fd == -1 || stat(file, &sb) == -1)
        return NULL;
    if (sb.st_size == 0)
        return NULL;
    str = malloc(sizeof(char) * (sb.st_size + 1));
    if (str == NULL)
        return NULL;
    tab = to_file(str, fd, &sb);
    if (close(fd) == -1 || tab == NULL)
        return NULL;
    return tab;
}
