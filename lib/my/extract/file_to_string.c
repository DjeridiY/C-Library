/*
** EPITECH PROJECT, 2023
** C-Library
** File description:
** file_to_string.c
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

char *file_to_string(char const *file)
{
    int size = 0;
    struct stat sb;
    int nbr_of_char = 0;
    int fd = open(file, O_RDONLY);
    char *str = NULL;

    stat(file, &sb);
    nbr_of_char = sb.st_size;
    str = malloc(sizeof(char) * (nbr_of_char + 1));
    if (str == NULL)
        return NULL;
    *str = (char){0};
    size = read(fd, str, (nbr_of_char));
    str[size] = '\0';
    close(fd);
    return str;
}
