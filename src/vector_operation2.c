/*
** EPITECH PROJECT, 2024
** set_animate_image
** File description:
** set_animate_image
*/

#include "my.h"

sfVector2f add2(sfVector2f pos, sfVector2f pos2)
{
    return ((sfVector2f){pos.x + pos2.x, pos.y + pos2.y});
}

sfVector2f sub2(sfVector2f pos, sfVector2f pos2)
{
    return ((sfVector2f){pos.x - pos2.x, pos.y - pos2.y});
}
