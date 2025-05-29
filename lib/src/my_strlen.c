/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Dipslay a string char-by-char
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i;

    if (str == NULL)
        return 0;
    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
