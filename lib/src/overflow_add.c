/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Find out if the result of a multiplication is higher than an int
*/

int overflow_add(int nb, int add)
{
    int bnb = nb;

    bnb = bnb + add;
    bnb = bnb - add;
    return (bnb != nb);
}
