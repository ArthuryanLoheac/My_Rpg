/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** return the given sub-string if it appear in the
** string, else return NULL
*/

#include "../include/lib.h"

char *my_strstr(char *str, char const *to_find)
{
    int x = 0;
    int targetx = my_strlen(to_find);
    int i = 0;
    int len = my_strlen(str);

    while (i <= len){
        if (x == targetx) {
            return (&str[i]);
        }
        if (str[i + x] == to_find[x]) {
                x++;
        } else {
            x = 0;
            i ++;
        }
    }
    return (0);
}
