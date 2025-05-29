/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** a function to append a character to a string
*/

#include <stdlib.h>
#include "../include/my.h"

char *remove_str1(char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src)));

    my_strncpy(dest, src, my_strlen(src) - 1);
    dest[my_strlen(src) - 1] = '\0';
    return dest;
}

char *remove_stri(char *src, int index)
{
    int passed = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src)));

    for (int i = 0; i < my_strlen(src) - 1; i++) {
        if (i == index)
            passed++;
        dest[i] = src[i + passed];
    }
    dest[my_strlen(src) - 1] = '\0';
    free(src);
    return dest;
}

char *insert_stri(char *src, int index, char to_insert)
{
    int passed = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 2));

    for (int i = 0; i < my_strlen(src); i++) {
        if (i == index)
            passed++;
        dest[i + passed] = src[i];
    }
    dest[index] = to_insert;
    dest[my_strlen(src) + 1] = '\0';
    free(src);
    return dest;
}
