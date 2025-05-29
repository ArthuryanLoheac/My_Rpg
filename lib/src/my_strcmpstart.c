/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** give the first index to which you will find the target string in source str
*/

#include "../include/lib.h"

int my_strcmpstart(char *src, char *target)
{
    int cmp;

    for (int i = 0; i + my_strlen(target) <= my_strlen(src); i++) {
        cmp = 0;
        while (src[i + cmp] == target[cmp])
            cmp++;
        if (cmp >= my_strlen(target))
            return i;
    }
    return -1;
}
