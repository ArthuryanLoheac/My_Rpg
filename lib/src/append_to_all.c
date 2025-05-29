/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Append the given string to every strings into the given array
*/

#include <stddef.h>
#include <stdlib.h>
#include "../include/lib.h"

char **append_to_array(char **src, char *to_append)
{
    char *temp;

    if (to_append == NULL) {
        to_append = malloc(sizeof(char) * 1);
        to_append[0] = '\0';
    }
    for (int i = 0; src[i] != NULL; i++) {
        temp = src[i];
        src[i] = malloc(my_strlen(src[i]) + my_strlen(to_append) + 1);
        src[i][0] = '\0';
        my_strcat(src[i], temp);
        free(temp);
        my_strcat(src[i], to_append);
    }
    return src;
}

char **append_to_array2(char *to_append, char **src)
{
    char *temp;

    if (to_append == NULL) {
        to_append = malloc(sizeof(char) * 1);
        to_append[0] = '\0';
    }
    for (int i = 0; src[i] != NULL; i++) {
        temp = src[i];
        src[i] = malloc(my_strlen(src[i]) + my_strlen(to_append) + 1);
        src[i][0] = '\0';
        my_strcat(src[i], to_append);
        my_strcat(src[i], temp);
        free(temp);
    }
    return src;
}
