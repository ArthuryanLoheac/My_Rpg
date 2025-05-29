/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** get the size of an integer akin to strlen
*/

int my_nbrlen(int nb)
{
    int i = 0;

    for (i = 0; nb >= 10; i++)
        nb = nb / 10;
    return i + 1;
}
