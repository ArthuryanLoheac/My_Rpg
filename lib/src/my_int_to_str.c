/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Function that make a string our of an integer only for natural int
*/

#include <stdlib.h>
#include "../include/lib.h"

char *int_to_str(int i)
{
    char *str = malloc(sizeof(char) * my_nbrlen(i) + 1);
    int j = 0;

    while (i > 9) {
        str[j] = (i % 10) + 48;
        i /= 10;
        j++;
    }
    str[j] = (i % 10) + 48;
    str[j + 1] = '\0';
    str = my_revstr(str);
    return str;
}
