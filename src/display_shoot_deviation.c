/*
** EPITECH PROJECT, 2024
** display shoot
** File description:
** display_shoot
*/

#include "my.h"

float compute_no_hit(void)
{
    if (rand() % 2 == 1)
        return randf(5, 15);
    else
        return randf(-15, -5);
}

float compute_no_hit2(void)
{
    if (rand() % 2 == 1)
        return randf(5, 75);
    else
        return randf(-75, -5);
}

sfVector2f bullet_pos(sfFloatRect tas)
{
    return (sfVector2f){tas.left + randf(-3, 3), tas.top + randf(-3, 3)};
}
