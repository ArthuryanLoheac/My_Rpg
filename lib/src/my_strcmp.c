/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** compare two string 0 mean they are the same
*/
#include <stdlib.h>
#include <unistd.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;
    return s1[i] - s2[i];
}

int my_strcmp_array(char const *s1, char const **s2)
{
    for (int i = 0; s2[i] != NULL; i++) {
        if (my_strcmp(s1, s2[i]) == 0)
            return i;
    }
    return -1;
}
