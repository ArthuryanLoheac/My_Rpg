/*
** EPITECH PROJECT, 2024
** open file
** File description:
** open_file
*/

#include "../include/lib.h"

char *open_file(char *file)
{
    int fd = -1;
    struct stat stats;
    char *result = NULL;

    if (!file)
        return NULL;
    fd = open(file, O_RDONLY, 00644);
    if (fd == -1 || stat(file, &stats) == -1)
        return NULL;
    result = malloc(sizeof(char) * (stats.st_size + 1));
    if (result == NULL)
        return NULL;
    if (read(fd, result, stats.st_size) == -1)
        return NULL;
    result[stats.st_size] = '\0';
    free(file);
    file = NULL;
    close(fd);
    return result;
}

char *read_fd(int fd, char *file)
{
    struct stat stats;
    char *result = NULL;

    if (fd == -1)
        return NULL;
    if (stat(file, &stats) == -1)
        return NULL;
    result = malloc(sizeof(char) * (stats.st_size + 1));
    if (result == NULL)
        return NULL;
    if (read(fd, result, stats.st_size) == -1)
        return NULL;
    result[stats.st_size] = '\0';
    return result;
}
