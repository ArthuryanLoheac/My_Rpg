/*
** EPITECH PROJECT, 2024
** set_animate_image
** File description:
** set_animate_image
*/

#include "my.h"

sfVector2f add3(sfVector2f pos, float val)
{
    return ((sfVector2f){pos.x + val, pos.y + val});
}

sfVector2f mult3(sfVector2f pos, float val)
{
    return ((sfVector2f){pos.x * val, pos.y * val});
}

sfVector2f div3(sfVector2f pos, float val)
{
    return ((sfVector2f){pos.x / val, pos.y / val});
}
