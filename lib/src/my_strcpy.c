/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Copy a string char-by-char
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i;

    i = 0;
    dest[0] = src[0];
    while (src[i] != '\0') {
        i++;
        dest[i] = src[i];
    }
    return (dest);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
