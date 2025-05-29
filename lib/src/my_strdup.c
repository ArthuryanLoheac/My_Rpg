/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Allocate memory to copy a string in a new place
*/

#include <stdlib.h>
#include "../include/lib.h"

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    return (my_strcpy(dest, src));
}
