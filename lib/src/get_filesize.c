/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Get the size of a file using stat
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my.h"

int get_filesize(char const *filepath)
{
    struct stat s;

    stat(filepath, &s);
    if (s.st_size == 0) {
        fprintf(stderr, "Error opening file %s\n", filepath);
        exit(84);
    }
    return (int)s.st_size;
}
