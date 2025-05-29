/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

unsigned int roll_dice_6(int n)
{
    int result = 0;

    for (int i = 0; i < n; i++)
        result += (rand() % 6) + 1;
    return result;
}

unsigned int roll_dice_10(int n)
{
    int result = 0;

    for (int i = 0; i < n; i++)
        result += (rand() % 10) + 1;
    return result;
}
