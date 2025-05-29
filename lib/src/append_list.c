/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** a function to append a character to a string
*/

#include <stdlib.h>
#include "lib.h"

char *append_str(char *src, char *src2)
{
    char *dest;

    if (src == NULL)
        return src2;
    if (src2 == NULL)
        return src;
    dest = malloc(sizeof(char) * (my_strlen(src) + my_strlen(src2) + 1));
    my_strcpy(dest, src);
    for (int i = 0; i < my_strlen(src2); i++)
        dest[my_strlen(src) + i] = src2[i];
    dest[my_strlen(src) + my_strlen(src2)] = '\0';
    return dest;
}

char *append_str2(char *src, char *src2)
{
    char *dest;

    if (src == NULL)
        return src2;
    if (src2 == NULL)
        return src;
    dest = malloc(sizeof(char) * (my_strlen(src) + my_strlen(src2) + 1));
    my_strcpy(dest, src);
    for (int i = 0; i < my_strlen(src2); i++)
        dest[my_strlen(src) + i] = src2[i];
    dest[my_strlen(src) + my_strlen(src2)] = '\0';
    free(src);
    free(src2);
    return dest;
}

char *append_str1(char *src, char ch)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 2));

    my_strcpy(dest, src);
    dest[my_strlen(src) + 1] = '\0';
    dest[my_strlen(src)] = ch;
    return dest;
}

char *append_str1f(char *src, char ch)
{
    char *dest = append_str1(src, ch);

    free(src);
    return dest;
}

char *append_1str(char ch, char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 2));

    my_strcpy(&dest[1], src);
    dest[my_strlen(src) + 1] = '\0';
    dest[0] = ch;
    return dest;
}
