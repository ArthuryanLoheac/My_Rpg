/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** is_same_color
*/

#include "my.h"

bool is_same_color(sfColor a, sfColor b)
{
    if (a.a == b.a && a.b == b.b &&
        a.g == b.g && a.r == b.r)
        return true;
    return false;
}
