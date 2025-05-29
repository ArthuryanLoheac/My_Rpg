/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Get the first integer of a string and return it
*/
#include <limits.h>
#include "../include/lib.h"

int get_firstnb(char *str, int i, int nb, int *fintadd)
{
    if (str[i] >= '0' && str[i] <= '9' && *fintadd != 2){
        if (overflow_mult(nb, 10) == 1) {
            return 0;
        }
        nb = nb * 10;
        if (overflow_add(nb, (str[i] - '0')) == 1) {
            return 0;
        }
        nb = nb + str[i] - '0';
        *fintadd = 1;
    } else {
        if (*fintadd == 1) {
            *fintadd = *fintadd +1;
        }
    }
    return (nb);
}

int test_is_neg(char *str, int i)
{
    if (str[i] == '-') {
        return 1;
    }
    return 0;
}

int my_getnbr(char *str)
{
    int fintadd = 0;
    int prevchar = 0;
    int nb = 0;
    int i = 0;

    for (i = 0; (str[i] < '0' || str[i] > '9') && (str[i] != '\0'); i ++) {
        prevchar = prevchar + test_is_neg(str, i);
    }
    while (str[i] != '\0'){
        nb = get_firstnb(str, i, nb, &fintadd);
        i++;
    }
    if (prevchar % 2 == 0) {
        return (nb);
    } else {
        return (-(nb));
    }
}
