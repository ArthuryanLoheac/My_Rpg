/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Dipslay a string char by char
*/

#include <unistd.h>
#include "../include/lib.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 1;
}

int my_putsterr(char const *str)
{
    write(2, str, my_strlen(str));
    return 1;
}
