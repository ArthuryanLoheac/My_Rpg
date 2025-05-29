/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Find out if the result of a multiplication is higher than an int
*/

int overflow_mult(int nb, int mult)
{
    int bnb = nb;

    bnb = bnb * mult;
    bnb = bnb / mult;
    return (bnb != nb);
}
