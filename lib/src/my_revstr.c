/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Reverse a reversed string two-by-two
*/

#include <stdlib.h>
#include "../include/lib.h"

void my_swap2(char *a, char *b)
{
    char temp = *a;

    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    int size = my_strlen(str);
    int i = 0;

    size--;
    while (i <= (size / 2)){
        my_swap2(&str[i], &str[size - i]);
        i++;
    }
    return (str);
}
