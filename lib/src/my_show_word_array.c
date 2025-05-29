/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** print all argument given in an array of strings
*/

#include "../include/lib.h"

int my_show_word_array(char *const *tab)
{
    int len = 0;

    while (tab[len] != 0) {
        len++;
    }
    my_putsterr(concat_params(len, tab));
    if (len != 0) {
    my_putsterr("\n");
    }
    return 0;
}
