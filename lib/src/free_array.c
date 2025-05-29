/*
** EPITECH PROJECT, 2023
** concat params
** File description:
** concatenate all parameter given in main into a single string
*/

#include <stdlib.h>
#include "my.h"

void free_array(char **array)
{
    int len = my_pointlen(array);

    for (int i = 0; i < len; i++) {
        free(array[i]);
    }
    free(array);
}
