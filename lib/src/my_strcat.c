/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Concatenate two strings
*/

#include "../include/lib.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int len = my_strlen(dest);

    i = 0;
    dest[len] = src[0];
    while (src[i] != '\0') {
        i++;
        dest[i + len] = src[i];
    }
    return (dest);
}
