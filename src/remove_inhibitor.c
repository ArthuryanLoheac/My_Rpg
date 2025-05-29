/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** the my_str_to_word_array file is like my_str_to_word_array but better
*/

#include "../include/my.h"

char *remove_inhibitor_line(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == 34) {
            str = remove_stri(str, i);
            break;
        }
    }
    for (int i = my_strlen(str) - 1; i >= 0; i--) {
        if (str[i] == 34) {
            str = remove_stri(str, i);
            break;
        }
    }
    return str;
}

char **remove_inhibitor(char **dest)
{
    for (int x = 0; x < my_pointlen(dest); x++) {
        dest[x] = remove_inhibitor_line(dest[x]);
    }
    return dest;
}
