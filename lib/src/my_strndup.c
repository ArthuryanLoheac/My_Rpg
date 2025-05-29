/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Allocate memory to copy a string in a new place
*/

#include <stdlib.h>
#include "my.h"

char *my_strndup(char const *src, int n)
{
    char *dest;

    if (n > my_strlen(src))
        n = my_strlen(src);
    dest = malloc(sizeof(char) * (n + 1));
    return (my_strncpy(dest, src, n));
}
