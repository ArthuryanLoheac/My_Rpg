/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** concatenate all parameter given to it into a single string
*/

#include <stdlib.h>
#include "../include/lib.h"

char *concat_params(int argc, char *const *argv)
{
    int len = 0;
    char *dest;
    int y = 0;
    int z = 0;
    int i;

    for (i = 0; i < argc; i++)
        len = len + my_strlen(argv[i]);
    dest = malloc(sizeof(char) * (len + argc + 1));
    for (i = 0; i < (len + argc); i++) {
        for (z = 0; argv[y][z] != '\0'; z++){
            dest[i + z] = argv[y][z];
        }
        dest[i + z] = '\n';
        i = i + z;
        y++;
    }
    dest[len + argc - 1] = '\0';
    return (dest);
}
