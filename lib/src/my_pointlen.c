/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** get the size of an array akin to strlen
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_pointlen(char **str)
{
    int i;

    i = 0;
    while (str[i] != 0) {
        i++;
    }
    return (i);
}

int my_pointlen3(void **str)
{
    int i;

    i = 0;
    while (str[i] != 0) {
        i++;
    }
    return (i);
}
