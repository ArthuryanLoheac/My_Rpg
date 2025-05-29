/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Concatenate two strings
*/

#include "../include/lib.h"
#include <stdlib.h>

static void add_extention(char *src, char *result, int nbr)
{
    for (int i = 0; src[i]; i++)
        result[nbr + i] = src[i];
}

char *my_strcat_assets(char *start)
{
    int i = 0;
    int len = my_strlen(start) + my_strlen("_icon");
    char *result = malloc(sizeof(char *) * (len + 1));

    result[len] = '\0';
    for (; start[i] != '\0'; i++)
        result[i] = start[i];
    add_extention("_icon", result, i);
    return (result);
}

char *my_strcat_data(char *start)
{
    int i = 0;
    int len = my_strlen(start) + my_strlen("_data");
    char *result = malloc(sizeof(char *) * (len + 1));

    result[len] = '\0';
    for (; start[i] != '\0'; i++)
        result[i] = start[i];
    add_extention("_data", result, i);
    return (result);
}
