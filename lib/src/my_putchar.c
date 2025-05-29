/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** Display one character on the terminal
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
