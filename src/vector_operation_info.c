/*
** EPITECH PROJECT, 2024
** set_animate_image
** File description:
** set_animate_image
*/

#include "my.h"

float get_distance(sfVector2f pos1, sfVector2f pos2)
{
    float val1 = pos1.x - pos2.x;
    float val2 = pos1.y - pos2.y;

    return sqrtf(pow(val1, 2) + pow(val2, 2));
}

float get_len(sfVector2f pos)
{
    return sqrtf(pow(pos.x, 2) + pow(pos.y, 2));
}
