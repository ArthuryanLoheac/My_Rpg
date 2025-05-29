/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Function that displays the number given as a parameter
*/

#include <unistd.h>
#include "../include/lib.h"

int my_put_nbr(int nb)
{
    int a;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * - 1;
    }
    if (nb >= 0) {
        a = nb % 10;
        if (nb >= 10) {
            nb = nb / 10;
            my_put_nbr(nb);
            my_putchar(48 + a);
        } else {
            my_putchar(48 + a);
        }
    } else {
        write(1, "2147483648", 10);
    }
    return nb;
}
